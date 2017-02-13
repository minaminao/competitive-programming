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
//const int MOD = (int)(1e9 + 7);
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//int dp[2][5010];
//
//signed main() {
//	int N, L; cin >> N >> L;
//	vector<int> x(N); rep(i, 0, N) { cin >> x[i]; }
//	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
//
//	fill(dp[0], dp[0] + L, 1);
//	rep(i, 0, N) {
//		int curr = i & 1, next = !curr;
//		for (int j = x[i]; j < L; j += a[i]) {
//			if (j > 0) 
//				dp[next][j] += dp[curr][j - 1];
//			else 
//				dp[next][j] = dp[curr][j];
//			dp[next][j] %= MOD;
//			if (a[i] == 0) break;
//		}
//		rep(j, x[i], L) {
//			dp[next][j + 1] += dp[next][j];
//			dp[next][j + 1] %= MOD;
//		}
//		fill(dp[curr], dp[curr] + L, 0);
//	}
//	cout << dp[N & 1][L - 1] << endl;
//	return 0;
//}