func1()
{
	local var='func1 local'
	func2
}

func2()
{
	echo "In func2, var = $var"
}

var=global
func1
