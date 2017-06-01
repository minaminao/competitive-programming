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
//void addArc(Graph &g, int s, int d, Weight w = 1) {
//	g[s].emplace_back(s, d, w);
//}
//void addEdge(Graph &g, int a, int b, Weight w = 1) {
//	addArc(g, a, b, w);
//	addArc(g, b, a, w);
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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	for (int w, h; cin >> w >> h && w;) {
//		vector<vector<int>> v(h, vector<int>(w));
//		rep(i, 0, h) rep(j, 0, w) { cin >> v[i][j]; }
//		Graph g(w*h * 4);
//		auto index = [&](int i, int j, int d) {return i*w + j + d*w*h; };
//		auto inrange = [&](int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; };
//		vector<int> c(4); rep(i, 0, 4) {
//			cin >> c[i];
//		}
//
//		rep(i, 0, h)rep(j, 0, w) {
//			static const int di[] = { 1,0,-1,0 };
//			static const int dj[] = { 0,1,0,-1 };
//			rep(a, 0, 4) {
//				rep(k, 0, 4) {
//					int b = (a + k) % 4;
//					int ni = i + di[a], nj = j + dj[a];
//					if (!inrange(ni, nj))continue;
//					if (k == v[i][j])
//						addArc(g, index(i, j, a), index(ni, nj, b), 0);
//					else
//						addArc(g, index(i, j, a), index(ni, nj, b), c[k]);
//				}
//			}
//		}
//		int ans = INF;
//		Array dist;
//		dump(g);
//		dump(dijkstra(g, index(0, 0, 1), dist));
//		rep(b, 0, 4) {
//			chmin(ans, dist[index(h - 1, w - 1, b)]);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}