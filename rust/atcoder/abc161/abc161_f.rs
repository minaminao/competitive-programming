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

fn b(mut m: usize, k: usize) -> bool {
    if k == 1 {
        return false;
    }
    while m >= k {
        if m % k == 0 {
            m /= k;
        } else {
            m %= k;
        }
    }
    m == 1
}

fn a(mut n: usize) {
    let mut cnt = 0;
    println!("{}", n);
    for k in 2..n + 1 {
        let mut m = n;
        while m >= k {
            if m % k == 0 {
                m /= k;
            } else {
                m %= k;
            }
        }
        if m == 1 {
            println!("  {}", k);
            cnt += 1;
        }
    }
    println!("  cnt:{}", cnt);
}

fn main() {
    let n: usize = read();
    let mut h = HashSet::new();

    let mut x = n - 1;
    let mut i = 1;
    loop {
        if i * i >= x {
            break;
        }
        if x % i != 0 {
            i += 1;
            continue;
        }
        h.insert(i);
        h.insert(x / i);
        i += 1;
    }
    if i * i == x {
        h.insert(i);
    }

    x = n;
    i = 2;
    loop {
        if i * i >= x {
            break;
        }
        if x % i != 0 {
            i += 1;
            continue;
        }
        if b(i, x / i) {
            h.insert(x / i);
        }
        if b(x / i, i) {
            h.insert(i);
        }
        i += 1;
    }
    if i * i == x {
        if b(i, i) {
            h.insert(i);
        }
    }
    h.insert(n);
    println!("{}", h.len() - 1);
}
