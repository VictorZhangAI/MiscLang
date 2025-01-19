import java.io.FileReader
import java.io.FileNotFoundException
import java.io.IOException

object ExceptionTest {
  def main(args: Array[String]) {
    try {
      val f = new FileReader("input.txt")
    } catch {
      case ex: FileNotFoundException => {
        println("Missing file Exception")
      }
      case ex: IOException => {
        println("IO Exception")
      }
    }finally {
        println("Exciting finally...")
    }
  }
}
