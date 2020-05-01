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
	for (int w, h; cin >> w >> h&&w;) {
		static char c[21][21];
		int n = 1;
		static int pi[11], pj[11];
		rep(i, 0, h)rep(j, 0, w) {
			cin >> c[i][j];
			if (c[i][j] == '*') {
				pi[n] = i;
				pj[n] = j;
				n++;
			}
			else if (c[i][j] == 'o')
				pi[0] = i, pj[0] = j;
		}
		static const int di[] = { 1,0,-1,0 };
		static const int dj[] = { 0,1,0,-1 };
		static int d[11][21][21];
		memset(d, 0x3f, sizeof(d));
		rep(i, 0, n) {
			d[i][pi[i]][pj[i]] = 0;
		}
		auto inrange = [&](int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; };
		rep(k, 0, n) {
			using P = pair<int, int>;
			queue<P> q;
			q.push(P(pi[k], pj[k]));
			for (int ci, cj; !q.empty();) {
				tie(ci, cj) = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int ni = ci + di[i], nj = cj + dj[i];
					if (!inrange(ni, nj))continue;
					if (c[ni][nj] == 'x')continue;
					if (d[k][ni][nj] != INF)continue;
					d[k][ni][nj] = d[k][ci][cj] + 1;
					q.emplace(ni, nj);
				}
			}
		}
		static int dp[1 << 11][11];
		memset(dp, 0x3f, sizeof(dp));
		dp[1][0] = 0;
		dump(n);
		for (int mask = 0; mask < (1 << n); mask++) {
			rep(i, 0, n) {
				rep(j, 0, n) {
					if (mask >> j & 1)continue;
					if (dp[mask][i] == INF || d[i][pi[j]][pj[j]] == INF)continue;
					dump(mask);
					chmin(dp[mask | (1 << j)][j], dp[mask][i] + d[i][pi[j]][pj[j]]);
				}
			}
		}
		int ans = INF;
		rep(i, 0, n)
			chmin(ans, dp[(1 << n) - 1][i]);
		cout << (ans == INF ? -1 : ans) << endl;
	}
	return 0;
}