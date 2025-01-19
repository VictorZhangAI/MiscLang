cmake_minimum_required(VERSION 3.20.0)
project(HelloWorld)
add_executable(HelloWorld HelloWorld.cpp)
if(APPLE)
	target_compile_definitions(HelloWorld PUBLIC APPLE)
endif()

set(var_name var1)
set(${var_name} foo) # same as "set(var1 foo)"
set(${${var_name}}_var bar) #same as "set(foo_var bar)"

if(APPLE)
	set(extra_sources Apple.cpp)
endif()
add_executable(HelloWorld HelloWorld.cpp ${extra_sources})

set(my_list a b c d)
set(my_list "a;b;c;d")

set(my_string "a b c d")


