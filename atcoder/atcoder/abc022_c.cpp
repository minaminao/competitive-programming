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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

using Weight = int;
struct Edge {
	int s, d; Weight w;
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w) {};
	bool operator<(const Edge &e)const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

//–¢’Tõ, ’Tõ’†, ’TõÏ
enum { WHITE, GRAY, BLACK };

//’Pˆên“_Å’ZŒo˜H(•‰•Â˜H‚È‚µ)
//Dijkstra O((E+V)logV)
//dist: n“_‚©‚çŠe’¸“_‚Ü‚Å‚ÌÅ’Z‹——£
//–ß‚è’l: Å’ZŒo˜H–Ø‚Ìe’¸“_(ª‚Í-1)
vector<int> dijkstra(const Graph &g, int s, Array &dist) {
	int n = g.size();
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //n“_‚©‚ç‚ÌÅ’Z‹——£ q e
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //dist‚ªÅ¬‚Æ‚È‚éState‚ğæ‚èo‚·
		if (dist[v] < d)continue; //‚·‚Å‚ÉÅ’Z‚Å‚È‚¯‚ê‚Î–³‹
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

void all_pairs_shortest_paths_by_dijkstra(const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
}

ostream &operator<<(ostream &os, const Edge &e) {
	return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')');
}

signed main() {
	int N, M; cin >> N >> M;
	vector<int> u(M), v(M), l(M); rep(i, 0, M) { cin >> u[i] >> v[i] >> l[i]; u[i]--, v[i]--; }

	Graph g(N);
	vector<Edge> es;
	rep(i, 0, M) {
		if (u[i] == 0)
			es.emplace_back(u[i], v[i], l[i]);
		else if (v[i] == 0)
			es.emplace_back(v[i], u[i], l[i]);
		else {
			g[u[i]].emplace_back(u[i], v[i], l[i]);
			g[v[i]].emplace_back(v[i], u[i], l[i]);
		}
	}
	dump(es);

	Matrix dists;
	all_pairs_shortest_paths_by_dijkstra(g, dists);

	Weight ans = INF;
	rep(i, 0, es.size())rep(j, i + 1, es.size())
		chmin(ans, dists[es[i].d][es[j].d] + es[i].w + es[j].w);

	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}