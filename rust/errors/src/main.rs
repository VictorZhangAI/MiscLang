use std::fs::File;
use std::error::Error;

// fn read_username_from_file()-> Result<String, io::Error> {

//     let mut username = String::new();

//     File::open("hello.txt")?.read_to_string(&mut username)?;

//     Ok(username)

//     //fs::read_to_string("hello.txt");
// }

// fn last_char_from_first_line(text: &str)-> Option<char> {
//     text.lines().next()?.chars().last()
// }

fn main()-> Result<(), Box<dyn Error>>{
    let greeting_file = File::open("hello.txt")?;

    Ok(())
}
