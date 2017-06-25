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

using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c; int r;
	Edge() {};
	Edge(int s, int d, int r, Weight w = 1) : s(s), d(d), w(w), c(w), r(r) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	using T = tuple<int, int, int, int>;
	for (int n, m, c, s, g; cin >> n >> m >> c >> s >> g&&n;) {
		static int dp[101][21][10010];
		static int p[21], q[21][51], r[21][51];
		memset(dp, 0x3f, sizeof(dp));
		queue<T> Q;
		s--, g--;
		Q.emplace(s, 0, 0, 0);
		dp[s][0][0] = 0;
		Graph G(n);
		rep(i, 0, m) {
			int x, y, d, c; cin >> x >> y >> d >> c;
			x--, y--; c--;
			G[x].emplace_back(x, y, c, d);
			G[y].emplace_back(y, x, c, d);
		}
		rep(i, 0, c) {
			cin >> p[i];
		}
		int maxi = 0;
		rep(i, 0, c) {
			q[i][0] = 0;
			rep(j, 0, p[i] - 1) {
				int t; cin >> t;
				q[i][j + 1] = t;
				chmax(maxi, t);
			}
			q[i][p[i]] = INF;
			rep(j, 0, p[i]) {
				int t; cin >> t;
				r[i][j] = t;
			}
		}
		function<int(int, int, int)> cost = [&](int sum, int w, int c) {
			int ret = 0;
			//dump(sum, w, c);
			rep(i, 0, p[c]) {
				//dump(r[c].size(), i, q[c].size(), i + 1);
				//dump(q[c][i]);
				//dump(q[c][i + 1]);
				//dump(r[c][i]);
				if (sum >= q[c][i + 1])
					ret -= (q[c][i + 1] - q[c][i])*r[c][i];
				else {
					ret -= (sum - q[c][i])*r[c][i];
					break;
				}
			}
			//if (sum == 2 && w == 2 && c == 0)
			//  dump(ret);
			rep(i, 0, p[c]) {
				//dump(r[c].size(), i, q[c].size(), i + 1);
				//dump(q[c][i]);
				//dump(q[c][i + 1]);
				//dump(r[c][i]);
				if (sum + w >= q[c][i + 1])
					ret += (q[c][i + 1] - q[c][i])*r[c][i];
				else {
					//if (sum == 2 && w == 2 && c == 0)
					//  dump(ret);
					ret += (sum + w - q[c][i])*r[c][i];
					//if (sum == 2 && w == 2 && c == 0)
					//  dump(ret);
					break;
				}
			}
			assert(ret >= 0);
			return ret;
		};
		while (Q.size()) {
			int cx, cc, sum, fare;
			tie(cx, cc, sum, fare) = Q.front(); Q.pop();
			if (fare != dp[cx][cc][sum])
				continue;
			for (auto &e : G[cx]) {
				if (e.r == cc && chmin(dp[e.d][cc][min(maxi, sum + e.w)],
					dp[cx][cc][sum] + cost(sum, e.w, cc))) {
					Q.emplace(e.d, cc, min(maxi, sum + e.w), dp[e.d][cc][min(maxi, sum + e.w)]);
				}
				if (e.r != cc && chmin(dp[e.d][e.r][min(maxi, e.w)],
					dp[cx][cc][sum] + cost(0, e.w, e.r))) {
					Q.emplace(e.d, e.r, min(maxi, e.w), dp[e.d][e.r][min(maxi, e.w)]);
				}
			}
		}
		int ans = INF;
		rep(i, 0, c)rep(j, 0, maxi + 1) {
			chmin(ans, dp[g][i][j]);
			//if (dp[g][i][j] != INF)
			//  dump(i, j, dp[g][i][j]);
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
	return 0;
}