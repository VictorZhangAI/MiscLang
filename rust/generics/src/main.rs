/*use generics::{Summary, Tweet};

fn main() {
    let tweet = Tweet{
        username: String::from("horse_ebooks"),
        content: String::from("of course, as you probably already know, people"),
        reply: false,
        retweet: false,
    };

    println!("1 new tweet: {}", tweet.summarize());
}*/

use std::fmt::Display

struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn new(x: T, y: T)-> Self{
        self{x, y}
    }
}

impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self){
        if self.x >= self.y {
            println!("The largest number is: {}", x);
        } else {
            println!("The largest number is: {}", y);
        }
    }
}