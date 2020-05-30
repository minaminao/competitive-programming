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
    input! {
        T:Chars
    }
    let N = T.len();
    let mut S = Vec::<char>::new();
    let mut ans: usize = 0;
    let mut even = 0;
    let mut one_sum = 0;
    let mut zero_sum = 0;
    let mut tmp = 0;
    for i in 0..N {
        if T[i] == '1' {
            tmp += 1;
            one_sum += 1;
        } else {
            if tmp % 2 == 0 {
                even += tmp;
            } else {
                even += tmp / 2 * 2;
                S.push('1');
            }
            tmp = 0;
            S.push('0');
            zero_sum += 1;
        }
    }
    if tmp > 0 {
        if tmp % 2 == 0 {
            even += tmp;
        } else {
            even += tmp / 2 * 2;
            S.push('1');
        }
    }
    let M = S.len();
    let mut zero = 0;
    for i in 0..M {
        if S[i] == '1' {
            if i % 2 == 1 {
                ans += zero / 2 + (zero_sum - zero);
            } else {
                ans += (zero + 1) / 2 + (zero_sum - zero);
            }
        } else {
            zero += 1;
            ans += even / 2;
        }
    }
    for i in 1..one_sum + 1 {
        ans += (i + 1) / 2;
    }
    println!("{}", ans);
}
