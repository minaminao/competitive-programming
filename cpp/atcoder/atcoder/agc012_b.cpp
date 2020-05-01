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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, M; cin >> N >> M;
//	Graph g(N);
//	vector<int> a(M), b(M); rep(i, 0, M) {
//		cin >> a[i] >> b[i];
//		a[i]--, b[i]--;
//		add_edge(g, a[i], b[i]);
//	}
//	int Q; cin >> Q;
//	vector<int> v(Q), d(Q), c(Q);
//	rep(i, 0, Q) {
//		cin >> v[i] >> d[i] >> c[i];
//		v[i]--;
//	}
//	vector<int> color(N);
//	auto bfs = [&](int root, int d, int c) {
//		int n = g.size();
//		vector<bool> f(n);
//		using State = tuple<int, int>;
//		queue<State> q; q.emplace(root, d);
//		while (q.size()) {
//			int u, d;
//			tie(u, d) = q.front(); q.pop();
//			if (f[u])continue;
//			f[u] = true;
//			if (color[u] == 0)color[u] = c;
//			if (d == 0)continue;
//			for (auto &e : g[u]) {
//				if (f[e.d])continue;
//				q.emplace(e.d, d - 1);
//			}
//		}
//	};
//	rrep(i, 0, Q) {
//		bfs(v[i], d[i], c[i]);
//	}
//	rep(i, 0, color.size()) { cout << color[i] << endl; }
//	return 0;
//}