#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int dp[15][2][15] = {};
	string S; cin >> S;
	dp[0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 14) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			dp[i + 1][j || d < lim][k + (d == 1)] += dp[i][j][k];
		}
	}
	int ans = 0;
	rep(k, 1, 15) {
		ans += (dp[S.size()][0][k] + dp[S.size()][1][k])*k;
	}
	cout << ans << endl;
	return 0;
}