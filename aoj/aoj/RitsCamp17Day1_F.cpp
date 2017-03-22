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
//	bool operator<(const Edge &e)const { return w < e.w; }
//};
//using Edges = vector<Edge>;
//using Graph = vector<Edges>;
//using Array = vector<Weight>;
//using Matrix = vector<Array>;
//
//inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }
//
//void add_edge(Graph &g, int a, int b, Weight w = 1) {
//	g[a].emplace_back(a, b, w);
//	g[b].emplace_back(b, a, w);
//}
//void add_arc(Graph &g, int s, int d, Weight w = 1) { g[s].emplace_back(s, d, w); }
//
//int N, M, R, Q;
//
////ñ¢íTçı, íTçıíÜ, íTçıçœ
//enum { WHITE, GRAY, BLACK };
//
//Array dijkstra(const Graph &g, int s) {
//	int n = g.size();
//	vector<int> color(n, WHITE); color[s] = GRAY;
//	vector<int> prev(n, -1);
//	vector<int> color2(R, WHITE);
//	vector<Weight> dist2(R, INF);
//	dist2[s%R] = 0;
//	unordered_map<int, Weight> dist;
//	dist[s] = 0;
//	using State = tuple<Weight, int, int>; //énì_Ç©ÇÁÇÃç≈íZãóó£ éq êe
//	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
//	while (pq.size()) {
//		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //distÇ™ç≈è¨Ç∆Ç»ÇÈStateÇéÊÇËèoÇ∑
//		dump(d, v, u);
//		if (dist[v] < d)continue; //Ç∑Ç≈Ç…ç≈íZÇ≈Ç»ÇØÇÍÇŒñ≥éã
//		color[v] = BLACK; prev[v] = u;
//
//		if (count(all(color2), WHITE) == 0)break;
//		color2[v%R] = BLACK;
//
//		for (auto &e : g[v]) {
//			if (color[e.d] == BLACK)continue;
//			if (!dist.count(e.d))dist[e.d] = INF;
//			if (dist[e.d] > dist[v] + e.w) {
//				dist[e.d] = dist[v] + e.w;
//				chmin(dist2[e.d%R], dist[e.d]);
//				pq.emplace(dist[e.d], e.d, v);
//				color[e.d] = GRAY;
//			}
//		}
//	}
//	return dist2;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> N >> M >> R >> Q;
//	Graph g(N);
//	vector<int> a(M), b(M), c(M); rep(i, 0, M) {
//		cin >> a[i] >> b[i] >> c[i];
//		a[i]--, b[i]--;
//		add_arc(g, a[i], b[i], c[i]);
//	}
//
//	Matrix dists(N);
//	rep(i, 0, N) {
//		dists[i] = dijkstra(g, i);
//	}
//	dump(dists);
//
//	vector<int> x(Q), y(Q), z(Q); rep(i, 0, Q) {
//		cin >> x[i] >> y[i] >> z[i];
//		x[i]--, y[i]--;
//	}
//
//	int ans = 0;
//	rep(i, 0, Q) {
//		int add = 0;
//		rep(j, 0, R) {
//			chmax(add, z[i] - dists[x[i]][j] - dists[y[i]][j]);
//		}
//		ans += add;
//	}
//	cout << ans << endl;
//	return 0;
//}