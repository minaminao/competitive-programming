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

int dp[10010] = {};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, W; cin >> N >> W;
	vector<int> v(N), w(N); rep(i, 0, N) { cin >> v[i] >> w[i]; }
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	rep(i, 0, N) {
		rrep(j, 0, 10001) {
			if (dp[j] == INF)continue;
			chmin(dp[j + v[i]], dp[j] + w[i]);
		}
	}
	rrep(i, 0, 10001) {
		if (dp[i] != INF&&dp[i] <= W) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}