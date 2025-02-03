//When 
class Top extends Component{
    val cond1,cond2= in Bool()
    val dout = out UInt(8 bits)
  when(cond1){
      dout := 11
  //execute when      cond1 is true
  }.elsewhen(cond2){
      dout := 23
  //execute when (not cond1) and cond2
  }.otherwise{
      dout := 51
  //execute when (not cond1) and (not cond2)
  }
}
showRtl(new Top)
