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
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void add_arc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void add_edge(Graph &g, int a, int b, Weight w = 1) {
	add_arc(g, a, b, w);
	add_arc(g, b, a, w);
}

Graph reverse(const Graph &g) {
	Graph rg(g.size());
	for (auto &es : g)
		for (auto &e : es)
			rg[e.d].emplace_back(e.d, e.s, e.w);
	return rg;
}

vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> cc(n, -1);
	vector<int> post;
	function<void(int, int)> dfs_cc = [&](int u, int cc_id) {
		if (cc[u] != -1)return;
		cc[u] = cc_id;
		for (auto &e : g[u])
			dfs_cc(e.d, cc_id);
		post.emplace_back(u);
	};
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, u);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, u, cc[u]);
	return scc;
}

bool detect_cycle(const vector<int> &idx) {
	int n = idx.size();
	vector<bool> f(n);
	for (auto &u : idx) {
		if (f[u])return true;
		f[u] = true;
	}
	return false;
}

//最小全域有向木 (minimum spanning arborescence)
//Chu-Liu/Edmonds' algorithm
Weight edmonds(const Graph &g, int root) {
	//辺を逆に張ったグラフで考えると都合がいい
	int n = g.size();
	Weight total = 0;
	Graph rg = reverse(g);
	Graph rmsa;
	while (true) {
		rmsa.assign(n, Edges());
		//頂点 u から出ている最小コスト辺を採用
		Edges minout(n);
		for (int u = 0; u < n; u++) {
			if (u == root)continue;
			if (!rg[u].size())continue;
			minout[u] = *min_element(rg[u].begin(), rg[u].end());
			rmsa[u].emplace_back(minout[u]);
		}
		//閉路がなければ最小全域有向木
		vector<int> idx = kosaraju(rmsa);
		if (!detect_cycle(idx))
			break;
		vector<int> cycle_count(n);
		Array cycle_cost(n);
		for (int u = 0; u < n; u++) {
			if (u == root)continue;
			if (!rmsa[u].size())continue;
			Edge &e = rmsa[u].front();
			if (idx[e.d] == idx[e.s]) {
				cycle_cost[idx[e.d]] += e.w;
				cycle_count[idx[u]]++;
			}
		}
		//閉路のコストを加算
		for (int i = 0; i < n; i++)
			if (cycle_count[i] >= 2)
				total += cycle_cost[i];
		//閉路を縮約 閉路の代表頂点に辺を張り直す
		rmsa.assign(n, Edges());
		for (auto &es : rg)
			for (auto &e : es) {
				if (idx[e.s] == idx[e.d])continue;
				//s から出ている辺のコストを再計算
				if (cycle_count[idx[e.s]] >= 2)
					e.w -= minout[e.s].w;
				rmsa[idx[e.s]].emplace_back(idx[e.s], idx[e.d], e.w);
			}
		rg = rmsa;
	}
	for (auto &es : rmsa)
		for (auto &e : es)
			total += e.w;
	return total;
}
//https://en.wikipedia.org/wiki/Edmonds%27_algorithm

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int V, E, r; cin >> V >> E >> r;
	Graph g(V);
	rep(i, 0, E) {
		int s, t, w; cin >> s >> t >> w;
		add_arc(g, s, t, w);
	}
	cout << edmonds(g, r) << endl;
	return 0;
}