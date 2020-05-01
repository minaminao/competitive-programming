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
	for (int n, m; cin >> n >> m&&n;) {
		int s, g; cin >> s >> g;
		vector<vector<double>> D(n + 1, vector<double>(n + 1, INF));
		vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
		rep(i, 0, m) {
			int x, y, d, c; cin >> x >> y >> d >> c;
			D[x][y] = D[y][x] = d;
			C[x][y] = C[y][x] = c;
		}
		static double dp[33][33][33];
		rep(i, 0, 33)rep(j, 0, 33)rep(k, 0, 33)dp[i][j][k] = INF;
		using T = tuple<int, int, int>;
		queue<T> q;
		dp[s][0][0] = 0;
		q.emplace(s, 0, 0);
		while (q.size()) {
			int cur, prev, e;
			tie(cur, prev, e) = q.front(); q.pop();
			rep(next, 1, n + 1) {
				if (next == prev)continue;
				if (C[cur][next] == 0)continue;
				rep(k, e - 1, e + 2) {
					if (k <= 0)continue;
					if (C[cur][next] < k)continue;
					if (chmin(dp[next][cur][k], dp[cur][prev][e] + D[cur][next] / k))
						q.emplace(next, cur, k);
				}
			}
		}
		double ans = INF;
		rep(i, 1, n + 1) {
			if (chmin(ans, dp[g][i][1]))dump(ans);
		}
		cout << fixed << setprecision(10);
		if (ans == INF) {
			cout << "unreachable" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}