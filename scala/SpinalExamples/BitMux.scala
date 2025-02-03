//the example of ALU
class Top extends Component{
    val io = new Bundle{
        val src0,src1 = in Bool()
    }
  val bitwiseSelect = UInt(2 bits)
  val bitwiseResult = bitwiseSelect.mux(
   0 -> (io.src0 & io.src1),
   1 -> (io.src0 | io.src1),
   2 -> (io.src0 ^ io.src1),
   default -> (io.src0)
  )
}
showRtl(new Top)
