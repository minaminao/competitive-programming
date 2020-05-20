#[allow(unused_imports)]
use algo;
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};

#[allow(non_snake_case)]
fn main() {
    input! {
        S: Chars
    }
    let mut ok = true;
    for i in 0..S.len() {
        if S[i] != S[S.len() - 1 - i] {
            ok = false;
        }
    }
    let N = (S.len() - 1) / 2;
    for i in 0..N {
        if S[i] != S[N - 1 - i] {
            ok = false;
        }
    }
    for i in (S.len() + 3) / 2..S.len() {
        if S[i] != S[S.len() - 1 - i] {
            ok = false;
        }
    }
    println!("{}", if ok { "Yes" } else { "No" });
}
