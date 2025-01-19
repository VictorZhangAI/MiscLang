object ClosureExample2 {
  def main(args: Array[String]): Unit = {
    def makeAdder(adder: Int): Int => Int = {
      (x: Int) => x + adder
    }

    val addFive = makeAdder(5)
    val addTen = makeAdder(10)
    
    println(addFive(3))
    println(addTen(3))
  }
}
