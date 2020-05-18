#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet, VecDeque};
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

// Verified: https://atcoder.jp/contests/atc001/submissions/7948320
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

#[allow(non_snake_case)]
fn main() {
    input! {
        N:usize,
        M:usize,
        AB:[(usize,usize); M]
    }
    let mut uf = UnionFind::new(N);

    let mut g = vec![Vec::new(); N];

    for (a, b) in &AB {
        let a = a - 1;
        let b = b - 1;
        uf.unite(a, b);
        g[a].push(b);
        g[b].push(a);
    }
    if uf.size != 1 {
        println!("No");
    } else {
        println!("Yes");
        let mut vis = vec![false; N];
        let mut q = VecDeque::new();
        q.push_back((0, N));
        let mut ans = vec![0; N];
        while !q.is_empty() {
            let (x, p) = q.pop_front().unwrap();
            if vis[x] {
                continue;
            }
            ans[x] = p;
            vis[x] = true;
            for y in &g[x] {
                if vis[*y] {
                    continue;
                }
                q.push_back((*y, x));
            }
        }
        for i in 1..N {
            println!("{}", ans[i] + 1);
        }
    }
}
