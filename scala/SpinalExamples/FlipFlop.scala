class Top extends Component{
    val a = in Bits(8 bits)
    val b = RegNext(a) init 0
}
showRtl(new Top)
