object PrintString {
  def main(args: Array[String]){
    printStrings("Scala", "Python", "Java")
  }

  def printStrings(args: String*) = {
    var i: Int = 0;
    for(arg <- args){
      println("Arg value[" + i + "]" + arg);
      i = i + 1;
    }
  }
}
