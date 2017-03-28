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
//
////óLå¸êXÅióLå¸ñÿÅjÇÃê[Ç≥
//using P = pair<int, int>; //ê[Ç≥ ç™
//vector<P> depth(const Graph &g) {
//	int n = g.size();
//	vector<P> ret(n);
//	for (int i = 0; i < n; i++)
//		ret[i] = P(0, i);
//	vector<bool> isroot(n, true);
//	for (int i = 0; i < n; i++)
//		for (auto &e : g[i])
//			isroot[e.d] = false;
//	using State = tuple<int, int, int>; //ÉmÅ[Éh ç™ ê[Ç≥
//	stack<State> st;
//	dump(isroot);
//	for (int i = 0; i < n; i++)
//		if (isroot[i])
//			st.emplace(i, i, 0);
//	while (st.size()) {
//		int s, r, d; tie(s, r, d) = st.top(); st.pop();
//		ret[s] = P(d, r);
//		for (auto &e : g[s])
//			st.emplace(e.d, r, d + 1);
//	}
//	return ret;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int H, W, N; cin >> H >> W >> N;
//	Graph g(H*W);
//	auto index = [&](int i, int j) {return i*W + j; };
//	rep(i, 0, H)rep(j, 0, W) {
//		int r, c; cin >> r >> c;
//		add_arc(g, index(r, c), index(i, j));
//	}
//	dump(g);
//	vector<P> d = depth(g);
//	dump(d);
//	return 0;
//}