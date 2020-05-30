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
    input!{
        H:usize,
        M:usize,
        H2:usize,
        M2:usize,
        K:usize,
    }
    let mut ans = (H2 - H) * 60;
    if M > M2 {
        ans -= (M - M2);
    }
    else {
        ans += (M2 - M);
    }
    ans -= K;
    println!("{}",ans);
}
