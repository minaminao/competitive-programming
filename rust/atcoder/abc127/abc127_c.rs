#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};
#[allow(unused_imports)]
use std::io::*;
#[allow(unused_imports)]
use std::str::*;

#[allow(dead_code)]
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

fn main() {
    let n: usize = read();
    let m: usize = read();
    let mut l = Vec::new();
    let mut r = Vec::new();
    for _i in 0..m {
        l.push(read::<isize>() - 1);
        r.push(read::<isize>() - 1);
    }
    let a = l.iter().max().unwrap();
    let b = r.iter().min().unwrap();
    println!("{}", max(0, b - a + 1));
}
