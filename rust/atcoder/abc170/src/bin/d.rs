#[allow(unused_imports)]
use algo;
#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BinaryHeap, HashMap, HashSet, VecDeque};

fn get_divisors(x: usize) -> Vec<usize> {
    let mut ret = Vec::new();
    let mut i = 1;
    while i * i < x {
        if x % i != 0 {
            i += 1;
            continue;
        }
        ret.push(i);
        ret.push(x / i);
        i += 1;
    }
    if i * i == x {
        ret.push(i);
    }
    ret
}

#[allow(non_snake_case)]
fn main() {
    input! {
        N:usize,
        A:[usize;N]
    }
    let mut h = HashMap::new();
    for i in 0..N {
        *h.entry(A[i]).or_insert(0) += 1;
    }
    let mut cnt = 0;
    for i in 0..N {
        let d = get_divisors(A[i]);
        let mut f = true;
        for x in d {
            if !h.contains_key(&x) {
                continue;
            }
            let y = h.get(&x).unwrap();
            if (y - 1 > 0) || (*y == 1 && x != A[i]) {
                f = false;
                break;
            }
        }
        if f {
            cnt += 1;
        }
    }
    println!("{}", cnt);
}
