//mux
class Top extends Component{
  val sel  = in UInt(2 bits)
  val data = in Bits(128 bits)
  val dataWord = sel.muxList(for(index <- 0 until 4) yield (index, data(index*32+32-1 downto index*32)))
  // This example can be written shorter.
  val dataWord2 = data.subdivideIn(32 bits)(sel)
}
showRtl(new Top)
