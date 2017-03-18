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
////ñ¢íTçı, íTçıíÜ, íTçıçœ
//enum { WHITE, GRAY, BLACK };
//
////íPàÍénì_ç≈íZåoòH(ïâï¬òHÇ»Çµ)
////Dijkstra O((E+V)logV)
////dist: énì_Ç©ÇÁäeí∏ì_Ç‹Ç≈ÇÃç≈íZãóó£
////ñﬂÇËíl: ç≈íZåoòHñÿÇÃêeí∏ì_(ç™ÇÕ-1)
//vector<int> dijkstra(const Graph &g, int s, Array &dist) {
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
//auto idx = [&](int i, int j) {return i*W + j; };
//
////ìÒéüå≥îzóÒÇ©ÇÁGraphÇê∂ê¨
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
//		if (ci == gi&&cj == gj) {
//			s[gi][gj] = '.';
//			return r;
//		}
//		if (!inrange(ci, cj))continue;
//		if (s[ci][cj] == '#')continue;
//		//else if (s[ci][cj] == 'o')continue;
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
//
//	//auto bfs = [&](int si, int sj, int gi, int gj) {
//	//	using P = tuple<int, int, string>;
//	//	queue<P> q;
//	//	vector<vector<int>> d(H, vector<int>(W, INF));
//	//	q.emplace(si, sj, "");
//	//	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
//	//	while (q.size()) {
//	//		int ci, cj; string r; tie(ci, cj, r) = q.front(); q.pop();
//	//		if (ci == gi&&cj == gj)return make_pair(score, r);
//	//		if (!inrange(ci, cj))continue;
//	//		if (s[ci][cj] == '#')continue;
//	//		if (d[ci][cj] < INF)continue;
//	//		d[ci][cj] = r.size();
//	//		rep(i, 0, 4) {
//	//			q.emplace(ci + di[i], cj + dj[i], r + dir[i]);
//	//		}
//	//	}
//	//	return make_pair(0, "");
//	//};
//
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
//		s[fr[i]][fc[i]] = 'o';
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
//	int s = N - 1;
//	string ans = "";
//	vector<int> flag(N);
//	rep(a, 0, N) {
//		flag[s] = true;
//		int d = -1;
//		Weight mini = INF;
//		rep(j, 0, N) {
//			if (s == j)continue;
//			if (flag[j])continue;
//			int t = ans.size();
//			if (F[j] - D[j] * (C[s][j] + t) <= 0)continue;
//			rep(k, 0, N) {
//				if (j == k)continue;
//				if (flag[k])continue;
//				if (F[k] - D[k] * (C[s][j] + C[j][k] + t) <= 0)continue;
//				if (chmin(mini, C[s][j] + C[j][k])) {
//					d = j;
//					//dump(s, j, k, C[s][j], C[j][k]);
//					//dump(mini);
//				}
//			}
//		}
//		dump(d);
//		if (d == -1)break;
//		dump(ans.size(), fr[s], fc[s], fr[d], fc[d]);
//		ans += bfs(fr[s], fc[s], fr[d], fc[d]);
//		s = d;
//	}
//	output(ans);
//	return 0;
//}