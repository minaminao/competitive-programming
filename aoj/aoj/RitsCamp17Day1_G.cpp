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

//座標圧縮
//index()と合わせて使う
template<typename T>
vector<T> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

//圧縮後の配列のインデックス
//index(圧縮後の配列, 要素)
template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, S, G; cin >> N >> M >> S >> G;
	S--, G--;
	using P = pair<int, int>; // u t
	vector<P> V;
	V.emplace_back(S, 0);
	vector<int> u(M), v(M), t(M), c(M); rep(i, 0, M) {
		cin >> u[i] >> v[i] >> t[i] >> c[i];
		u[i]--, v[i]--;
		V.emplace_back(u[i], t[i]);
		V.emplace_back(v[i], t[i] + c[i]);
	}
	vector<P> CV = compress(V);
	int n = CV.size();
	Graph g(n);
	rep(i, 0, n - 1) {
		if (CV[i].first == CV[i + 1].first) {
			add_arc(g, i, i + 1, CV[i + 1].second - CV[i].second);
		}
	}
	rep(i, 0, M) {
		int a = index(CV, P(u[i], t[i])),
			b = index(CV, P(v[i], t[i] + c[i]));
		add_arc(g, a, b, 0);
	}
	int s = index(CV, P(S, 0));
	Array dist;
	dijkstra(g, s, dist);
	Weight ans = INF;
	rep(i, 0, n) {
		if (CV[i].first == G) {
			chmin(ans, dist[i]);
		}
	}
	cout << ans << endl;
	return 0;
}