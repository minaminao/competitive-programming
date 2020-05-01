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
    let mut h = Vec::<usize>::new();
    for i in 0..n {
        h.push(read());
    }
    for i in 1..n {
        if h[i - 1] < h[i] {
            h[i] -= 1;
        } else if h[i - 1] > h[i] {
            println!("No");
            return;
        }
    }
    println!("Yes");
}
