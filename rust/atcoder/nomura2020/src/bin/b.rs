#[allow(unused_imports)]
use algo;
#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};

fn main() {
    input!{mut D:Chars}
    for c in &mut D {
        if *c == '?'{
            *c = 'D';
        }
    }
    println!("{}", D.iter().collect::<String>());
}
