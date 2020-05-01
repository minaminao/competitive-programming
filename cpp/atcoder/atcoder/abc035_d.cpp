#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

using Weight = int;
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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, T; cin >> N >> M >> T;
	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
	Graph g(N), g2(N);
	vector<int> a(M), b(M), c(M); rep(i, 0, M) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		add_arc(g, a[i], b[i], c[i]);
		add_arc(g2, b[i], a[i], c[i]);
	}
	vector<Weight> dist, dist2;
	dijkstra(g, 0, dist);
	dijkstra(g2, 0, dist2);
	int ans = 0;
	rep(i, 0, N) {
		Weight t = T - dist[i] - dist2[i];
		if (t < 0)continue;
		dump(t, A[i]);
		chmax(ans, A[i] * t);
	}
	cout << ans << endl;
	return 0;
}