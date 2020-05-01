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
//void generate_dot(const Graph &g) {
//	int n = g.size();
//	cout << "digraph G {" << endl;
//	rep(i, 0, n) {
//		cout << "  " << i << ";" << endl;
//	}
//	for (auto &es : g)for (auto &e : es) {
//		cout << "  " << e.s << " -> " << e.d << ";" << endl;
//	}
//	cout << "}";
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	return 0;
//}