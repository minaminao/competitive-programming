#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};
//#[allow(unused_imports)]
//use std::convert::{TryFrom, TryInto};
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

struct UnionFind {
    parent: Vec<i32>,
    size: usize,
}

impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind {
            parent: vec![-1; n],
            size: n,
        }
    }

    fn unite(&mut self, mut x: usize, mut y: usize) -> bool {
        x = self.root(x);
        y = self.root(y);
        if x == y {
            return false;
        }
        if self.size_of(x) < self.size_of(y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.parent[x] += self.parent[y];
        self.parent[y] = x as i32;
        self.size -= 1;
        return true;
    }

    fn same(&mut self, x: usize, y: usize) -> bool {
        return self.root(x) == self.root(y);
    }

    fn root(&mut self, x: usize) -> usize {
        return if self.parent[x] < 0 {
            x
        } else {
            let r = self.parent[x] as usize;
            self.parent[x] = self.root(r) as i32;
            self.parent[x] as usize
        };
    }

    #[allow(dead_code)]
    fn size_of(&mut self, x: usize) -> i32 {
        let r = self.root(x);
        return -self.parent[r];
    }
}

fn main() {
    input! {
        n: usize,
        q: usize,
        e: [(u8, usize, usize); q],
    }
    let mut uf = UnionFind::new(n);
    let mut ans = String::new();
    for (p, a, b) in e {
        if p == 0 {
            uf.unite(a, b);
        } else {
            let v = if uf.same(a, b) { "Yes" } else { "No" };
            ans.push_str(v);
            ans.push('\n');
        }
    }
    print!("{}", ans);
}
