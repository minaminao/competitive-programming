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

int dp[55][10010] = {};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int W; cin >> W;
	int N, K; cin >> N >> K;
	vector<int> A(N), B(N); rep(i, 0, N) { cin >> A[i] >> B[i]; }
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	rep(i, 0, N) {
		rrep(k, 0, K) {
			rrep(j, 0, W) {
				if (j + A[i] > W)continue;
				if (dp[k][j] == -1)continue;
				chmax(dp[k + 1][j + A[i]], dp[k][j] + B[i]);
			}
		}
	}
	int ans = 0;
	rep(i, 0, K + 1)rep(j, 0, W + 1) {
		chmax(ans, dp[i][j]);
		dump(i, j, dp[i][j]);
	}
	cout << ans << endl;
	return 0;
}