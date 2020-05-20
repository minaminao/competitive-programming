#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{HashMap, HashSet};
#[allow(unused_imports)]
use std::io::*;
#[allow(unused_imports)]
use std::str::*;

fn data_structures() {
    // String
    {
        let s: String;

        // String to Vec<char>
        s.chars().collect::<Vec<char>>();

        // Count
        s.chars().filter(|c| *c == '1').count();
        s.chars().filter(|&c| c == 'o').count();

        // Replace
        s.replace("2017", "2018");

        // Vec<char> to String
        let v = Vec::new();
        v.iter().collect::<String>();

        // Slice
        &S[0..5];
    }

    // Vec
    {
        let mut v = Vec::new();
        let mut v = vec![0; N];
        v = Vec::with_capacity(100);

        v.reverse();

        // Vec<char> -> String
        let s = s.into_iter().collect::<String>();

        // max min
        v.into_iter().max().unwrap();
        v.into_iter().min().unwrap();

        v.iter().sum();
    }

    // HashSet
    {
        let a = 0;
        let mut st = HashSet::new();
        st.insert(1);
        st.contains(&a);
    }

    // HashMap
    {
        let m = HashMap::new();
        m.insert(1, 2); // HashMap<i32, i32>
        let m = HashMap::<usize, usize>::new();
        *m.entry(0).or_insert(0) += 1;
    }
}

fn io() {
    let b = 0;
    let a = 0;

    // 入力
    input! {
        n: usize,
        v: [(usize, usize); n],
        s: chars
    }

    // 出力
    {
        let ans: String = t.into_iter().collect();
        println!(
            "{}",
            if a == b.chars().rev().collect::<String>() {
                "YES"
            } else {
                "NO"
            }
        );

        println!(
            "{}",
            match N % 10 {
                0 | 1 | 6 | 8 => "pon",
                3 => "bon",
                _ => "hon",
            }
        );

        // 定数倍高速化
        let mut ans = String::new();
        for i in 0..n {
            ans.push_str(s);
            ans.push('\n');
        }
        print!("{}", ans);
    }

    // debug
    dbg!(s);
}

fn main() {
    let n = format!("{:b}", n);

    let mut ans = None;
    for c in b'a'..b'z' + 1 {
        let c = char::from(c);
        ans = Some(c.to_string());
    }
    for i in (0..n).rev() {}
    println!("{}", ans.unwrap_or("None".to_string()));

    for (a, b) in v {}

    std::f64::consts::PI;
}
