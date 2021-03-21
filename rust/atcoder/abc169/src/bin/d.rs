#[allow(unused_imports)]
use algo;
use primes;
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
    input! {N:usize}
    let p = primes::factors(N as u64);
    let mut ans = 0;
    let mut c = Vec::new();
    let mut prev = 0;
    let mut cnt = 0;
    for x in p {
        if prev == x {
            cnt += 1;
        } else {
            c.push(cnt);
            cnt = 1;
        }
        prev = x;
    }
    c.push(cnt);

    for mut x in c {
        for i in 1..100 {
            if x >= i {
                ans += 1;
                x -= i;
            } else {
                break;
            }
        }
    }

    println!("{}", ans);
}
