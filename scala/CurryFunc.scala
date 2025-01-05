object CurryFunc {
  def main(args: Array[String]): Unit = {
    val str1: String = "Hello, "
    val str2: String = "Scala"
    println("str1 + str2 = " + strcat(str1)(str2))
  }

  def strcat(s1: String)(s2: String) = {
    s1 + s2
  }
}
