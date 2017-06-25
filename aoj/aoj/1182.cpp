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
	using T = tuple<int, int, int>;
	for (int N, M, C, s, g; cin >> N >> M >> C >> s >> g&&N;) {
		static int dist[21][101][101], p[21], q[21][51], r[21][51];
		static int fare[21][20001], cost[101][101];
		s--; g--;
		memset(dist, 0x3f, sizeof(dist));
		memset(cost, 0x3f, sizeof(cost));
		rep(i, 0, M) {
			int x, y, d, c;
			cin >> x >> y >> d >> c;
			x--; y--; c--;
			chmin(dist[c][x][y], d);
			chmin(dist[c][y][x], d);
		}
		rep(c, 0, C)
			cin >> p[c];
		rep(c, 0, C) {
			rep(i, 0, p[c] - 1)
				cin >> q[c][i];
			rep(i, 0, p[c])
				cin >> r[c][i];
		}
		rep(c, 0, C)rep(k, 0, N)rep(i, 0, N)rep(j, 0, N)
			chmin(dist[c][i][j], dist[c][i][k] + dist[c][k][j]);
		rep(c, 0, C) {
			int idx = 0;
			fare[c][0] = 0;
			rep(i, 0, 20000) {
				if (idx < p[c] - 1 && i == q[c][idx]) idx++;
				fare[c][i + 1] = fare[c][i] + r[c][idx];
			}
		}
		rep(c, 0, C)rep(i, 0, N)rep(j, 0, N)
			if (dist[c][i][j] < INF)
				chmin(cost[i][j], fare[c][dist[c][i][j]]);
		rep(k, 0, N)rep(i, 0, N)rep(j, 0, N)
			chmin(cost[i][j], cost[i][k] + cost[k][j]);
		cout << (cost[s][g] == INF ? -1 : cost[s][g]) << endl;
	}
	return 0;
}