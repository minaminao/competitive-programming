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
//	int N; cin >> N;
//	vector<int> f(N), a(N), t(N), x(N), y(N); rep(i, 0, N) { cin >> f[i] >> a[i] >> t[i] >> x[i] >> y[i]; }
//	double a0, a1, t0, t1;
//	a0 = a1 = t0 = t1 = 0;
//	rep(i, 0, N - 1) {
//		if (t[i] != t[i + 1])continue;
//		if (a[i] == a[i + 1])continue;
//		double dx = abs(x[i + 1] - x[i]), dy = abs(y[i + 1] - y[i]), df = f[i + 1] - f[i];
//		if (a[i] == 0) {
//			if (chmax(a0, sqrt(dx*dx + dy*dy)))t0 = ;
//		}
//		else {
//			chmax(a1, sqrt(dx*dx + dy*dy));
//		}
//	}
//	return 0;
//}