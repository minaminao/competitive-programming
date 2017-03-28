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


struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
};

//最小全域木 (Minimum Spanning Tree)
//Prim O(|E|log|V|)
//root から到達可能な頂点が対象
pair<Weight, Edges> prim(const Graph &g, int root = 0) {
	int n = g.size();
	Edges mst;
	Weight total = 0;
	vector<bool> v(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.emplace(-1, root, 0);
	while (pq.size()) {
		Edge e = pq.top(); pq.pop();
		if (v[e.d])continue;
		v[e.d] = true;
		total += e.w;
		if (e.s != -1)mst.emplace_back(e);
		for (auto &f : g[e.d])
			if (!v[f.d])
				pq.emplace(f);
	}
	return make_pair(total, mst);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	Graph g(V);
	rep(i, 0, E) {
		int s, t, w; cin >> s >> t >> w;
		add_edge(g, s, t, w);
	}
	auto res = prim(g);
	cout << res.first << endl;
	return 0;
}