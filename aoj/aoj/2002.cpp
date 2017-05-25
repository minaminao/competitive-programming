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

const int N = 51;
char c[N][N];
int imin[128], imax[128], jmin[128], jmax[128];
bool f[128];

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

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
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
	int count_cc = 0;
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, count_cc++);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	int count_scc = 0;
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, count_scc++, cc[u]);
	return scc;
}

bool detectCycle(const Graph &g) {
	vector<int> idx = kosaraju(g);
	return find(all(idx), idx.size() - 1) == idx.end();
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	rep(i, 0, N) {
		int H, W; cin >> H >> W;
		memset(c, 0, sizeof(c));
		memset(imin, 0x3f, sizeof(imin));
		memset(jmin, 0x3f, sizeof(jmin));
		memset(imax, -1, sizeof(imax));
		memset(jmax, -1, sizeof(jmax));
		memset(f, 0, sizeof(f));
		rep(i, 0, H)rep(j, 0, W) {
			cin >> c[i][j];
			chmin(imin[c[i][j]], i);
			chmax(imax[c[i][j]], i);
			chmin(jmin[c[i][j]], j);
			chmax(jmax[c[i][j]], j);
			f[c[i][j]] = true;
		}
		bool safe = true;
		Graph g(128);
		rep(k, 'A', 'Z' + 1) {
			if (!f[k])continue;
			rep(i, imin[k], imax[k] + 1) {
				rep(j, jmin[k], jmax[k] + 1) {
					if (c[i][j] == '.') {
						safe = false;
					}
					else if (c[i][j] != k) {
						addArc(g, k, c[i][j]);
					}
				}
			}
		}
		if (detectCycle(g))safe = false;
		cout << (safe ? "SAFE" : "SUSPICIOUS") << endl;
	}
	return 0;
}