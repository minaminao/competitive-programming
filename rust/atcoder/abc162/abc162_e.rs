#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};
#[allow(unused_imports)]
use std::io::*;
#[allow(unused_imports)]
use std::str::*;

#[allow(unused_macros)]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        let mut next = || { iter.next().unwrap() };
        input_inner!{next, $($r)*}
    };
    ($($r:tt)*) => {
        let stdin = std::io::stdin();
        let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));
        let mut next = move || -> String{
            bytes
                .by_ref()
                .map(|r|r.unwrap() as char)
                .skip_while(|c|c.is_whitespace())
                .take_while(|c|!c.is_whitespace())
                .collect()
        };
        input_inner!{next, $($r)*}
    };
}

#[allow(unused_macros)]
macro_rules! input_inner {
    ($next:expr) => {};
    ($next:expr, ) => {};

    ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($next, $t);
        input_inner!{$next $($r)*}
    };

    ($iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        let mut $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[allow(unused_macros)]
macro_rules! read_value {
    ($next:expr, ( $($t:tt),* )) => {
        ( $(read_value!($next, $t)),* )
    };

    ($next:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
    };

    ($next:expr, chars) => {
        read_value!($next, String).chars().collect::<Vec<char>>()
    };

    ($next:expr, usize1) => {
        read_value!($next, usize) - 1
    };

    ($next:expr, $t:ty) => {
        $next().parse::<$t>().expect("Parse error")
    };
}

#[allow(dead_code)]
fn read<T: FromStr>() -> T {
    let cin = stdin();
    let cin = cin.lock();
    let s: String = cin
        .bytes() // Bytes
        .map(|c| c.expect("failed reading char") as char)
        .skip_while(|c| c.is_whitespace()) // c が whitespace である限り skip
        .take_while(|c| !c.is_whitespace()) // c が whitespace でない限り要素を返す
        .collect();
    s.parse().ok().expect("failed parsing")
}

fn modpow(mut a: usize, mut e: usize, m: usize) -> usize {
    let mut res = 1;
    while e > 0 {
        if e & 1 == 1 {
            res = res * a % m;
        }
        a = a * a % m;
        e >>= 1;
    }
    res
}

fn divisors(x: usize) -> Vec<usize> {
    let mut v = Vec::new();
    let mut i = 1;
    while i * i < x {
        if x % i != 0 {
            i += 1;
            continue;
        }
        v.push(i);
        v.push(x / i);
        i += 1;
    }
    if i * i == x {
        v.push(i);
    }
    v
}

#[allow(non_snake_case)]
fn main() {
    input! {
        N:usize,
        K:usize
    }

    let mut p = vec![0; K + 1];

    let m = 1000000007;

    for g in (1..K + 1).rev() {
        p[g] += modpow(K / g, N, m);
        p[g] %= m;
        let d = divisors(g);
        for x in d {
            if x == g {
                continue;
            }
            p[x] = (p[x] + m - p[g]) % m;
        }
    }

    let mut ans = 0;
    for g in 1..K + 1 {
        ans += p[g] * g;
        ans %= m;
    }

    println!("{}", ans);
}
