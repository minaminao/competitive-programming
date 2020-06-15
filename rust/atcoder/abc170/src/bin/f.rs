#[allow(unused_imports)]
use algo;
#[allow(unused_imports)]
use proconio::input;
#[allow(unused_imports)]
use proconio::marker::{Bytes, Chars, Isize1, Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BinaryHeap, HashMap, HashSet, VecDeque};

#[allow(non_snake_case)]
fn main() {
    input! {
        H:usize,W:usize,K:usize,
        x1:Usize1,y1:Usize1,x2:Usize1,y2:Usize1,
        c:[Chars;H]
    }
    let mut h = VecDeque::new();
    let mut dist = vec![vec![vec![usize::MAX; 5]; W]; H];
    let mut dist2 = vec![vec![vec![usize::MAX; 5]; W]; H];
    h.push_back((0, x1, y1, 0, 4));
    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];
    while h.len() > 0 {
        let (p, x, y, k, dir) = h.pop_front().unwrap();
        if p < dist[x][y][dir] {
            dist[x][y][dir] = p;
            dist2[x][y][dir] = k;
        } else if p == dist[x][y][dir] && k > dist2[x][y][dir] {
            dist2[x][y][dir] = k;
        } else {
            continue;
        }
        if x == x2 && y == y2 {
            continue;
        }
        for d in 0..4 {
            let nx = x as isize + dx[d];
            let ny = y as isize + dy[d];
            if nx < 0 || ny < 0 {
                continue;
            }
            let nx = nx as usize;
            let ny = ny as usize;
            if nx >= H || ny >= W {
                continue;
            }
            if c[nx][ny] == '@' {
                continue;
            }
            if k == 0 {
                if p + 1 > dist[nx][ny][d] {
                    continue;
                }
                if p + 1 == dist[nx][ny][d] && K - 1 <= dist[nx][ny][d] {
                    continue;
                }
                h.push_back((p + 1, nx, ny, K - 1, d));
            } else {
                if d == dir {
                    if p > dist[nx][ny][d] {
                        continue;
                    }
                    h.push_front((p, nx, ny, k - 1, d));
                } else {
                    if p + 1 > dist[nx][ny][d] {
                        continue;
                    }
                    if p + 1 == dist[nx][ny][d] && K - 1 <= dist[nx][ny][d] {
                        continue;
                    }
                    h.push_back((p + 1, nx, ny, K - 1, d));
                }
            }
        }
    }
    let mut ans = usize::MAX;
    for i in 0..5 {
        ans = min(ans, dist[x2][y2][i]);
    }
    if ans == usize::MAX {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}
