object TimeTest {
  def main(args: Array[String]): Unit = {
    delayed(time())
  }

  def time() = {
    println("Get time in nanoseconds")
    System.nanoTime
  }

  def delayed(t: => Long) = {
    println("In the delayed method")
    println("param:" + t)
    t
  }
}
