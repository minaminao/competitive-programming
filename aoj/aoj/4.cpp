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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
	bool operator<(const Edge &e)const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int s, int d, Weight w = 1) { g[s].emplace_back(s, d, w); }

//未探索, 探索中, 探索済
enum { WHITE, GRAY, BLACK };

//単一始点最短経路(負閉路なし)
//Dijkstra O((E+V)logV)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
vector<int> dijkstra(const Graph &g, int s, vector<Weight> &dist) {
	int n = g.size();
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //distが最小となるStateを取り出す
		if (dist[v] < d)continue; //すでに最短でなければ無視
		color[v] = BLACK; prev[v] = u;
		for (auto &e : g[v]) {
			if (color[e.d] == BLACK)continue;
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				pq.emplace(dist[e.d], e.d, v);
				color[e.d] = GRAY;
			}
		}
	}
	return prev;
}

//全点対間最短経路 
void all_pairs_shortest_paths_by_dijkstra(const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int N, M; cin >> N >> M&&N;) {
		Graph l(N), s(N);
		rep(i, 0, M) {
			int x, y, t; cin >> x >> y >> t; x--, y--;
			char c; cin >> c;
			if (c == 'L')add_edge(l, x, y, t);
			else add_edge(s, x, y, t);
		}
		int R; cin >> R;
		vector<int> z(R); rep(i, 0, R) { cin >> z[i]; z[i]--; }
		Matrix distsl, distss;
		all_pairs_shortest_paths_by_dijkstra(l, distsl);
		all_pairs_shortest_paths_by_dijkstra(s, distss);
		Matrix dp(R, Array(N, INF));
		rep(j, 0, N) {
			if (distsl[j][z[0]] == INF || distss[z[0]][j] == INF)continue;
			dp[0][j] = distsl[j][z[0]] + distss[z[0]][j];
			dump(j, dp[0][j]);
		}
		rep(i, 1, R) {
			rep(j, 0, N) {
				if (dp[i - 1][j] == INF)continue;
				if (distsl[j][z[i]] == INF || distss[z[i]][j] == INF)continue;
				dp[i][j] = dp[i - 1][j] + distsl[j][z[i]] + distss[z[i]][j];
				dump(i, j, dp[i][j]);
			}
		}
		int ans = INF;
		dump(dp);
		rep(i, 0, N) {
			chmin(ans, dp[R - 1][i]);
		}
		cout << ans << endl;
	}
	return 0;
}