class Top extends Component{
  var x = UInt(4 bits)
  val y,z = UInt(4 bits)
  x := 0
  y := x      //y read x with the value 0
  x \= x + 1
  z := x      //z read x with the value 1
}
showRtl(new Top)
