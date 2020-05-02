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

#[allow(non_snake_case)]
fn main() {
    input! {
        N:usize,
        M:usize,
        Q:usize,
        V:[(usize,usize,usize,usize); Q]
    }
    let mut x = 0;
    let mut ans = 0;
    let mut max_x = 1;
    let MM = M;
    for i in 0..N {
        max_x *= MM;
    }
    while x < max_x {
        let mut xx = x;
        let mut f = false;
        for i in 0..N - 1 {
            let a = (xx / MM) % MM;
            let b = xx % MM;
            if a > b {
                xx += (a - b);
                for j in 0..i {
                    xx *= MM;
                }
                x = xx;
                f = true;
                break;
            }
            xx /= MM;
        }
        if f {
            continue;
        }
        let mut v = Vec::new();
        xx = x;
        for i in 0..N {
            v.push(xx % MM);
            xx /= MM;
        }
        v.reverse();
        let mut ans2 = 0;
        for (a, b, c, d) in &V {
            if v[*b - 1] - v[*a - 1] == *c {
                ans2 += *d;
            }
        }
        ans = max(ans, ans2);
        x += 1;
    }
    println!("{}", ans);
}
