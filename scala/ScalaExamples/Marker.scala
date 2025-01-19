import java.io._

class Marker private(val color: String) {
  println("create" + this)

  override def toString(): String = "color mark" + color
}

object Marker {
  private val markers: Map[String, Marker] = Map(
      "red" -> new Marker("red"),
      "blue" -> new Marker("blue"),
      "green" -> new Marker("green")
    )

  def apply(color: String) = {
    if(markers.contains(color)) markers(color) else null
  }

  def getMarker(color: String) = {
    if(markers.contains(color)) markers(color) else null
  }

  def main(args: Array[String]) {
    println(Marker("red"))
    println(Marker getMarker "blue")
  }
}
