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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

int dp[55][55] = {};
int dp2[55][55] = {};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	int N, A, B; cin >> N >> A >> B;
	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
	dp[0][0] = 0;
	dp2[0][0] = 1;
	rep(i, 0, N)rep(j, 0, 51) {
		if (dp[i + 1][j + 1] == dp[i][j] + v[i]) {
			dp2[i + 1][j + 1] += dp2[i][j];
		}
		else if (chmax(dp[i + 1][j + 1], dp[i][j] + v[i])) {
			dp2[i + 1][j + 1] = dp2[i][j];
		}
		if (dp[i + 1][j] == dp[i][j]) {
			dp2[i + 1][j] += dp2[i][j];
		}
		else if (chmax(dp[i + 1][j], dp[i][j])) {
			dp2[i + 1][j] = dp2[i][j];
		}
	}
	int ans = dp[N][A], ans_n = A, ans2 = dp2[N][A];
	rep(i, A + 1, B + 1) {
		dump(ans, ans_n, ans2);
		if (ans*i == dp[N][i] * ans_n) {
			ans2 += dp2[N][i];
		}
		else if (ans*i < dp[N][i] * ans_n) {
			ans = dp[N][i];
			ans_n = i;
			ans2 = dp2[N][i];
		}
	}
	cout << (double)ans / ans_n << endl;
	cout << ans2 << endl;
	return 0;
}