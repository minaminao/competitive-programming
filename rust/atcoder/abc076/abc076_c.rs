#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};
#[allow(unused_imports)]
use std::io::*;
#[allow(unused_imports)]
use std::str::*;

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

fn main() {
    let t: String = read();
    let ss: String = read();
    let mut t = t.chars().collect::<Vec<char>>();
    let ss = ss.chars().collect::<Vec<char>>();
    let n = t.len();
    let m = ss.len();
    for i in 0..n {
        if n < (i + m) {
            break;
        }
        let j = n - i - m;
        let mut ok = true;
        for k in 0..m {
            if t[j + k] != '?' && t[j + k] != ss[k] {
                ok = false;
                break;
            }
        }
        if ok {
            for k in 0..m {
                t[j + k] = ss[k];
            }
            for k in 0..n {
                if t[k] == '?' {
                    t[k] = 'a';
                }
            }
            let ans: String = t.into_iter().collect();
            println!("{}", ans);
            return;
        }
    }
    println!("UNRESTORABLE");
}
