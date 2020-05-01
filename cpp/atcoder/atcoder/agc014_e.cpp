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
//	int N; cin >> N;
//	vector<int> deg1(N), deg2(N);
//	Graph g1(N), g2(N);
//	rep(i, 0, N - 1) {
//		int a, b; cin >> a >> b; a--, b--;
//		add_edge(g1, a, b);
//		deg1[a]++; deg1[b]++;
//	}
//	rep(j, 0, N - 1) {
//		int c, d; cin >> c >> d; c--, d--;
//		add_edge(g2, c, d);
//		deg2[c]++, deg2[d]++;
//	}
//	dump(deg1, deg2);
//
//	bool flag = true;
//	while (flag) {
//		flag = false;
//		rep(i, 0, N) {
//			if (deg1[i] == 1 && deg2[i] == 1) {
//				flag = true;
//				deg1[i] = deg2[i] = 0;
//				for (auto &e : g1[i]) {
//					if (deg1[e.d]) {
//						deg1[e.d]--;
//					}
//				}
//				for (auto &e : g2[i]) {
//					if (deg2[e.d]) {
//						deg2[e.d]--;
//					}
//				}
//			}
//		}
//		dump(deg1, deg2);
//	}
//	rep(i, 0, N) {
//		if (deg1[i]) {
//			cout << "NO" << endl;
//			return 0;
//		}
//	}
//	cout << "YES" << endl;
//	return 0;
//}