class Person {
  var name = ""
  override def toString = getClass.getName + "[name=" + name + "]"
}

class Employee extends Person {
  var salary = 0.0
  override def toString = super.toString + "[salary=" + salary + "]"
}

object OverrideClass2 extends App{
  val fred = new Employee
  fred.name = "Fred"
  fred.salary = 20000
  println(fred)
}
