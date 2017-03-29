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

//巡回セールスマン問題
//ある頂点から出発し各頂点をちょうど1回通り出発点へ戻る最短閉路
void traveling_salesman_problem() {
	static const int MAX_V = 15;
	static int dp[1 << MAX_V][MAX_V];
	static int g[MAX_V][MAX_V];
	memset(dp, 0x3f, sizeof(dp));
	memset(g, 0x3f, sizeof(dp));
	int V, E; cin >> V >> E;
	rep(i, 0, E) {
		int s, t, d; cin >> s >> t >> d;
		g[s][t] = d;
	}
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << V); mask++) {
		rep(i, 0, V) {
			rep(j, 0, V) {
				if (mask >> j & 1)continue;
				if (dp[mask][i] == INF || g[i][j] == INF)continue;
				chmin(dp[mask | (1 << j)][j], dp[mask][i] + g[i][j]);
			}
		}
	}
	cout << (dp[(1 << V) - 1][0] == INF ? -1 : dp[(1 << V) - 1][0]) << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	traveling_salesman_problem();
	return 0;
}