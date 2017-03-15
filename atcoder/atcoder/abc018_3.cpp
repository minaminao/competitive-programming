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
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int R, C, K; cin >> R >> C >> K;
//	vector<string> s(R); rep(i, 0, R) { cin >> s[i]; }
//	vector<vector<int>> v(R, vector<int>(C));
//	rep(i, 0, R)rep(j, 0, C) {
//		if (s[i][j] == 'o') {
//			v[i][j]++;
//		}
//	}
//	rep(i, 0, R - 1)rep(j, 0, C) {
//		v[i + 1][j] += v[i][j];
//	}
//	dump(v);
//	int ans = 0;
//	K--;
//	rep(i, K, R - K) rep(j, K, C - K) {
//		rep(jj, j - K, j) {
//			dump(v[i + (j - jj)][jj] - v[i - (j - jj)][jj]);
//		}
//		rep(jj, j, j + K + 1) {
//			dump(v[i + (jj - j)][jj] - v[i - (jj - j)][jj]);
//		}
//	}
//	return 0;
//}