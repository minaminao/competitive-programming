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
    input! {X:usize,Y:usize}
    for i in 0..X + 1 {
        let j = X - i;
        if i * 2 + j * 4 == Y {
            println!("Yes");
            return;
        }
    }
    println!("No");
}
