object ClosureExample4 {
  def main(args: Array[String]): Unit = {
    def highOrderFunction(f: Int => Int, x: Int): Int = f(x)

    val externalVar = 5
    val closure = (x: Int) => x + externalVar

    println(highOrderFunction(closure, 10))
  }
}
