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

fn main() {
    input! {N:i128,
    A:[i128;N]}
    let mut ans = 1;
    for a in &A {
        if *a == 0 {
            ans = 0;
        }
    }
    if ans != 0 {
        for a in A {
            ans *= a;
            if ans > 1000000000000000000 {
                ans = -1;
                break;
            }
        }
    }
    println!("{}", ans);
}
