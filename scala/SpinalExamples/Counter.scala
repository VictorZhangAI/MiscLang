class Top extends Component{
val inc, clear = Bool()            //Define two combinatorial signal/wire
val counter = Reg(UInt(8 bits))  //Define a 8 bits register

when(inc){
  counter := counter + 1
}
when(clear){
  counter := 0    //If inc and clear are True, then this  assignement wins (Last valid assignement rule)
}
}
showRtl(new Top)
