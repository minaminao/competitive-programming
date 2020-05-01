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
//double f(int a, int b) {
//	int d = abs(a - b);
//	return sqrt(d*d + 1 * 1);
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	int s, g; cin >> s >> g;
//	static double dp[200010][2];
//	vector<int> l(N), r(N); rep(i, 0, N) {
//		cin >> l[i] >> r[i];
//	}
//	rep(i, 0, N - 1) {
//		dp[i + 1][0] = min(
//			dp[i][0] + f(l[i], l[i + 1]),
//			dp[i][1] + f(r[i], l[i + 1])
//		);
//		dp[i + 1][1] = min(
//			dp[i][0] + f(l[i], r[i + 1]),
//			dp[i][1] + f(r[i], r[i + 1])
//		);
//	}
//	cout << min(dp[N][0], dp[N][1]) << endl;
//	return 0;
//}