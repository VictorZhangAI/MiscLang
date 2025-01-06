import java.io._

class Point(val xc: Int, val yc: Int) {
  var x: Int = xc
  var y: Int = yc
  def move(dx: Int, dy: Int) {
    x = x + dx
    y = y + dy
  }
}

object ObjectExample {
  def main(args: Array[String]): Unit = {
    val point = new Point(10, 20)
    printPoint

    def printPoint {
      println("x axis:" + point.x)
      println("y axis:" + point.y)
    }
  }
}
