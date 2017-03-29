#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

//Å‘å³•ûŒ`
void largest_square() {
	int H, W; cin >> H >> W;
	vector<vector<int>> dp(H + 1, vector<int>(W + 1));
	rep(i, 0, H) rep(j, 0, W) {
		int x; cin >> x;
		dp[i + 1][j + 1] = !x;
	}
	int ans = 0;
	rep(i, 1, H + 1)rep(j, 1, W + 1) {
		if (dp[i][j] == 0)continue;
		dp[i][j] = min({
			dp[i - 1][j],
			dp[i][j - 1],
			dp[i - 1][j - 1]
		}) + 1;
		chmax(ans, dp[i][j]);
	}
	cout << ans*ans << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	largest_square();
	return 0;
}