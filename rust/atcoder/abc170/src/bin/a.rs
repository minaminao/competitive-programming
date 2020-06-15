#[allow(unused_imports)]
use algo;
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
        x:[usize;5]
    }
    for i in 0..5 {
        if x[i] == 0 {
            println!("{}", i + 1);
        }
    }
}
