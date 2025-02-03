class FIR extends Component{
    val fi = slave Flow(SInt(8 bits))
    val fo = master Flow(SInt(8 bits)) 
    
    fo << fi.stage()
    
    def -->(that: FIR):FIR = {
        this.fo >> that.fi 
        that
    }
}

class casCadeFilter extends Component{
    val fi = slave Flow(SInt(8 bits))
    val fo = master Flow(SInt(8 bits))
    
    val Firs = List.fill(4)(new FIR)
    
    Firs(0) --> Firs(1) --> Firs(2) --> Firs(3) 
  //Firs(0).-->(Firs(1)).-->(Firs(2)).-->(Firs(3))  //scala Infix expression excute from left to right 
    Firs(0).fi << fi
    fo << Firs(3).fo   
}
showRtl(new casCadeFilter)
