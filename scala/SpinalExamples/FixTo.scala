class Top extends Component{
    val A = in SInt(10 bits)  
    val B = A.fixTo(7 downto 3) //default RoundToInf, same as A.roundToInf(3).sat(3)
 }
showRtl(new Top)
