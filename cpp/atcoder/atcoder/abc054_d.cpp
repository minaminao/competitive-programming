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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	int N, Ma, Mb; cin >> N >> Ma >> Mb;
	vector<int> a(N), b(N), c(N); rep(i, 0, N) { cin >> a[i] >> b[i] >> c[i]; }
	static int dp[410][410] = {};
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	rep(i, 0, N) {
		rrep(j, 0, 410 - a[i]) {
			rrep(k, 0, 410 - b[i]) {
				if (dp[j][k] == INF)continue;
				chmin(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
			}
		}
	}
	int ans = INF;
	rep(ma, 1, 410)rep(mb, 1, 410) {
		if (ma*Mb != Ma*mb)continue;
		chmin(ans, dp[ma][mb]);
	}
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}