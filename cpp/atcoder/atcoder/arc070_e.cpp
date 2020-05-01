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
//#define MAX 410
//int dp[MAX][MAX] = {};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	assert(N <= 500);
//	vector<int> l(N), r(N); rep(i, 0, N) { cin >> l[i] >> r[i]; }
//	memset(dp, 0x3f, sizeof(dp));
//	rep(i, 0, MAX - (r[0] - l[0])) {
//		dp[0][i] = abs(i - l[0]);
//	}
//	rep(i, 0, N - 1) {
//		rep(j, 0, MAX - (r[i + 1] - l[i + 1])) {
//			rep(k, max(0, j - (r[i] - l[i])), r[i + 1] - l[i + 1] + j + 1) {
//				chmin(dp[i + 1][j], dp[i][k] + abs(j - l[i + 1]));
//			}
//		}
//		dump(dp[i]);
//	}
//	dump(dp[N - 1]);
//	cout << *min_element(all(dp[N - 1])) << endl;
//	return 0;
//}