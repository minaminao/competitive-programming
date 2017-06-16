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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int T; cin >> T;
//	rep(t, 0, T) {
//		int N; cin >> N;
//		vector<int> par1(N, -1), par2(N, -1);
//		rep(i, 0, N - 1) {
//			int u, v; cin >> u >> v; u--, v--;
//			par1[v] = u;
//		}
//		rep(i, 0, N - 1) {
//			int u, v; cin >> u >> v; u--, v--;
//			par2[v] = u;
//		}
//		vector<int> cnt(N, -1);
//		cnt[0] = 0;
//		function<int(int)> f = [&](int x) {
//			if (cnt[x] != -1)return cnt[x];
//			unordered_set<int> st;
//			for (int u1 = x, u2 = x;;) {
//				if (par1[u1] != -1) {
//					if (st.count(par1[u1])) {
//						return cnt[x] = f(par1[u1]) + 1;
//					}
//					else {
//						st.insert(par1[u1]);
//						u1 = par1[u1];
//					}
//				}
//				if (par2[u2] != -1) {
//					if (st.count(par2[u2])) {
//						return cnt[x] = f(par2[u2]) + 1;
//					}
//					else {
//						st.insert(par2[u2]);
//						u2 = par2[u2];
//					}
//				}
//			}
//		};
//		rep(i, 0, N - 1) { cout << f(i) << " "; }
//		cout << f(N - 1) << endl;
//	}
//	return 0;
//}