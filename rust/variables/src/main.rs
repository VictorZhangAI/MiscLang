use std::io;

fn main(){

    //This code could be panicked!

    let a = [1, 2, 3, 4, 5];

    println!("Please input an array index:");

    let mut index = String::new();

    io::stdin()
    .read_line(&mut index)
    .expect("failed to read line!");

    let index: usize = index
    .trim()
    .parse()
    .expect("Index entered is not a number!");

    let element = a[index];

    println!("The element at {index} is: {element}");
}
