#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

using Weight = long long;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
	bool operator<(const Edge &e)const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int s, int d, Weight w = 1) { g[s].emplace_back(s, d, w); }

//ñ¢íTçı, íTçıíÜ, íTçıçœ
enum { WHITE, GRAY, BLACK };

//íPàÍénì_ç≈íZåoòH(ïâï¬òHÇ»Çµ)
//Dijkstra O((E+V)logV)
//dist: énì_Ç©ÇÁäeí∏ì_Ç‹Ç≈ÇÃç≈íZãóó£
//ñﬂÇËíl: ç≈íZåoòHñÿÇÃêeí∏ì_(ç™ÇÕ-1)
vector<int> dijkstra(const Graph &g, int s, vector<Weight> &dist) {
	int n = g.size();
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //énì_Ç©ÇÁÇÃç≈íZãóó£ éq êe
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //distÇ™ç≈è¨Ç∆Ç»ÇÈStateÇéÊÇËèoÇ∑
		if (dist[v] < d)continue; //Ç∑Ç≈Ç…ç≈íZÇ≈Ç»ÇØÇÍÇŒñ≥éã
		color[v] = BLACK; prev[v] = u;
		for (auto &e : g[v]) {
			if (color[e.d] == BLACK)continue;
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				pq.emplace(dist[e.d], e.d, v);
				color[e.d] = GRAY;
			}
		}
	}
	return prev;
}

Graph build(const vector<vector<char>> &v, int w) {
	const int H = v.size(), W = v[0].size();
	static const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	auto idx = [&](int i, int j) {return i*W + j; };
	Graph g(H*W);
	rep(i, 0, H)rep(j, 0, W) {
		rep(k, 0, 4) {
			int ni = i + di[k], nj = j + dj[k];
			if (!inrange(ni, nj))continue;
			int s = idx(i, j), d = idx(ni, nj);
			if (v[ni][nj] == '#')add_arc(g, s, d, w);
			else add_arc(g, s, d, 1);
		}
	}
	return g;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W, T; cin >> H >> W >> T;
	vector<vector<char>> v(H, vector<char>(W));
	int s, d;
	rep(i, 0, H) rep(j, 0, W) {
		cin >> v[i][j];
		if (v[i][j] == 'S')s = i*W + j;
		else if (v[i][j] == 'G')d = i*W + j;
	}
	auto f = [&](int x) {
		Graph g = build(v, x);
		Array dist;
		dijkstra(g, s, dist);
		return !(dist[d] <= T);
	};
	auto binary_search = [&](int l, int r) {
		if (f(l))return l; //exception f(l):true
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (f(m))
				r = m;
			else
				l = m;
		}
		//f(l):false, f(r):true
		return r;
	};
	cout << binary_search(1, INF) - 1 << endl;
	return 0;
}