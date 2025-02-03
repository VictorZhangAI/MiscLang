class Top extends Component{
  val myUInt,myUInt1,myUInt2,myUInt3,myUInt4,myUInt5,myUInt6,myUInt7,myUInt8,myUInt9 = UInt(8 bits)
  myUInt  := U(2,8 bits)
  myUInt1 := U(2)
  myUInt2 := U"0000_0101"  // Base per default is binary => 5
  myUInt3 := U"h1A"        // Base could be x (base 16)
                          //               h (base 16)
                          //               d (base 10)
                          //               o (base 8)
                          //               b (base 2)
  myUInt4 := U"8'h1A"
  myUInt5 := 2             // You can use scala Int as literal value

  val myBool0 = myUInt === U(7 -> true,(6 downto 0) -> false)
  val myBool1 = myUInt === U(myUInt.range -> true)

  // For assignement purposes, you can omit the U/S, which also alow the use of the [default -> ???] feature
  myUInt6 := (default -> true)                        //Assign myUInt with "11111111"
  myUInt7 := (myUInt.range -> true)                   //Assign myUInt with "11111111"
  myUInt8 := (7 -> true, default -> false)            //Assign myUInt with "10000000"
  myUInt9 := ((4 downto 1) -> true, default -> false) //Assign myUInt with "00011110"
}
showRtl(new Top)
