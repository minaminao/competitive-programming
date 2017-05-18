//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//using Weight = int;
//using Flow = int;
//struct Edge {
//	int s, d; Weight w; Flow c;
//	Edge() {};
//	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
//};
//bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
//bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
//inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }
//
//using Edges = vector<Edge>;
//using Graph = vector<Edges>;
//using Array = vector<Weight>;
//using Matrix = vector<Array>;
//
//void add_arc(Graph &g, int s, int d, Weight w = 1) {
//	g[s].emplace_back(s, d, w);
//}
//void add_edge(Graph &g, int a, int b, Weight w = 1) {
//	add_arc(g, a, b, w);
//	add_arc(g, b, a, w);
//}
//
//pair<vector<int>, bool> bellmanFord(const Graph &g, int s, Array &dist) {
//	int n = g.size();
//	vector<int> prev(n, -1);
//	Edges es; for (int i = 0; i < n; i++) for (auto &e : g[i]) es.emplace_back(e);
//	dist.assign(n, INF); dist[s] = 0;
//	bool negative_cycle = false;
//	for (int i = 0;; i++) {
//		bool update = false;
//		for (auto &e : es) {
//			if (dist[e.s] != INF && dist[e.d] > dist[e.s] + e.w) {
//				dist[e.d] = dist[e.s] + e.w;
//				prev[e.d] = e.s;
//				update = true;
//			}
//		}
//		if (!update) break;
//		if (i > n) { negative_cycle = true; break; }
//	}
//	return make_pair(prev, !negative_cycle);
//}
//
////•Ó‚ð‹t‚É’£‚Á‚½ƒOƒ‰ƒt
//Graph reverse(const Graph &g) {
//	Graph rg(g.size());
//	for (auto &es : g)
//		for (auto &e : es)
//			rg[e.d].emplace_back(e.d, e.s, e.w);
//	return rg;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, M; cin >> N >> M;
//	Graph g(N);
//	rep(i, 0, M) {
//		int a, b, c; cin >> a >> b >> c;
//		a--, b--;
//		add_arc(g, a, b, -c);
//	}
//	Array dist1, dist2;
//	auto res1 = bellmanFord(g, 0, dist1);
//	Graph rg = reverse(g);
//	auto res2 = bellmanFord(rg, N - 1, dist2);
//	if (!res1.second && !res2.second) {
//		cout << "inf" << endl;
//	}
//	else {
//		cout << -dist1[N - 1] << endl;
//	}
//	return 0;
//}