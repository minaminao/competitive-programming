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
//struct Dinic {
//	int n, s, t;
//	vector<int> level, prog, que;
//	vector<vector<Flow>> cap, flow;
//	vector<vector<int>> g;
//	Flow inf;
//	Dinic(const Graph &graph)
//		: n(graph.size()),
//		cap(n, vector<Flow>(n)),
//		flow(n, vector<Flow>(n)),
//		g(n, vector<int>()),
//		inf(numeric_limits<Flow>::max() / 8) {
//		for (int i = 0; i < n; i++) {
//			for (auto &e : graph[i]) {
//				int u = e.s, v = e.d;
//				Flow c = e.c;
//				cap[u][v] += c;
//				cap[v][u] += c;
//				flow[v][u] += c;
//				g[u].push_back(v);
//				g[v].push_back(u);
//			}
//		}
//	}
//	inline Flow residue(int u, int v) { return cap[u][v] - flow[u][v]; }
//	Flow solve(int s_, int t_) {
//		this->t = t_, this->s = s_;
//		que.resize(n + 1);
//		Flow res = 0;
//		while (levelize()) {
//			prog.assign(n, 0);
//			res += augment(s, inf);
//		}
//		return res;
//	}
//	bool levelize() {
//		int l = 0, r = 0;
//		level.assign(n, -1);
//		level[s] = 0;
//		que[r++] = s;
//		while (l != r) {
//			int v = que[l++];
//			if (v == t) break;
//			for (const int &d : g[v])
//				if (level[d] == -1 && residue(v, d) != 0) {
//					level[d] = level[v] + 1;
//					que[r++] = d;
//				}
//		}
//		return level[t] != -1;
//	}
//	Flow augment(int v, Flow lim) {
//		Flow res = 0;
//		if (v == t) return lim;
//		for (int &i = prog[v]; i < (int)g[v].size(); i++) {
//			const int &d = g[v][i];
//			if (residue(v, d) == 0 || level[v] >= level[d]) continue;
//			const Flow aug = augment(d, min(lim, residue(v, d)));
//			flow[v][d] += aug;
//			flow[d][v] -= aug;
//			res += aug;
//			lim -= aug;
//			if (lim == 0) break;
//		}
//		return res;
//	}
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt0.out", "w", stdout);
//	//freopen("in.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	cout << fixed << setprecision(10);
//	for (int test = 0; test < T; test++) {
//		int N, C, M; cin >> N >> C >> M;
//		vector<int> P(M), B(M); rep(i, 0, M) {
//			cin >> P[i] >> B[i];
//			P[i]--, B[i]--;
//		}
//		dump(N, C, M);
//
//		Graph g(2 * M + 2);
//
//		int s = 2 * M, t = 2 * M + 1;
//
//		auto init = [&]() {
//			g.assign(2 * M + 2, Edges());
//			rep(i, 0, M) {
//				rep(j, 0, M) {
//					if (B[i] == B[j])continue;
//					if (P[i] == P[j])continue;
//					add_arc(g, i, M + j, 1);
//				}
//			}
//
//			//dump(g);
//
//			rep(i, 0, M) {
//				add_arc(g, s, i, 1);
//				add_arc(g, M + i, t, 1);
//			}
//		};
//		init();
//		Dinic dinic(g);
//		Flow f = dinic.solve(s, t);
//		Flow f0 = f;
//		dump(f);
//
//		rep(i, 0, M) {
//			if (dinic.flow[s][i] == 0) {
//				if (P[i] >= 1)
//					P[i]--;
//			}
//		}
//		init();
//		dinic = Dinic(g);
//		f = dinic.solve(s, t);
//		dump(f);
//
//		rep(i, M, 2 * M) {
//			if (dinic.flow[i][t] == 0) {
//				if (P[i] >= 1)
//					P[i]--;
//			}
//		}
//
//		init();
//		dinic = Dinic(g);
//		f = dinic.solve(s, t);
//		Flow z = f - f0;
//
//		int y = 0;
//		rep(i, 0, M) {
//			if (B[i] == 0) {
//				y++;
//			}
//			else {
//				if (dinic.flow[i][t] == 0)
//					y++;
//			}
//		}
//
//		cout << "Case #" << test + 1 << ": " << y << " " << z << endl;
//	}
//	return 0;
//}