pub trait Summary {
	fn summarize_author(&self)-> String;

	fn summarize(&self)-> String {
		format!("Read more from {}...", self.summarize_author())
	}
}

pub fn notify(item: &impl Summary){
	println!("Breaking news!: {}", item.summarize());
}

// pub fn notify<T: &Summary>(item1: &T, item2: &T){}

// pub fn notify(item: &(impl Summary + Display))

// pub fn notify<T: Summary + Display>(item: &T)

/*fn some_function<T, U>(t: &T, u: &U)-> i32
where
	T: Display + Clone,
	U: Clone + Debug,
{}*/

pub struct NewsArticle {
	pub headline: String,
	pub location: String,
	pub author: String,
	pub content: String,
}

impl Summary for NewsArticle {
	fn summarize(&self)-> String {
		format!("{}, by {} ({})", self.headline, self.author, self.location)
	}
}

pub struct Tweet {
	pub username: String,
	pub content: String,
	pub reply: bool,
	pub retweet: bool,
}

impl Summary for Tweet {
	// fn summarize(&self)-> String {
	// 	format!("{}: {}", self.username, self.content)
	// }

	fn summarize_author(&self)-> String {
		format!("@{}", self.username)
	}
}

fn returns_summarizable()-> impl Summary {
	Tweet {
		username: String::from("horse ebooks"),
		contents: String::from("of course, as you probably already know, people"),
		reply: false,
		retweet: false,
	}
}