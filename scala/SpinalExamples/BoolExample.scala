class Top extends Component{
  val x = Bool()          
  val y = UInt(8 bits)
  when(x.edge){
      y.setAll
  }.otherwise{
      y.clearAll
  }
}
showRtl(new Top)
