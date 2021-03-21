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
        N:usize,
        AB:[(usize,usize);N]
    }
    let mut A = Vec::new();
    let mut B = Vec::new();
    for (a, b) in AB {
        A.push(a);
        B.push(b);
    }
    A.sort();
    B.sort();
    let mini;
    let maxi;
    let ans;
    if N % 2 == 0 {
        mini = A[N / 2] + A[N / 2 - 1];
        maxi = B[N / 2] + B[N / 2 - 1];
        ans = maxi - mini + 1;
    } else {
        mini = A[N / 2];
        maxi = B[N / 2];
        ans = maxi - mini + 1;
    }
    println!("{}", ans);
}
