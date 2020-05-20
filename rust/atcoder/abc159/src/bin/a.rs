use proconio::input;
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};

#[allow(non_snake_case)]
fn main() {
    input! {
        N:usize,
        M:usize,
    }
    let mut ans = 0;
    if N > 0 {
        ans += N * (N - 1) / 2;
    }
    if M > 0 {
        ans += M * (M - 1) / 2;
    }
    println!("{}", ans);
}
