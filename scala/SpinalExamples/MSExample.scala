 class Top extends Component{
  val a = slave Flow(UInt(8 bits))
  val b = master Flow(UInt(8 bits)) 
  b << a //  b <> a also ok
}
showRtl(new Top)
