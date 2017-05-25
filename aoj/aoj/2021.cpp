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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}

vector<int> dijkstra(const Graph &g, int s, Array &dist, int M = INF) {
	int n = g.size();
	assert(s < n);
	enum { WHITE, GRAY, BLACK };
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>;
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
		if (dist[v] < d)continue;
		color[v] = BLACK; prev[v] = u;
		for (auto &e : g[v]) {
			if (color[e.d] == BLACK)continue;
			if (dist[e.d] > dist[v] + e.w) {
				if (dist[v] + e.w > M)continue;
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
	for (int N, M, L, K, A, H; cin >> N >> M >> L >> K >> A >> H&&N;) {
		vector<int> f(L); rep(i, 0, L) {
			cin >> f[i];
		}

		Graph g(N);
		rep(i, 0, K) {
			int a, b, c; cin >> a >> b >> c;
			addEdge(g, a, b, c);
		}
		Matrix dists(N, Array(N, INF));
		dijkstra(g, A, dists[A], M);
		rep(i, 0, L) {
			dijkstra(g, f[i], dists[f[i]], M);
		}
		Graph g2(N);
		f.push_back(A);
		f.push_back(H);
		rep(i, 0, f.size()) {
			rep(j, 0, f.size()) {
				if (i == j)continue;
				addArc(g2, f[i], f[j], dists[f[i]][f[j]]);
			}
		}
		Array dist;
		dijkstra(g2, A, dist);
		if (dist[H] == INF) {
			cout << "Help!" << endl;
		}
		else if (dist[H] <= M) {
			cout << dist[H] << endl;
		}
		else {
			cout << dist[H] - M + dist[H] << endl;
		}
	}
	return 0;
}