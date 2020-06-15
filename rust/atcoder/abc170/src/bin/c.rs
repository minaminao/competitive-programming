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
        X:usize,N:usize,
        p:[usize;N]
    }
    let mut ans = usize::MAX;
    let mut mini = usize::MAX;
    let mut h = HashSet::new();
    for i in 0..N {
        h.insert(p[i]);
    }
    for i in 0..102 {
        let a;
        if h.contains(&i) {
            continue;
        }
        if X > i {
            a = X - i;
        } else {
            a = i - X;
        }
        if a < mini {
            mini = a;
            ans = i;
        }
    }
    println!("{}", ans);
}
