//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
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
//vector<int> dijkstra(const Graph &g, int s, Array &dist) {
//	int n = g.size();
//	assert(s < n);
//	enum { WHITE, GRAY, BLACK };
//	vector<int> color(n, WHITE); color[s] = GRAY;
//	vector<int> prev(n, -1);
//	dist.assign(n, INF); dist[s] = 0;
//	using State = tuple<Weight, int, int>; 
//	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
//	while (pq.size()) {
//		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
//		if (dist[v] < d)continue;
//		color[v] = BLACK; prev[v] = u;
//		for (auto &e : g[v]) {
//			if (color[e.d] == BLACK)continue;
//			if (dist[e.d] > dist[v] + e.w) {
//				dist[e.d] = dist[v] + e.w;
//				pq.emplace(dist[e.d], e.d, v);
//				color[e.d] = GRAY;
//			}
//		}
//	}
//	return prev;
//}
//
//Edge diameter(const Graph &g, int s = 0) {
//	Array dist;
//	dijkstra(g, s, dist);
//	int n = g.size(), u = -1, v = -1;
//	for (int i = 0; i < n; i++) if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
//	dijkstra(g, u, dist);
//	for (int i = 0; i < n; i++) if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
//	Weight d = dist[v];
//	if (u > v) swap(u, v);
//	return Edge(u, v, d);
//}
//
//vector<bool> er;
//vector<int> dijkstra2(const Graph &g, int s, Array &dist) {
//	int n = g.size();
//	assert(s < n);
//	enum { WHITE, GRAY, BLACK };
//	vector<int> color(n, WHITE); color[s] = GRAY;
//	vector<int> prev(n, -1);
//	dist.assign(n, INF); dist[s] = 0;
//	using State = tuple<Weight, int, int>; 
//	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
//	while (pq.size()) {
//		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
//		if (dist[v] < d)continue;
//		if (er[v])continue;
//		color[v] = BLACK; prev[v] = u;
//		for (auto &e : g[v]) {
//			if (color[e.d] == BLACK)continue;
//			if (dist[e.d] > dist[v] + e.w) {
//				dist[e.d] = dist[v] + e.w;
//				pq.emplace(dist[e.d], e.d, v);
//				color[e.d] = GRAY;
//			}
//		}
//	}
//	return prev;
//}
//
//Edge diameter2(const Graph &g, int s = 0) {
//	Array dist;
//	dijkstra2(g, s, dist);
//	int n = g.size(), u = -1, v = -1;
//	for (int i = 0; i < n; i++) if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
//	dijkstra2(g, u, dist);
//	for (int i = 0; i < n; i++) if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
//	Weight d = dist[v];
//	if (u > v) swap(u, v);
//	return Edge(u, v, d);
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n; cin >> n;
//	Graph g(n);
//	rep(i, 0, n - 1) {
//		int a, b; cin >> a >> b; a--, b--;
//		add_edge(g, a, b);
//	}
//	Edge d = diameter(g);
//	vector<bool> f(n);
//	er.resize(n);
//	function<bool(int)> dfs = [&](int u) {
//		if (f[u])return false;
//		f[u] = true;
//		if (u == d.d) {
//			er[u] = true;
//			return true;
//		}
//		for (auto &e : g[u]) {
//			if (f[e.d])continue;
//			if (dfs(e.d)) {
//				er[u] = true;
//				return true;
//			}
//		}
//		return false;
//	};
//	dfs(d.s);
//	dump(er);
//	int add = 0;
//	rep(i, 0, n) {
//		if (er[i])continue;
//		Edge d2 = diameter2(g, i);
//		dump(i, d2);
//		chmax(add, d2.w + 1);
//	}
//	cout << d.d + add << endl;
//	return 0;
//}