import java.io._

class Point(val xc: Int, val yc: Int){
  var x: Int = xc
  var y: Int = yc
  def move(dx: Int, dy: Int) {
    x = x + dx
    y = y + dy
    println("x axis:" + x)
    println("y axis:" + y)
  } 
}

class Location(override val xc: Int, override val yc: Int,
      val zc: Int) extends Point(xc, yc) {
  var z: Int = zc

  def move(dx: Int, dy: Int, dz: Int) {
    x = x + dx
    y = y + dy
    z = z + dz
    println(s"x axis: $x")
    println(s"y axis: $y")
    println(s"z axis: $z")
  }
}

object OverrideClass {
  def main(args: Array[String]) {
    val loc = new Location(10, 20, 30)
    loc.move(2, 4, 5)
  }
}
