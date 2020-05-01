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

// Verified: https://atcoder.jp/contests/chokudai_s001/submissions/7949468
struct BinaryIndexedTree {
    n: usize,
    p: usize,
    v: Vec<isize>,
}

impl BinaryIndexedTree {
    fn new(mut n: usize) -> BinaryIndexedTree {
        let mut p = 1;
        while p < n {
            p = p << 1;
        }
        BinaryIndexedTree {
            n: n,
            p: p,
            v: vec![0; n + 1],
        }
    }

    fn add(&mut self, mut i: usize, x: isize) {
        let mut i = i as isize;
        while i <= self.n as isize {
            self.v[i as usize] = self.v[i as usize] + x;
            i += i & -i;
        }
    }
    fn sum(&mut self, mut i: usize) -> isize {
        let mut ret = 0;
        let mut i = i as isize;
        while i > 0 {
            ret = ret + self.v[i as usize];
            i -= i & -i;
        }
        return ret;
    }
    fn sum2(&mut self, l: usize, r: usize) -> isize {
        return self.sum(r) - self.sum(l - 1);
    }
}

fn main() {
    input! {
        n:usize,
        a:[usize;n]
    }
    let mut bit = BinaryIndexedTree::new(n + 1);
    let mut ans = 0;
    for x in a {
        bit.add(x, 1);
        ans += bit.sum2(x + 1, n);
    }
    println!("{}", ans);
}
