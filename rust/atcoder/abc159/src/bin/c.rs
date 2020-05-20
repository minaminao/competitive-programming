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
        L:f64
    }
    println!("{}", (L / 3.0).powf(3.0));
}
