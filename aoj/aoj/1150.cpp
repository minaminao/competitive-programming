//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//int dp[61][31][61][31][2];
//char c[61][31];
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	for (int h, w; cin >> h >> w&&h;) {
//		rep(i, 0, h)rep(j, 0, w) {
//			cin >> c[i][j];
//		}
//		using T = tuple<int, int, int>;
//		queue<T> q;
//		auto inrange = [&](int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; };
//		while (q.size()) {
//			int ci, cj, right;
//			tie(ci, cj, right) = q.front(); q.pop();
//			rep(di, 0, 3)rep(dj, 0, 3) {
//				if (di + dj < 3) {
//					if (right) {
//						int ni = ci + di, nj = cj + dj;
//						
//					}
//					else {
//						int ni = ci + di, nj = cj - dj;
//
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}