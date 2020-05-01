#include "GraphTheory.cpp"

// ç≈ëÂó¨
struct Dinic {
	int n, s, t;
	vector<int> level, prog, que;
	vector<vector<Flow>> cap, flow;
	vector<vector<int>> g;
	Flow inf;
	Dinic(const Graph &graph)
		: n(graph.size()),
		cap(n, vector<Flow>(n)),
		flow(n, vector<Flow>(n)),
		g(n, vector<int>()),
		inf(numeric_limits<Flow>::max() / 8) {
		for (int i = 0; i < n; i++) {
			for (auto &e : graph[i]) {
				int u = e.s, v = e.d;
				Flow c = e.c;
				cap[u][v] += c;
				cap[v][u] += c;
				flow[v][u] += c;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
	}
	inline Flow residue(int u, int v) { return cap[u][v] - flow[u][v]; }
	Flow solve(int s_, int t_) {
		this->t = t_, this->s = s_;
		que.resize(n + 1);
		Flow res = 0;
		while (levelize()) {
			prog.assign(n, 0);
			res += augment(s, inf);
		}
		return res;
	}
	bool levelize() {
		int l = 0, r = 0;
		level.assign(n, -1);
		level[s] = 0;
		que[r++] = s;
		while (l != r) {
			int v = que[l++];
			if (v == t) break;
			for (const int &d : g[v])
				if (level[d] == -1 && residue(v, d) != 0) {
					level[d] = level[v] + 1;
					que[r++] = d;
				}
		}
		return level[t] != -1;
	}
	Flow augment(int v, Flow lim) {
		Flow res = 0;
		if (v == t) return lim;
		for (int &i = prog[v]; i < (int)g[v].size(); i++) {
			const int &d = g[v][i];
			if (residue(v, d) == 0 || level[v] >= level[d]) continue;
			const Flow aug = augment(d, min(lim, residue(v, d)));
			flow[v][d] += aug;
			flow[d][v] -= aug;
			res += aug;
			lim -= aug;
			if (lim == 0) break;
		}
		return res;
	}
};
//http://abc010.contest.atcoder.jp/submissions/1143879
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235592

//ç≈è¨îÔópó¨
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
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235555
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235579