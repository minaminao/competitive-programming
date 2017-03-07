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
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
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
////ñ¢íTçı, íTçıíÜ, íTçıçœ
//enum { WHITE, GRAY, BLACK };
//
////íPàÍénì_ç≈íZåoòH(ïâï¬òHÇ»Çµ)
////Dijkstra O((E+V)logV)
////dist: énì_Ç©ÇÁäeí∏ì_Ç‹Ç≈ÇÃç≈íZãóó£
////ñﬂÇËíl: ç≈íZåoòHñÿÇÃêeí∏ì_(ç™ÇÕ-1)
//vector<int> dijkstra(const Graph &g, int s, vector<Weight> &dist) {
//	int n = g.size();
//	vector<int> color(n, WHITE); color[s] = GRAY;
//	vector<int> prev(n, -1);
//	dist.assign(n, INF); dist[s] = 0;
//	using State = tuple<Weight, int, int>; //énì_Ç©ÇÁÇÃç≈íZãóó£ éq êe
//	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
//	while (pq.size()) {
//		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //distÇ™ç≈è¨Ç∆Ç»ÇÈStateÇéÊÇËèoÇ∑
//		if (dist[v] < d)continue; //Ç∑Ç≈Ç…ç≈íZÇ≈Ç»ÇØÇÍÇŒñ≥éã
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
////ëSì_ëŒä‘ç≈íZåoòH 
//void all_pairs_shortest_paths_by_dijkstra(const Graph &g, Matrix &dists) {
//	int n = g.size();
//	dists.resize(n);
//	for (int i = 0; i < n; i++)
//		dijkstra(g, i, dists[i]);
//}
//
////ëfèWçáÉfÅ[É^ç\ë¢
//struct UnionFind {
//	vector<int> parent;
//	int size;
//	UnionFind(int n) :parent(n, -1), size(n) {}
//	bool unite(int x, int y) {
//		x = root(x); y = root(y);
//		if (x == y)return false;
//		if (size_of(x) < size_of(y))swap(x, y);
//		parent[x] += parent[y]; parent[y] = x; size--;
//		return true;
//	}
//	bool same(int x, int y) { return root(x) == root(y); }
//	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
//	int size_of(int x) { return -parent[root(x)]; }
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cout << fixed << setprecision(8);
//	for (int N; cin >> N&&N;) {
//		vector<double> p(N);
//		Graph g(N);
//		rep(i, 0, N) {
//			cin >> p[i];
//			int M; cin >> M;
//			rep(j, 0, M) {
//				int a; cin >> a;
//				add_arc(g, i, a - 1);
//			}
//		}
//		Matrix dists;
//		all_pairs_shortest_paths_by_dijkstra(g, dists);
//		UnionFind uf(N);
//		vector<int> in(N);
//		vector<double> pp(N, 1.0);
//		rep(i, 0, N)rep(j, 0, N) {
//			if (dists[i][j] != INF&&dists[j][i] != INF) {
//				uf.unite(i, j);
//			}
//			else if (dists[i][j] != INF) {
//				in[j]++;
//			}
//			else if (dists[j][i] != INF) {
//				in[i]++;
//			}
//		}
//		rep(i, 0, N) {
//			pp[uf.root(i)] *= p[i];
//		}
//		dump(pp);
//		vector<bool> f(N);
//		double ans = 1;
//		rep(i, 0, N) {
//			if (in[i]) continue;
//			if (f[uf.root(i)])continue;
//			f[uf.root(i)] = true;
//			ans *= 1 - pp[uf.root(i)];
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}