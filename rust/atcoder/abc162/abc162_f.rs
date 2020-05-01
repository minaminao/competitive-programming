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

use std::cmp;
use std::collections::vec_deque::VecDeque;
use std::i64::MAX;
pub struct Edge {
    pub to: usize,
    pub rev: usize,
    pub cap: i64,
}

struct Dinitz {
    g: Vec<Vec<Edge>>,
    level: Vec<i32>,
    iter: Vec<usize>,
}

impl Dinitz {
    fn new(v: usize) -> Dinitz {
        let mut g: Vec<Vec<Edge>> = Vec::new();
        for _ in 0..v {
            g.push(Vec::new());
        }
        Dinitz {
            g: g,
            level: vec![0; v],
            iter: vec![0; v],
        }
    }

    fn add_edge(&mut self, from: usize, to: usize, cap: i64) {
        let to_len = self.g[to].len();
        let from_len = self.g[from].len();
        self.g[from].push(Edge {
            to: to,
            rev: to_len,
            cap: cap,
        });
        self.g[to].push(Edge {
            to: from,
            rev: from_len,
            cap: 0,
        });
    }

    fn dfs(&mut self, v: usize, t: usize, f: i64) -> i64 {
        if v == t {
            return f;
        }
        while self.iter[v] < self.g[v].len() {
            let (e_cap, e_to, e_rev);
            {
                let ref e = self.g[v][self.iter[v]];
                e_cap = e.cap;
                e_to = e.to;
                e_rev = e.rev;
            }
            if e_cap > 0 && self.level[v] < self.level[e_to] {
                let d = self.dfs(e_to, t, cmp::min(f, e_cap));
                if d > 0 {
                    {
                        let ref mut e = self.g[v][self.iter[v]];
                        e.cap -= d;
                    }
                    {
                        let ref mut rev_edge = self.g[e_to][e_rev];
                        rev_edge.cap += d;
                    }
                    return d;
                }
            }
            self.iter[v] += 1;
        }

        return 0;
    }

    fn bfs(&mut self, s: usize) {
        let v = self.level.len();
        self.level = vec![-1; v];
        self.level[s] = 0;
        let mut deque = VecDeque::new();
        deque.push_back(s);
        while !deque.is_empty() {
            let v = deque.pop_front().unwrap();
            for e in &self.g[v] {
                if e.cap > 0 && self.level[e.to] < 0 {
                    self.level[e.to] = self.level[v] + 1;
                    deque.push_back(e.to);
                }
            }
        }
    }

    fn max_flow(&mut self, s: usize, t: usize, max: i64) -> i64 {
        let v = self.level.len();
        let mut flow: i64 = 0;
        loop {
            self.bfs(s);
            if self.level[t] < 0 || max == flow {
                return flow;
            }
            self.iter = vec![0; v];
            loop {
                let f = self.dfs(s, t, max - flow);
                if f == 0 {
                    break;
                }
                flow += f;
            }
        }
    }
}

#[allow(non_snake_case)]
fn main() {
    input! {
        N:usize,
        A:[i64;N]
    }

    let n = N + 2;
    let s = n - 1;
    let t = n - 2;
    let mut dinitz = Dinitz::new(n);
    let base = std::i32::MAX as i64;
    for i in 0..N {
        if i % 2 == 0 {
            dinitz.add_edge(s, i, base - A[i]);
            dinitz.add_edge(i, t, base);
        } else {
            dinitz.add_edge(s, i, base);
            dinitz.add_edge(i, t, base - A[i]);
        }
    }
    let inf = std::i64::MAX / 2;
    for i in 0..N - 1 {
        if i % 2 == 0 {
            dinitz.add_edge(i + 1, i, inf);
        } else {
            dinitz.add_edge(i, i + 1, inf);
        }
    }
    let mut ans = dinitz.max_flow(s, t, (N / 2) as i64) - base * (N as i64);
    ans = -ans;
    println!("{}", ans);
}
