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
//	int N; cin >> N;
//	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
//	vector<int> c = { 0 };
//	rep(i, 0, N - 1) {
//		if (v[i] == v[i + 1]) {
//			c.emplace_back(i + 1);
//		}
//	}
//	dump(c);
//	c.emplace_back(N);
//	if (c.size() <= 3) {
//		cout << N << endl;
//	}
//	else {
//		int ans = 0;
//		rep(i, 0, c.size() - 3) {
//			chmax(ans, c[i + 3] - c[i]);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}