object LoopTest {
  def main(args: Array[String]):Unit = {
    var a = 0;
    for(a <- 1 until 10){
      println("Value of a:" + a)
    }
  }
}
