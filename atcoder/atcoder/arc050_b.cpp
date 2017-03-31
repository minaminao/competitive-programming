//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
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
//	int R, B; cin >> R >> B;
//	int x, y; cin >> x >> y;
//	int Q = (B*x - R) / (x*y - 1) + 100000;
//	int ans = 0;
//	rep(i, 0, 100000) {
//		int r = R, b = B;
//		int q = Q - i;
//		r -= q;
//		b -= q*y;
//		if (r < 0 || b < 0)continue;
//		int p = min(r / x, b);
//		chmax(ans, p + q);
//	}
//	cout << ans << endl;
//	return 0;
//}