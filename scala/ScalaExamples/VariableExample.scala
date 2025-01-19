object VariableExample {
  def main(args: Array[String]): Unit = {
    val immutableValue: Int = 15
    var mutableValue: Int = 25
    println(s"Value $immutableValue is immutable")
    println(s"Value $mutableValue is mumtable")
    mutableValue += immutableValue
    println(s"After changing: $mutableValue")
  }
}
