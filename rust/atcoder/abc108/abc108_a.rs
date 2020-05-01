#[allow(unused_imports)]
use std::collections::*;
use std::io::*;
use std::str::*;

fn main() {
    let k: usize = read();
    let odd = k / 2 + k % 2;
    let even = k / 2;
    println!("{}", odd * even);
}

fn read<T: FromStr>() -> T {
    let cin = stdin();
    let cin = cin.lock();
    let s: String = cin
        .bytes() // Bytes
        .map(|c| c.expect("failed reading char") as char)
        .skip_while(|c| c.is_whitespace()) // c が whitespace である限り skip
        .take_while(|c| !c.is_whitespace()) // c が whitespace でない限り要素を返す
        .collect();
    s.parse().ok().expect("failed parsing")
}
