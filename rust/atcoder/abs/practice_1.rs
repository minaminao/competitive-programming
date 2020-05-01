use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let a = line.trim().parse::<usize>().unwrap();

    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut it = line.split_whitespace();
    let b = it.next().unwrap().parse::<usize>().unwrap();
    let c = it.next().unwrap().parse::<usize>().unwrap();

    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let s = line.trim();

    println!("{} {}", a + b + c, s);
}
