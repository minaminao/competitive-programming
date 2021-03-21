#[allow(unused_imports)]
use algo;
#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};

#[allow(non_snake_case)]
fn main() {
    input! {
        mut A:usize,
        B:Chars,
    }
    let mut b = 0;
    b += B[0] as usize - '0' as usize;
    b *= 10;
    b += B[2] as usize - '0' as usize;
    b *= 10;
    b += B[3] as usize - '0' as usize;
    A *= b;
    A /= 100;
    println!("{}", A);
}
