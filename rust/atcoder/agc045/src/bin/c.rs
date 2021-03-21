#[allow(unused_imports)]
use algo;
#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet, VecDeque};

fn ex() {
    let N = 5;
    let mut mat = vec![vec![0; N]; N];
    for A in 1..N + 1 {
        for B in 1..N + 1 {
            let mut q = VecDeque::new();
            let v = vec![0; N];
            q.push_back(v);
            let mut vis = HashSet::new();
            while !q.is_empty() {
                let u = q.pop_front().unwrap();
                if vis.contains(&u) {
                    continue;
                }
                vis.insert(u.clone());
                for i in 0..N - A + 1 {
                    let mut nu = u.clone();
                    for j in i..i + A {
                        nu[j] = 0;
                    }
                    if !vis.contains(&nu) {
                        q.push_back(nu);
                    }
                }
                for i in 0..N - B + 1 {
                    let mut nu = u.clone();
                    for j in i..i + B {
                        nu[j] = 1;
                    }
                    if !vis.contains(&nu) {
                        q.push_back(nu);
                    }
                }
            }
            mat[A - 1][B - 1] = vis.len();
            println!("A={} B={} l={}", A, B, vis.len());
            for x in vis {
                for b in x {
                    print!("{}", b);
                }
                println!();
            }
            println!();
        }
    }

    for A in 1..N + 1 {
        for B in 1..N + 1 {
            print!("{} ", mat[A - 1][B - 1]);
        }
        println!();
    }
}

#[allow(non_snake_case)]
fn main() {
    ex();
    let N = 10;
    let k = 2;
    let mut a = vec![1; N * N];
    for n in 2..20 {
        a[n] = 2 * a[n - 1];
        if n >= 2 {
            a[n] -= a[n - 2];
            println!(" -{}", a[n - 2])
        }
        if n >= k + 1 {
            a[n] += a[n - k - 1];
            println!(" +{}", a[n - k - 1])
        }
        println!("{} {}", n, a[n]);
    }
    dbg!(a);
}
