// struct ImportantExcerpt {
//     part: &'a str,
// }

// impl<'a> ImportantExcerpt<'a> {
//     fn level(&self)-> i32 {
//         3
//     }
// }

// fn main(){
//     let novel = String::from("Call me Ishmael. Some years ago...");

//     let first_sentence = novel.split('.').next().unwrap();

//     let i = ImportantExcerpt {
//         part: first_sentence,
//     };
// }


use std::fmt::Display;

fn longest_with_announcement<'a T>(
    x: &'a str,
    y: &'a str,
    ann: T,
)-> &'a str
where
    T: Display,
{
    println!("announcement: {ann}");
    if x.len() > y.len() {
        x
    } else {
        y
    }
}