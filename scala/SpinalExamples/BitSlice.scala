class T6 extends Component{
    val a = in SInt(16 bits) 
    val b  = out SInt()
    val c  = out SInt() 
    val o0,o1,o2,o3 = out Bool()
    
    b  := a(5 downto 2)  
    c  := a(0 to 4)
    o0 := a.msb
    o1 := a.lsb
    o2 := a(0)
    o3 := a(9)
    
    println(c.getWidth)
}

showRtl(new T6)
