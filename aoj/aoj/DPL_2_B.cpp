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

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}



//中国人郵便配達問題 O(V^2 2^V)
//無向グラフにおいて各辺を少なくとも1回通る最短閉路
int chinesePostman(const Graph &g) {
	static const int MAX_V = 17;
	Weight total = 0;
	int n = g.size();
	vector<int> odds;
	static Weight dist[MAX_V][MAX_V];
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, INF);
		for (auto &e : g[i]) {
			total += e.w;
			dist[e.s][e.d] = min(dist[e.s][e.d], e.w);
		}
		if (g[i].size() & 1)
			odds.push_back(i);
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	static Weight dp[1 << MAX_V];
	int k = odds.size();
	fill(dp, dp + (1 << k), INF);
	dp[0] = 0;
	for (int mask = 0; mask < 1 << k; mask++)
		for (int i = 0; i < k; i++)
			if (~mask >> i & 1)
				for (int j = 0; j < i; j++)
					if (~mask >> j & 1)
						dp[mask | 1 << i | 1 << j] = min(
							dp[mask | 1 << i | 1 << j],
							dp[mask] + dist[odds[i]][odds[j]]
						);
	return total / 2 + dp[(1 << k) - 1];
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int V, E; cin >> V >> E;
	Graph g(V);
	rep(i, 0, E) {
		int s, t, d; cin >> s >> t >> d;
		addEdge(g, s, t, d);
	}
	cout << chinesePostman(g) << endl;
	return 0;
}