#[allow(unused_imports)]
use std::cmp::{max, min, Reverse};
#[allow(unused_imports)]
use std::collections::{BinaryHeap, HashMap, HashSet};
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

const INF_DIST: usize = std::usize::MAX;
type Graph = Vec<Vec<(usize, usize, usize)>>;
fn dijkstra(g: &Graph, start: usize) -> Vec<usize> {
    let n = g.len();
    let mut vis = vec![false; n];
    let mut dist = vec![INF_DIST; n];
    let mut heap = BinaryHeap::new();

    dist[start] = 0;
    heap.push(Reverse((0, start)));

    while let Some(Reverse((cost, v))) = heap.pop() {
        if dist[v] < cost {
            continue;
        }
        vis[v] = true;
        for e in &g[v] {
            let (_, d, w) = &e;
            if vis[*d] {
                continue;
            }
            if dist[*d] > dist[v] + w {
                dist[*d] = dist[v] + w;
                heap.push(Reverse((dist[*d], *d)));
            }
        }
    }
    dist
}

const CMAX: usize = 2600;
fn id(i: usize, c: usize) -> usize {
    i * CMAX + c
}

fn rid(id: usize) -> (usize, usize) {
    (id / CMAX, id % CMAX)
}

#[allow(non_snake_case)]
fn main() {
    let N = read::<usize>();
    let M = read::<usize>();
    let S = read::<usize>();
    let mut U = Vec::new();
    let mut V = Vec::new();
    let mut A = Vec::new();
    let mut B = Vec::new();

    for _ in 0..M {
        let u = read::<usize>() - 1;
        let v = read::<usize>() - 1;
        let a = read::<usize>();
        let b = read::<usize>();
        U.push(u);
        V.push(v);
        A.push(a);
        B.push(b);

        U.push(v);
        V.push(u);
        A.push(a);
        B.push(b);
    }
    let M = 2 * M;
    let mut C = Vec::new();
    let mut D = Vec::new();
    for _ in 0..N {
        C.push(read::<usize>());
        D.push(read::<usize>());
    }

    let mut g = vec![Vec::<(usize, usize, usize)>::new(); N * CMAX];
    let MAX = min(CMAX - 1, S);

    for i in 0..M {
        for c in 0..CMAX {
            let s = id(U[i], c);
            if c < A[i] {
                continue;
            }
            let nc = c - A[i];
            let d = id(V[i], nc);
            g[s].push((s, d, B[i]));
        }
    }
    for i in 0..N {
        for c in 0..CMAX {
            let s = id(i, c);
            let nc = c + C[i];
            if nc >= CMAX {
                continue;
            }
            let d = id(i, nc);
            g[s].push((s, d, D[i]));
        }
    }
    let dist = dijkstra(&g, id(0, MAX));
    for t in 1..N {
        let mut ans = INF_DIST;
        for c in 0..CMAX {
            ans = min(ans, dist[id(t, c)]);
        }
        println!("{}", ans);
    }
}
