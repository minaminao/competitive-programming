#[allow(unused_imports)]
use algo;
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
        A:[Usize1;N]
    }
    let mut cnt = vec![0usize; N];
    for i in 0..N {
        cnt[A[i]] += 1;
    }
    let mut tot = 0;
    for i in 0..N {
        if cnt[i] == 0 {
            continue;
        }
        tot += cnt[i] * (cnt[i] - 1) / 2;
    }
    for i in 0..N {
        let mut ans = tot - cnt[A[i]] * (cnt[A[i]] - 1) / 2;
        if cnt[A[i]] != 1 {
            ans += (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;
        }
        println!("{}", ans);
    }
}
