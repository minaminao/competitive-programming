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

struct MinimumCostMaximumFlow {
	using Index = int;
	using Flow = int;
	using Cost = int;
	static const Flow INF_CAPACITY = INF;
	static const Cost INF_COST = INF;
	struct Edge {
		Index s, d;
		Flow capacity;
		Cost cost;
	};
	using Edges = vector<Edge>;
	using Graph = vector<Edges>;
	Graph g;
	void init(Index n) { g.assign(n, Edges()); }
	void add_arc(Index i, Index j, Flow capacity = INF_CAPACITY, Cost cost = Cost()) {
		Edge e, f; e.d = j, f.d = i; e.capacity = capacity, f.capacity = 0; e.cost = cost, f.cost = -cost;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().s = (Index)g[j].size() - 1; g[j].back().s = (Index)g[i].size() - 1;
	}
	void add_edge(Index i, Index j, Flow capacity = INF_CAPACITY, Cost cost = Cost()) {
		add_arc(i, j, capacity, cost);
		add_arc(j, i, capacity, cost);
	}
	pair<Cost, Flow> minimum_cost_maximum_flow(Index s, Index t, Flow f = INF_CAPACITY, bool useSPFA = false) {
		int n = g.size();
		vector<Cost> dist(n); vector<Index> prev(n); vector<Index> prev_edge(n);
		pair<Cost, Flow> total = make_pair(0, 0);
		vector<Cost> potential(n);
		while (f > 0) {
			fill(dist.begin(), dist.end(), INF_COST);
			if (useSPFA || total.second == 0) {
				deque<Index> q;
				q.push_back(s); dist[s] = 0; vector<bool> inqueue(n);
				while (!q.empty()) {
					Index i = q.front(); q.pop_front(); inqueue[i] = false;
					for (Index ei = 0; ei < g[i].size(); ei++) {
						const Edge &e = g[i][ei]; Index j = e.d; Cost d = dist[i] + e.cost;
						if (e.capacity > 0 && d < dist[j]) {
							if (!inqueue[j]) {
								inqueue[j] = true;
								q.push_back(j);
							}
							dist[j] = d; prev[j] = i; prev_edge[j] = ei;
						}
					}
				}
			}
			else {
				vector<bool> vis(n);
				priority_queue<pair<Cost, Index> > q;
				q.push(make_pair(-0, s)); dist[s] = 0;
				while (!q.empty()) {
					Index i = q.top().second; q.pop();
					if (vis[i]) continue;
					vis[i] = true;
					for (Index ei = 0; ei < (Index)g[i].size(); ei++) {
						const Edge &e = g[i][ei];
						if (e.capacity <= 0) continue;
						Index j = e.d; Cost d = dist[i] + e.cost + potential[i] - potential[j];
						if (dist[j] > d) {
							dist[j] = d; prev[j] = i; prev_edge[j] = ei;
							q.push(make_pair(-d, j));
						}
					}
				}
			}
			if (dist[t] == INF_COST) break;
			if (!useSPFA) for (Index i = 0; i < n; i++) potential[i] += dist[i];

			Flow d = f; Cost distt = 0;
			for (Index v = t; v != s; ) {
				Index u = prev[v]; const Edge &e = g[u][prev_edge[v]];
				d = min(d, e.capacity); distt += e.cost; v = u;
			}
			f -= d; total.first += d * distt; total.second += d;
			for (Index v = t; v != s; v = prev[v]) {
				Edge &e = g[prev[v]][prev_edge[v]];
				e.capacity -= d; g[e.d][e.s].capacity += d;
			}
		}
		return total;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, K; cin >> N >> M >> K;
	MinimumCostMaximumFlow mcmf;
	mcmf.init(N + M + 2 + 1 + 1);
	int source = N + M,
		sink = source + 1,
		I = source + 2,
		X = source + 3;
	rep(i, 0, N) {
		int test = i;
		mcmf.add_arc(source, test, 1);
		int a; cin >> a;
		mcmf.add_arc(test, I, 1, -a);
	}
	rep(i, 0, M)rep(j, 0, N) {
		int b; cin >> b;
		int test = j;
		int friends = i + N;
		mcmf.add_arc(test, friends, 1, -b);
	}
	rep(i, 0, M) {
		int T; cin >> T;
		int friends = i + N;
		mcmf.add_arc(friends, X, T);
	}
	mcmf.add_arc(X, sink, N - K);
	mcmf.add_arc(I, sink);
	auto res = mcmf.minimum_cost_maximum_flow(source, sink);
	cout << -res.first << endl;
	return 0;
}