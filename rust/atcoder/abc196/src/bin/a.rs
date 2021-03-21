#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(non_snake_case)]
fn main() {
    input! {
        a:isize,
        b:isize,
        c:isize,
        d:isize
    }
    println!("{}", b-c);
}
