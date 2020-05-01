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

vector<int> dijkstra(const Graph &g, int s, Array &dist) {
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
				dist[e.d] = dist[v] + e.w;
				pq.emplace(dist[e.d], e.d, v);
				color[e.d] = GRAY;
			}
		}
	}
	return prev;
}

//ç¿ïWà≥èk
//index()Ç∆çáÇÌÇπÇƒégÇ§
template<typename T>
vector<T> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int w, h; cin >> w >> h &&h;) {
		vector<vector<char>> c(h, vector<char>(w));
		rep(i, 0, h)rep(j, 0, w)
			cin >> c[i][j];
		auto inrange = [&](int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; };
		auto valid = [&](int li, int lj, int ri, int rj) {return abs(li - ri) + abs(lj - rj) <= 3 && lj < rj; };
		auto idx = [&](int li, int lj, int ri, int rj, int right) {
			int ret = li;
			ret *= w;
			ret += lj;
			ret *= h;
			ret += ri;
			ret *= w;
			ret += rj;
			ret += (w*h*w*h)*right;
			return ret;
		};

		vector<int> v;
		rep(li, 0, h)rep(lj, 0, w)rep(ri, 0, h)rep(rj, 0, w) {
			if (valid(li, lj, ri, rj)) {
				v.push_back(idx(li, lj, ri, rj, 0));
				v.push_back(idx(li, lj, ri, rj, 1));
			}
		}
		vector<int> zip = compress(v);

		auto index = [&](int li, int lj, int ri, int rj, int r) {
			return lower_bound(zip.begin(), zip.end(), idx(li, lj, ri, rj, r)) - zip.begin();
		};
		Graph g(zip.size() + 2);
		// next right 1
		int s = zip.size(), t = s + 1;

		rep(li, 0, h)rep(lj, 0, w)rep(ri, 0, h)rep(rj, lj + 1, w) {
			if (!valid(li, lj, ri, rj))continue;
			//dump(li, lj, ri, rj);
			if (c[li][lj] == 'X' || c[ri][rj] == 'X')continue;
			if (c[li][lj] == 'S') {
				addArc(g, s, index(li, lj, ri, rj, 0), c[ri][rj] == 'S' ? 0 : c[ri][rj] - '0');
			}
			if (c[ri][rj] == 'S') {
				addArc(g, s, index(li, lj, ri, rj, 1), c[li][lj] == 'S' ? 0 : c[li][lj] - '0');
			}
			if (c[li][lj] == 'T') {
				addArc(g, index(li, lj, ri, rj, 1), t, 0);
			}
			if (c[ri][rj] == 'T') {
				addArc(g, index(li, lj, ri, rj, 0), t, 0);
			}
			rep(r, 0, 2) {
				int u = index(li, lj, ri, rj, r);
				rep(di, -10, 10)rep(dj, -10, 10) {
					int nli = li, nlj = lj, nri = ri, nrj = rj;
					int cost;
					if (r) {
						nri += di;
						nrj += dj;
						if (!inrange(nri, nrj))continue;
						if (c[nri][nrj] == 'X')continue;
						cost = c[nri][nrj] == 'T' ? 0 : c[nri][nrj] - '0';
					}
					else {
						nli += di;
						nlj += dj;
						if (!inrange(nli, nlj))continue;
						if (c[nli][nlj] == 'X')continue;
						cost = c[nli][nlj] == 'T' ? 0 : c[nli][nlj] - '0';
					}
					if (!valid(nli, nlj, nri, nrj))continue;
					//dump(nli, nlj, nri, nrj);
					int v = index(nli, nlj, nri, nrj, !r);
					addArc(g, u, v, cost);
				}
			}
		}
		int ans = INF;
		Array dist;
		dijkstra(g, s, dist);
		chmin(ans, dist[t]);
		cout << (ans == INF ? -1 : ans) << endl;
	}
	return 0;
}