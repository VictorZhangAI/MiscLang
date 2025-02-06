case class RGB(channelWidth: Int) extends Bundle{
  val red   = UInt(channelWidth bit)
  val green = UInt(channelWidth bit)
  val blue  = UInt(channelWidth bit)
  def isBlack : Bool = red === 0 && green === 0 && blue === 0
} 

class MyRGB extends Component{
  val source = slave  Stream(RGB(8))
  val sink   = master Stream(RGB(8))
  sink <-< source.s2mPipe
} 


showRtl(new MyRGB)
