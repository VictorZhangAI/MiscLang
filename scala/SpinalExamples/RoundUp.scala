class Top extends Component{
    val a = in SInt(16 bits) //source data is 16 bits 
    val f = a.roundUp(2)     //round 2 bits to +Inf  return 15 bits
 }
showRtl(new Top)
