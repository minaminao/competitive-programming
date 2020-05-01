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

//辺を逆に張ったグラフ
Graph reverse(const Graph &g) {
	Graph rg(g.size());
	for (auto &es : g)
		for (auto &e : es)
			rg[e.d].emplace_back(e.d, e.s, e.w);
	return rg;
}

//強連結成分分解
//ret[u] = u が属している強連結成分のインデックス
vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> in(n, -1);
	vector<int> post;
	function<void(int, int)> dfs = [&](int u, int idx) {
		if (in[u] != -1)return;
		in[u] = idx;
		for (auto &e : g[u]) {
			if (in[e.d] != -1)continue;
			dfs(e.d, idx);
		}
		post.emplace_back(u);
	};
	int idx = 0;
	for (int u = 0; u < n; u++) {
		if (in[u] == -1) {
			dfs(u, idx++);
		}
	}
	vector<int> in2(n, -1);
	function<void(int, int, int)> dfs2 = [&](int u, int idx, int idx2) {
		if (in2[u] != -1)return;
		if (in[u] != idx)return;
		in2[u] = idx2;
		for (auto &e : rg[u]) {
			if (in2[e.d] != -1)continue;
			if (in[e.d] != idx)continue;
			dfs2(e.d, idx, idx2);
		}
	};
	int idx2 = 0;
	reverse(post.begin(), post.end());
	for (auto &u : post) {
		if (in2[u] == -1) {
			dfs2(u, in[u], idx2++);
		}
	}
	return in2;
}

bool cycle_detection(const Graph &g) {
	vector<int> res = kosaraju(g);
	return find(all(res), g.size() - 1) == res.end();
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	Graph g(V);
	rep(i, 0, E) {
		int s, t; cin >> s >> t;
		add_arc(g, s, t);
	}
	cout << cycle_detection(g) << endl;
	return 0;
}