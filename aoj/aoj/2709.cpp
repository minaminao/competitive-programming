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
//int dp[2 << 16];
//bool flag[2 << 16];
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, M, K; cin >> N >> M >> K;
//	vector<int> dark(N, -1);
//	vector<int> D(M); rep(i, 0, M) {
//		cin >> D[i];
//		D[i]--;
//		dark[D[i]] = i;
//	}
//	dump(dark);
//	vector<vector<int>> v(N, vector<int>(K));
//	rep(i, 0, N) rep(j, 0, K) { cin >> v[i][j]; v[i][j]--; }
//
//	memset(dp, 0x3f, sizeof(dp));
//	dp[0] = 0;
//
//	rep(k, 0, K) {
//		int t = 0;
//		if (dark[v[D[12]][k]] == -1)continue;
//		t |= 1 << dark[v[D[12]][k]];
//		dump(t);
//		dump(v[D[12]][k], dark[v[D[12]][k]], 1 << dark[v[D[12]][k]]);
//	}
//
//	function<int(int)> f = [&](int mask) {
//		if (flag[mask])return INF;
//		if (dp[mask] != INF)return dp[mask];
//		flag[mask] = true;
//		int ret = INF;
//		rep(k, 0, K) {
//			int t = 0;
//			rep(i, 0, M) {
//				if ((mask >> i) & 1) {
//					if (dark[v[D[i]][k]] != -1) {
//						t |= 1 << dark[v[D[i]][k]];
//					}
//				}
//			}
//			chmin(ret, f(t) + 1);
//		}
//		dump(bitset<16>(mask), ret);
//		return dp[mask] = ret;
//	};
//
//	dump(v[12]);
//	dump(bitset<16>((1 << 12) + 2));
//	cout << f((1 << 12)) << endl;
//	rep(i, 0, 2 << 16) {
//		if (dp[i] <= 48)
//			dump(bitset<16>(i), dp[i]);
//	}
//
//	return 0;
//}