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
//int N = 3;
//int f1(const vector<vector<char>> &v) {
//	int cnt = 0;
//	vector<int> cnti(N), cntj(N);
//	rep(i, 0, N)rep(j, 0, N) {
//		if (v[i][j] == '#') {
//			cnt++;
//			cnti[i]++;
//			cntj[j]++;
//		}
//	}
//	if (cnt == 0) {
//		return -1;
//	}
//	else {
//		int ans = INF;
//		rep(i, 0, N) {
//			rep(j, 0, N) {
//				if (v[i][j] == '#') {
//					int cost = (N - cnti[j]) * 2;
//					rep(jj, 0, N) {
//						if (v[j][jj] == '#') {
//							if (cntj[jj] == N)continue;
//							cost++;
//						}
//					}
//					chmin(ans, cost);
//				}
//			}
//		}
//		return ans;
//	}
//}
//
////愚直解との比較
//template<class F>
//void diff(F f1, F f2) {
//	//f1, f2 の引数として考えられるものを全て（一部）比較
//	for (int mask = 0; mask < (1 << N*N); mask++) {
//		//引数生成
//		vector<vector<char>> v(N, vector<char>(N, 0));
//		rep(i, 0, N*N)v[i / N][i % N] = ((mask >> i) & 1) ? '#' : '.';
//
//		auto res1 = f1(v), res2 = f2(v);
//		dump(res1, res2);
//		assert(res1 == res2);
//	}
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> N;
//	vector<vector<char>> v(N, vector<char>(N, 0));
//	rep(i, 0, N) rep(j, 0, N) { cin >> v[i][j]; }
//	cout << f1(v) << endl;
//	return 0;
//}