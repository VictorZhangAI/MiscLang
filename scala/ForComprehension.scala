object ForComprehension {
  def main(args: Array[String]): Unit = {
    val numbers = List((1, "one"), (2, "two"), (3, "three"))
    for((number, word) <- numbers) {
      println(s"Number: $number, Word: $word")
    }

    val newNumbers = for {
      (number, word) <- numbers
    } yield(number * 2, word.toUpperCase)

    println(s"New Numbers: $newNumbers")
  }
}
