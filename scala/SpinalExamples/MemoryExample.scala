class Top extends Component{
 val io = new Bundle{
        val writeValid = in Bool()
        val writeAddress = in UInt(8 bits)
        val writeData = in Bits(32 bits)
        val readValid = in Bool()
        val readAddress = in UInt(8 bits)
        val readData = out Bits(32 bits)
    }
 val mem = Mem(Bits(32 bits),wordCount = 256)
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
