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


//全探索

void dfs(const Graph &g, int root) {
	int n = g.size();
	vector<bool> vis(n);
	stack<int> st; st.emplace(root);
	while (st.size()) {
		int u = st.top(); st.pop();
		if (vis[u])continue;
		vis[u] = true;
		/* 処理 */
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			/* 処理 */
			st.emplace(e.d);
		}
	}
}

void bfs(const Graph &g, int root) {
	int n = g.size();
	vector<bool> vis(n);
	queue<int> q; q.emplace(root);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (vis[u])continue;
		vis[u] = true;
		/* 処理 */
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			/* 処理 */
			q.emplace(e.d);
		}
	}
}

void solve() {
	int n;
	Graph g(n);
	vector<bool> vis(n);
	function<void(int)> dfs = [&](int u) {
		if (vis[u])return;
		vis[u] = true;
		/* 処理 */
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			/* 処理 */
			dfs(e.d);
		}
	};
	auto bfs = [&](int root) {
		vector<bool> vis(n);
		queue<int> q; q.emplace(root);
		while (q.size()) {
			int u = q.front(); q.pop();
			if (vis[u])continue;
			vis[u] = true;
			/* 処理 */
			for (auto &e : g[u]) {
				if (vis[e.d])continue;
				/* 処理 */
				q.emplace(e.d);
			}
		}
	};
	//not verified
	auto unweightedShortestPath = [&](int root, Array &dist) {
		dist.assign(n, INF); dist[root] = 0;
		vector<bool> vis(n);
		queue<int> q; q.emplace(root);
		while (q.size()) {
			int u = q.front(); q.pop();
			if (vis[u])continue;
			vis[u] = true;
			for (auto &e : g[u]) {
				if (vis[e.d])continue;
				dist[e.d] = dist[u] + 1;
				q.emplace(e.d);
			}
		}
	};
}


//最短経路問題

//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
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

//単一始点最短経路(負閉路あり)
//Bellman-Ford O(|V||E|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点, 負閉路なし:true あり:false
pair<vector<int>, bool> bellmanFord(const Graph &g, int s, Array &dist) {
	int n = g.size();
	vector<int> prev(n, -1);
	Edges es; for (int i = 0; i < n; i++) for (auto &e : g[i]) es.emplace_back(e);
	dist.assign(n, INF); dist[s] = 0;
	bool negative_cycle = false;
	for (int i = 0;; i++) {
		bool update = false;
		for (auto &e : es) {
			if (dist[e.s] != INF && dist[e.d] > dist[e.s] + e.w) {
				dist[e.d] = dist[e.s] + e.w;
				prev[e.d] = e.s;
				update = true;
			}
		}
		if (!update) break;
		if (i > n) { negative_cycle = true; break; }
	}
	return make_pair(prev, !negative_cycle);
}

//経路復元
//始点から終点までの経路を取得
//終点から親を再帰的に辿り始点に着くまでの経路を反転している
//存在しない場合の戻り値: vector<int>()
vector<int> getPath(int s, int g, vector<int> prev) {
	vector<int> path;
	path.emplace_back(g);
	for (int i = g; i != s; ) {
		if (i == -1)
			return vector<int>();
		path.emplace_back(i = prev[i]);
	}
	reverse(path.begin(), path.end());
	return path;
}

////経路復元(Warshall-Floyd)
////存在しない場合の戻り値: ?
//vector<int> getPath(int s, int g, vector<vector<int>> next) {
//	vector<int> path;
//	for (int i = s; i != g; i = next[i][g])
//		path.emplace_back(i);
//	path.emplace_back(g);
//	return path;
//}
//
////全点対間最短経路 All Pairs Shortest Path バグあり
////Warshall Floyd O(V^3)
////戻り値:
////next[i][j]: iからjへの最短経路におけるiの1つ後の点 辞書順最小
////負閉路なし:true あり:false
//pair<vector<vector<int>>, bool> warshall_floyd(const Graph &g, Matrix &dist) {
//	int n = g.size();
//	dist.assign(n, Array(n, INF));
//	for (int i = 0; i < n; i++) dist[i][i] = 0;
//	for (int i = 0; i < n; i++)
//		for (auto &e : g[i])
//			dist[e.s][e.d] = min(dist[e.s][e.d], e.w);
//	vector<vector<int>> next(n, vector<int>(n));
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)next[i][j] = j;
//	for (int k = 0; k < n; k++)
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++) {
//				if (dist[i][k] == INF || dist[k][j] == INF)continue;
//				if (dist[i][j] > dist[i][k] + dist[k][j]) {
//					dist[i][j] = dist[i][k] + dist[k][j];
//					next[i][j] = next[i][k];
//				}
//				else if (k != i && dist[i][k] + dist[k][j] == dist[i][j])
//					next[i][j] = min(next[i][j], next[i][k]); //辞書順最小
//			}
//	bool negative_cycle = false;
//	for (int i = 0; i < n; i++)
//		if (dist[i][i] != 0)
//			negative_cycle = true;
//	return make_pair(next, !negative_cycle);
//}

//全点対間最短経路 
//Warshall-Floyd O(|V|^3)
//戻り値: 負閉路なし:true あり:false
bool warshallFloyd(const Graph &g, Matrix &dist) {
	int n = g.size();
	dist.assign(n, Array(n, INF));
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			dist[e.s][e.d] = min(dist[e.s][e.d], e.w);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (dist[i][k] == INF || dist[k][j] == INF)continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
	bool negative_cycle = false;
	for (int i = 0; i < n; i++)
		if (dist[i][i] != 0)
			negative_cycle = true;
	return !negative_cycle;
}

//全点対間最短経路
//Warshall-Floyd O(|V|^3)
//インライン版
void warshallFloyd() {
	static const int N = 100;
	static int wf[N][N];
	int n; cin >> n;
	rep(i, 0, n)rep(j, 0, n)wf[i][j] = INF;
	rep(i, 0, n)wf[i][i] = 0;

	int m; cin >> m;
	rep(i, 0, m) {
		int s, d, w; cin >> s >> d >> w;
		wf[s][d] = min(wf[s][d], w);
	}

	rep(k, 0, n)rep(i, 0, n)rep(j, 0, n) {
		if (wf[i][k] != INF&&wf[k][j] != INF)
			wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
	}

	int i, j;

	//iを通る負閉路があるか
	wf[i][i] < 0;

	//iからjへ向かう道であり負閉路を通るものがあるか
	rep(k, 0, n)
		if (wf[i][k] != INF&&wf[k][j] != INF&&wf[k][k] < 0);
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2243165

//全点対間最短経路 
void allPairsShortestPathsByDijkstra(const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
}

//最短経路DAGを構築
//どのような経路を通っても最短経路になる
Graph buildDag(const Graph &g, int s) {
	Graph dag(g.size());
	Array dist; dijkstra(g, s, dist);
	for (auto &es : g)for (auto &e : es)
		if (dist[e.s] + e.w == dist[e.d])
			dag[e.s].emplace_back(e);
	return dag;
}

//トポロジカルソート O(|E|+|V|)
//入次数が0の点と辺を取り除きながらretに突っ込む
vector<int> topologicalSort(const Graph &g) {
	int n = g.size(), k = 0;
	vector<int> ord(n), indeg(n); //入次数
	for (auto &es : g) for (auto &e : es) indeg[e.d]++;
	queue<int> q;
	for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int v = q.front(); q.pop(); ord[k++] = v;
		for (auto &e : g[v]) if (--indeg[e.d] == 0) q.push(e.d);
	}
	return *max_element(indeg.begin(), indeg.end()) == 0 ? ord : vector<int>();
}

#include "UnionFind.cpp"
//無向グラフが連結グラフか判定 O(|E|α(|E|))
bool isConnectedGraph(const Graph &udg) {
	int n = udg.size();
	UnionFind uf(n);
	for (auto &es : udg)for (auto &e : es) uf.unite(e.d, e.s);
	return uf.size == 1;
}

//無向グラフがオイラーグラフか判定（オイラー閉路を持つ）
bool isEulerianGraph(const Graph &udg) {
	if (!isConnectedGraph(udg))return false;
	int n = udg.size();
	vector<int> degree(n, 0);
	for (auto &es : udg)for (auto &e : es) degree[e.d]++, degree[e.s]++;
	dump(degree);
	for (auto &d : degree)if ((d / 2) % 2)return false;
	return true;
}

//無向グラフが準オイラーグラフか判定（閉路でないオイラー路を持つ）
bool isSemiEulerianGraph(const Graph &udg) {
	if (!isConnectedGraph(udg))return false;
	int n = udg.size();
	vector<int> degree(n, 0);
	for (auto &es : udg)for (auto &e : es) degree[e.d]++, degree[e.s]++;
	dump(degree);
	int odd = 0;
	for (auto &d : degree) {
		if ((d / 2) % 2)odd++;
		if (odd > 2)return false;
	}
	return odd == 2;
}

//二次元配列からGraphを生成
Graph build(const vector<vector<char>> &v) {
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
			addArc(g, s, d);
		}
	}
	return g;
}

//二次元配列からGraphを生成
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
			if (v[ni][nj] == '#')addArc(g, s, d, w);
			else addArc(g, s, d, 1);
		}
	}
	return g;
}

//s <= d かつ s1 <= s2 かつ d1 <= d2 を満たすようにソート
void sort(Edges &es) {
	for (auto &e : es)
		if (e.s > e.d)
			swap(e.s, e.d);
	sort(es.begin(), es.end(), [](const Edge &e1, const Edge &e2) {return e1.s == e2.s ? e1.d < e2.d : e1.s < e2.s; });
}