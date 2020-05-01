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

//–¢’Tõ, ’Tõ’†, ’TõÏ
enum { WHITE, GRAY, BLACK };

//lowest common ancestor (ƒ_ƒuƒŠƒ“ƒO + dfs”ñÄ‹A)
//\’zO(NlogN) ƒNƒGƒŠO(logN)
struct LowestCommonAncestor {
	const Graph &g;
	const int root, n, log2_n;
	vector<vector<int>> parent;
	vector<int> depth;
	LowestCommonAncestor(const Graph &g, int root)
		:g(g), root(root), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)), depth(n) {
		dfs();
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < n; v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
	void dfs() {
		using State = tuple<int, int, int>;
		stack<State> st; st.emplace(root, -1, 0);
		while (st.size()) {
			int s, p, d; tie(s, p, d) = st.top(); st.pop();
			parent[0][s] = p;
			depth[s] = d;
			for (auto &e : g[s]) {
				if (e.d == p)continue;
				st.emplace(e.d, s, d + 1);
			}
		}
	}
	int get(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	Graph g(N);
	rep(i, 0, N - 1) {
		int x, y; cin >> x >> y; x--, y--;
		add_edge(g, x, y);
	}
	LowestCommonAncestor lca(g, 0);
	int Q; cin >> Q;
	rep(i, 0, Q) {
		int a, b; cin >> a >> b; a--, b--;
		int an = lca.get(a, b);
		cout << lca.depth[a] + lca.depth[b] - 2 * lca.depth[an] + 1 << endl;
	}
	return 0;
}