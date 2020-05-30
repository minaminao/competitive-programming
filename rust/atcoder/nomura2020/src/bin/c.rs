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
        mut N:usize,
        A:[usize;N+1]
    }
    N += 1;
    let mut ans = 0;
    let mut B = vec![0; N];
    let sum: usize = A.iter().sum();
    B[N - 1] = A[N - 1];
    for i in (0..N - 1).rev() {
        B[i] = B[i + 1] + A[i];
    }
    let mut t = 1;
    let mut f = true;
    for i in 0..N {
        ans += min(t, B[i]);
        if t < A[i] {
            f = false;
            break;
        }
        t -= A[i];
        t *= 2;
    }
    if f {
        println!("{}", ans);
    } else {
        println!("-1");
    }
}
