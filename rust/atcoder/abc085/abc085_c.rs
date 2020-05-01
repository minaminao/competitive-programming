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
    let n: u64 = read();
    let y: u64 = read();
    for n10000 in 0..n + 1 {
        for n5000 in 0..n + 1 {
            for n1000 in 0..n + 1 {
                let p = n10000 * 10000 + n5000 * 5000 + n1000 * 1000;
                if p == y {
                    println!("{} {} {}", n10000, n5000, n1000);
                    return;
                }
            }
        }
    }
    println!("-1 -1 -1 ");
}
