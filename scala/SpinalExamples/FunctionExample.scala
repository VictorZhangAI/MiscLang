class Top extends Component{
  val a = in UInt(8 bits)
  val b = out UInt(8 bits) 
  val c = out UInt(8 bits) 
    
  def pass(x: UInt, n : Int) = {
      val ret = UInt(n bits)
          ret := x 
      ret 
  }
    
  def pass2(x: UInt) = {
      class Fix(n: Int) extends Component {
          val a = in UInt()
          val b = out  UInt() 
          b := pass(in(a), n)
      }
      val res = new Fix(x.getWidth)
      res.a := x
      res.b
  }
    b := pass(a,8)
    c := pass2(a)
}
showRtl(new Top) 
