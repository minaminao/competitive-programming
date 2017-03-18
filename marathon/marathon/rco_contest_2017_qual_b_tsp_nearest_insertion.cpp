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
//int di[4] = { 0,1,0,-1 };
//int dj[4] = { 1,0,-1,0 };
//char dir[4] = { 'R','D','L','U' };
//
//
//int H, W, K, sr, sc;
//char s[51][51];
//int N;
//int fr[2510], fc[2510], F[2510], D[2510];
//
//bool inrange(int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; }
//
//void output(string ans) {
//	if (ans.size() >= 2500) {
//		cout << ans.substr(0, 2500) << endl;
//	}
//	else {
//		ans += string(2500 - ans.size(), '-');
//		cout << ans << endl;
//	}
//}
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
////–¢’Tõ, ’Tõ’†, ’TõÏ
//enum { WHITE, GRAY, BLACK };
//
////’Pˆên“_Å’ZŒo˜H(•‰•Â˜H‚È‚µ)
////Dijkstra O((E+V)logV)
////dist: n“_‚©‚çŠe’¸“_‚Ü‚Å‚ÌÅ’Z‹——£
////–ß‚è’l: Å’ZŒo˜H–Ø‚Ìe’¸“_(ª‚Í-1)
//vector<int> dijkstra(const Graph &g, int s, Array &dist) {
//	int n = g.size();
//	vector<int> color(n, WHITE); color[s] = GRAY;
//	vector<int> prev(n, -1);
//	dist.assign(n, INF); dist[s] = 0;
//	using State = tuple<Weight, int, int>; //n“_‚©‚ç‚ÌÅ’Z‹——£ q e
//	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
//	while (pq.size()) {
//		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //dist‚ªÅ¬‚Æ‚È‚éState‚ğæ‚èo‚·
//		if (dist[v] < d)continue; //‚·‚Å‚ÉÅ’Z‚Å‚È‚¯‚ê‚Î–³‹
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
//auto idx = [&](int i, int j) {return i*W + j; };
//
////“ñŸŒ³”z—ñ‚©‚çGraph‚ğ¶¬
//Graph build(const vector<vector<char>> &v) {
//	const int H = v.size(), W = v[0].size();
//	static const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
//	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
//	Graph g(H*W);
//	rep(i, 0, H)rep(j, 0, W) {
//		if (v[i][j] == '#')continue;
//		rep(k, 0, 4) {
//			int ni = i + di[k], nj = j + dj[k];
//			if (!inrange(ni, nj))continue;
//			if (v[ni][nj] == '#')continue;
//			int s = idx(i, j), d = idx(ni, nj);
//			add_arc(g, s, d);
//		}
//	}
//	return g;
//}
//
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
//string bfs(int si, int sj, int gi, int gj) {
//	using P = tuple<int, int, string>;
//	queue<P> q;
//	vector<vector<int>> d(H, vector<int>(W, INF));
//	q.emplace(si, sj, "");
//	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
//	while (q.size()) {
//		int ci, cj; string r; tie(ci, cj, r) = q.front(); q.pop();
//		if (ci == gi&&cj == gj)return r;
//		if (!inrange(ci, cj))continue;
//		if (s[ci][cj] == '#')continue;
//		if (d[ci][cj] < INF)continue;
//		d[ci][cj] = r.size();
//		rep(i, 0, 4) {
//			q.emplace(ci + di[i], cj + dj[i], r + dir[i]);
//		}
//	}
//	return "";
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> H >> W >> K >> sr >> sc; sr--, sc--;
//	vector<vector<char>> v(H, vector<char>(W));
//	rep(i, 0, H)rep(j, 0, W) {
//		cin >> s[i][j];
//		v[i][j] = s[i][j];
//	}
//	cin >> N;
//	rep(i, 0, N) {
//		cin >> fr[i] >> fc[i] >> F[i] >> D[i];
//		fr[i]--, fc[i]--;
//	}
//	fr[N] = sr, fc[N] = sc;
//	N++;
//	Graph g1 = build(v);
//	Matrix C(N, Array(N));
//	Graph g2(N);
//	rep(i, 0, N) {
//		Array dist;
//		int s = idx(fr[i], fc[i]);
//		dijkstra(g1, s, dist);
//		rep(j, i + 1, N) {
//			int d = idx(fr[j], fc[j]);
//			add_edge(g2, i, j, dist[d]);
//			C[i][j] = C[j][i] = dist[d];
//		}
//	}
//	Graph g3(N);
//	sort(all(g2[N - 1]));
//	int a = N - 1, b = g2[N - 1][0].d, c = g2[N - 1][1].d;
//	add_edge(g3, a, b, C[a][b]);
//	add_edge(g3, b, c, C[b][c]);
//	add_edge(g3, c, a, C[c][a]);
//	//„‰ñ˜Hã‚É‚È‚¢‚à‚Ì‚Ì’†‚Å„‰ñ˜Hã‚Ì“_‚Æ‚Ì‹——£‚ªÅ¬‚Ì“_‚ğ‘}“ü
//	rep(a, 0, N - 3) {
//		Edge mini(0, 0, INF);
//		dump(g3);
//		rep(i, 0, N) {
//			if (!g3[i].size()) {
//				sort(all(g2[i]));
//				rep(j, 0, N - 1) {
//					if (g3[g2[i][j].d].size()) {
//						chmin(mini, g2[i][j]);
//						break;
//					}
//				}
//			}
//		}
//		dump(mini);
//		int k = mini.s;
//		Edge ij(0, 0, INF);
//		rep(i, 0, N) {
//			if (g3[i].size()) {
//				rep(j, 0, 2) {
//					int s = g3[i][j].s, d = g3[i][j].d;
//					dump(C[s][k], C[d][k], C[s][d]);
//					chmin(ij, Edge(s, d, C[s][k] + C[d][k] - C[s][d]));
//				}
//			}
//		}
//		dump(ij);
//		rep(i, 0, 2) {
//			if (g3[ij.s][i].d == ij.d) {
//				g3[ij.s].erase(g3[ij.s].begin() + i);
//				break;
//			}
//		}
//		rep(i, 0, 2) {
//			if (g3[ij.d][i].d == ij.s) {
//				g3[ij.d].erase(g3[ij.d].begin() + i);
//				break;
//			}
//		}
//		add_edge(g3, ij.s, k, C[ij.s][k]);
//		add_edge(g3, ij.d, k, C[ij.d][k]);
//	}
//	rep(i, 0, N) {
//		dump(g3[i]);
//	}
//	int s = N - 1;
//	string ans = "";
//	vector<int> flag(N);
//	flag[s] = true;
//	rep(i, 0, N) {
//		int d1 = g3[s][0].d, d2 = g3[s][1].d;
//		int d = flag[d1] ? d2 : d1;
//		flag[d] = true;
//		dump(s, d);
//		ans += bfs(fr[s], fc[s], fr[d], fc[d]);
//		s = d;
//	}
//	output(ans);
//	return 0;
//}