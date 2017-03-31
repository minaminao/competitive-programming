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

void add_arc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void add_edge(Graph &g, int a, int b, Weight w = 1) {
	add_arc(g, a, b, w);
	add_arc(g, b, a, w);
}


vector<int> dijkstra(const Graph &g, int s, Array &dist) {
	int n = g.size();
	assert(s < n);
	enum { WHITE, GRAY, BLACK };
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
		if (dist[v] < d)continue;
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

vector<int> get_path(int s, int g, vector<int> prev) {
	vector<int> path;
	path.emplace_back(g);
	for (int i = g; i != s; ) {
		if (i == -1)return vector<int>();
		path.emplace_back(i = prev[i]);
	}
	reverse(path.begin(), path.end());
	return path;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, x; cin >> n >> x; x--;
	Graph g(n);
	vector<int> h(n); rep(i, 0, n) { cin >> h[i]; }
	vector<int> a(n - 1), b(n - 1); rep(i, 0, n - 1) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		add_edge(g, a[i], b[i]);
	}
	Array dist;
	vector<int> prev = dijkstra(g, x, dist);
	unordered_set<int> st;
	rep(i, 0, n) {
		if (h[i] == 0)continue;
		vector<int> path = get_path(x, i, prev);
		dump(path);
		st.insert(path.begin(), path.end());
	}
	dump(st);
	int ans = st.size();
	ans--;
	ans *= 2;
	cout << max(0, ans) << endl;
	return 0;
}