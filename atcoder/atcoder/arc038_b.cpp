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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W; cin >> H >> W;
	vector<vector<char>> v(H, vector<char>(W));
	rep(i, 0, H) rep(j, 0, W) { cin >> v[i][j]; }
	vector<vector<int>> dp(H, vector<int>(W, -1));
	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	// win: 1 lose: 0
	function<int(int, int)> dfs = [&](int ci, int cj) {
		if (dp[ci][cj] != -1)return dp[ci][cj];
		int next = INF;
		rep(di, 0, 2)rep(dj, 0, 2) {
			if (di == 0 && dj == 0)continue;
			int ni = ci + di, nj = cj + dj;
			if (!inrange(ni, nj))continue;
			if (v[ni][nj] == '#')continue;
			chmin(next, dfs(ni, nj));
		}
		int ret;
		if (next == INF) {
			ret = 0;
		}
		else if (next == 0) {
			ret = 1;
		}
		else {
			ret = 0;
		}
		return dp[ci][cj] = ret;
	};
	if (dfs(0, 0)) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
	dump(dp);
	return 0;
}