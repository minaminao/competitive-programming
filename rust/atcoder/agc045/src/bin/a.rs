#[allow(unused_imports)]
use algo;
#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet, VecDeque};

#[allow(non_snake_case)]
fn main() {
    input! {
        T:usize
    }
    for _ in 0..T {
        input! {
            N:usize,
            A:[usize;N],
            S:Chars,
        }
    }
}
