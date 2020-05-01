use std::io;
 
fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let mut it = line.split_whitespace();
    let a = it.next().unwrap().parse::<usize>().unwrap();
    let b = it.next().unwrap().parse::<usize>().unwrap();
 
    if (a * b) % 2 == 0 {
        println!("Even");
    } else {
        println!("Odd");
    }
}