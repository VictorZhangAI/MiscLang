class Sum(diw: Int, size: Int, stage: Int) extends Component{
    this.setDefinitionName(s"sum_stage${stage}_n${size}_w${diw}")
    val dow = diw + log2Up(size)

    val io = new Bundle{
      val nets = slave Flow(Vec(SInt(diw bits), size))
      val sum  = out(SInt(dow bits)).setAsReg()
    }

    when(io.nets.valid){
      io.sum := io.nets.payload
        .map(_.resize(dow bits))
        .reduce(_ + _)
    }
}

//showRtl(new Sum(8, 2, 0))
//showRtl(new Sum(8, 3, 0))

private def sumAdd(nets: Flow[Vec[SInt]], stage: Int): Sum = {
    val uSum = new Sum(nets.payload.head.getWidth, nets.payload.size, stage)
    uSum.io.nets.valid   := nets.valid
    uSum.io.nets.payload := nets.payload.resized
    uSum
  }

def pipeTree(nets: Flow[Vec[SInt]], groupSize: Int , stage: Int = 0): (List[Sum], Int) = {

    val nextstage = stage + 1

    if (nets.payload.size <= groupSize) {
      (List(sumAdd(nets, nextstage)), nextstage)
    } else {
      val grpNum = scala.math.ceil(nets.payload.size.toDouble / groupSize).toInt
      val nextStage = (0 until grpNum).toList
        .map(i => nets.payload.drop(i * groupSize).take(groupSize))
        .map{ grouped =>
          val groupednets = Flow(Vec(SInt(grouped.head.getWidth bits), grouped.size))
          groupednets.valid   := nets.valid
          groupednets.payload := Vec(grouped)
          sumAdd(groupednets, nextstage)
        }
      val ret = Flow(Vec(SInt(nextStage.head.io.sum.getWidth bits), nextStage.size))
      ret.valid   := RegNext(nets.valid, init = False)
      ret.payload := Vec(nextStage.map(_.io.sum)).resized
      pipeTree(ret, groupSize, nextstage)
    }
}

class AdderTree(diw: Int, size: Int, groupSize: Int) extends Component{

    val io_nets = slave Flow(Vec(SInt(diw bits), size))

    val (sum, stage) = pipeTree(io_nets, groupSize, 0)

    this.setDefinitionName(s"adderTree_n${size}_g${groupSize}_dly${stage}")

    def Latency: Int = stage

    def dow: Int = diw + log2Up(groupSize) * stage

    val io_sum  = master Flow(SInt(sum.head.io.sum.getWidth bits))

    io_sum.payload := sum.head.io.sum
    io_sum.valid   := RegNext(sum.head.io.nets.valid, init = False)
}

object AdderTree {
  def apply(nets: Flow[Vec[SInt]], addCellSize: Int): AdderTree = {
    val uAdderTree = new AdderTree(nets.payload.head.getWidth, nets.payload.size, addCellSize)
    uAdderTree.io_nets := nets
    uAdderTree
  }

  def apply(nets: Vec[SInt], addCellSize: Int): AdderTree = {
    val uAdderTree = new AdderTree(nets.head.getWidth, nets.size, addCellSize)
    uAdderTree.io_nets.payload := nets
    uAdderTree.io_nets.valid   := True
    uAdderTree
  }
}

class Top extends Component{
    val nets = Flow(Vec(SInt(8 bits), 23))
    AdderTree(nets, addCellSize = 4)//group size = 4
}

showRtl(new Top)
// we change the addCellSize/groupSize = 4 , then got following diagram
