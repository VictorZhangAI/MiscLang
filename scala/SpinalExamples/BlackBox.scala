import spinal.lib.graphic._
class Top extends Component{
    val io = new Bundle{
        val writeValid = in Bool()
        val writeAddress = in UInt(8 bits)
        val writeData = in(Rgb(RgbConfig(8,8,8)))
        val readValid = in Bool()
        val readAddress = in UInt(8 bits)
        val readData = out(Rgb(RgbConfig(8,8,8)))
    }
    
 val mem = Mem(Rgb(RgbConfig(8,8,8)),1024)
    
 mem.generateAsBlackBox() // explicitly set a memory to be blackboxed
   
 mem.write(
  enable  = io.writeValid,
  address = io.writeAddress,
  data    = io.writeData
 )

 io.readData := mem.readSync(
  enable  = io.readValid,
  address = io.readAddress
 )
}
showRtl(new Top)    
