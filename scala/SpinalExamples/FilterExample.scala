case class FilterConfig(iqWidth: Int, 
                        tapNumbers: Int = 33,
                        hwFreq: HertzNumber = 200 MHz, 
                        sampleFreq: HertzNumber = 1.92 MHz)

case class IQ(width: Int) extends Bundle{
  val I,Q = SInt(width bits)
}

class Filter(fc: FilterConfig) extends Component{
  //val din   = slave Flow(IQ(fc.iqWidth))
  //val dout  = master Flow(IQ(fc.iqWidth))
  val din   = slave Flow(Bits(32 bits))
  val dout  = master Flow(Bits(32 bits))
  val flush = in Bool()
    
  val clockSMP = ClockDomain.external("smp")
  val clockHW = ClockDomain.external("hw")
    
  val u_fifo_in = StreamFifoCC(
      dataType = Bits(32 bits), 
      depth = 8,
      pushClock = clockSMP,
      popClock = clockDomain
  )
    
  u_fifo_in.io.push << din.toStream 
  dout << u_fifo_in.io.pop.toFlow
    
}

showRtl(new Filter(FilterConfig(8)))
