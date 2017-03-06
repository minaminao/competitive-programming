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

//未探索, 探索中, 探索済
enum { WHITE, GRAY, BLACK };

//単一始点最短経路(負閉路なし)
//Dijkstra O((E+V)logV)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
vector<int> dijkstra(const Graph &g, int s, vector<Weight> &dist) {
	int n = g.size();
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //distが最小となるStateを取り出す
		if (dist[v] < d)continue; //すでに最短でなければ無視
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
//Bellman-Ford O(VE)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点, 負閉路なし:true あり:false
pair<vector<int>, bool> bellman_ford(const Graph &g, int s, vector<Weight> &dist) {
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
////経路復元(Warshall-Floyd)
////存在しない場合の戻り値: ?
//vector<int> get_path(int s, int g, vector<vector<int>> next) {
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
//Warshall-Floyd O(V^3)
//戻り値: 負閉路なし:true あり:false
bool warshall_floyd(const Graph &g, Matrix &dist) {
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
void all_pairs_shortest_paths_by_dijkstra(const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
}

//最短経路DAGを構築
//どのような経路を通っても最短経路になる
Graph build_dag(const Graph &g, int s) {
	Graph dag(g.size());
	Array dist; dijkstra(g, s, dist);
	for (auto &es : g)for (auto &e : es)
		if (dist[e.s] + e.w == dist[e.d])
			dag[e.s].emplace_back(e);
	return dag;
}

//トポロジカルソート O(E+V)
//入次数が0の点と辺を取り除きながらretに突っ込む
vector<int> topological_sort(const Graph &g) {
	int n = g.size(), k = 0;
	vector<int> ord(n), indeg(n); //入次数
	for (auto &es : g) for (auto &e : es) indeg[e.d]++;
	queue<int> Q;
	for (int i = 0; i < n; i++) if (indeg[i] == 0) Q.push(i);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop(); ord[k++] = v;
		for (auto &e : g[v]) if (--indeg[e.d] == 0) Q.push(e.d);
	}
	return *max_element(indeg.begin(), indeg.end()) == 0 ? ord : vector<int>();
}

//木の直径
Edge diameter(const Graph &g, int s = 0) {
	vector<Weight> dist;
	dijkstra(g, s, dist);
	int n = g.size(), u = -1, v = -1;
	for (int i = 0; i < n; i++) if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
	dijkstra(g, u, dist);
	for (int i = 0; i < n; i++) if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
	Weight d = dist[v];
	if (u > v) swap(u, v);
	return Edge(u, v, d);
}

//木の高さ
//戻り値: 各頂点からの最遠距離
vector<Weight> height(const Graph &g) {
	Edge e = diameter(g);
	vector<Weight> dist1, dist2;
	dijkstra(g, e.s, dist1);
	dijkstra(g, e.d, dist2);
	int n = g.size();
	vector<Weight> height(n);
	for (int i = 0; i < n; i++)
		height[i] = max(dist1[i], dist2[i]);
	return height;
}

//Tarjan's off-line lowest common ancestors (dfs再帰)
//構築O(N) クエリ(1)
struct Query {
	int u, v;
	Query(int u, int v) :u(u), v(v) {}
};
struct LowestCommonAncestor {
	vector<vector<pair<int, Query>>> query_set;
	Graph g;
	vector<int> color;
	vector<int> ancestor;
	vector<int> res;
	UnionFind uf;
	LowestCommonAncestor(const Graph &g, vector<Query> &query) :g(g), color(g.size()), ancestor(g.size()), uf(g.size()), res(query.size()), query_set(g.size()) {
		int n = query.size();
		for (int i = 0; i < n; i++) {
			query_set[query[i].u].emplace_back(i, query[i]);
			query_set[query[i].v].emplace_back(i, query[i]);
		}
	}
	void visit(int s, int prev) {
		ancestor[uf.root(s)] = s;
		for (auto &e : g[s]) {
			if (e.d == prev)continue;
			visit(e.d, s);
			uf.unite(e.s, e.d);
			ancestor[uf.root(s)] = s;
		}
		color[s] = 1;
		for (auto &p : query_set[s]) {
			Query q = p.second;
			int w = (q.v == s ? q.u : q.u == s ? q.v : -1);
			if (w == -1 || !color[w])continue;
			res[p.first] = ancestor[uf.root(w)];
		}
	}
	vector<int> solve(int root) {
		int n = g.size();
		UnionFind uf(n);
		vector<int> color(n), ancestor(n);
		visit(root, -1);
		return res;
	}
};


//lowest common ancestor (ダブリング + dfs再帰)
//構築O(NlogN) クエリO(logN)
struct LowestCommonAncestor {
	const int n, log2_n;
	vector<vector<int>> parent;
	vector<int> depth;
	const Graph &g;
	LowestCommonAncestor(const Graph &g, int root)
		:g(g), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)), depth(n) {
		dfs(root, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < n; v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
	void dfs(int s, int p, int d) {
		parent[0][s] = p;
		depth[s] = d;
		for (auto &e : g[s]) {
			if (e.d == p)continue;
			dfs(e.d, s, d + 1);
		}
	}
	int get(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

//lowest common ancestor (ダブリング + dfs非再帰)
//構築O(NlogN) クエリO(logN)
struct LowestCommonAncestor {
	const Graph &g;
	const int root, n, log2_n;
	vector<vector<int>> parent;
	vector<int> depth;
	LowestCommonAncestor(const Graph &g, int root)
		:g(g), root(root), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)), depth(n) {
		dfs();
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < n; v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
	void dfs() {
		using State = tuple<int, int, int>;
		stack<State> st; st.emplace(root, -1, 0);
		while (st.size()) {
			int s, p, d; tie(s, p, d) = st.top(); st.pop();
			parent[0][s] = p;
			depth[s] = d;
			for (auto &e : g[s]) {
				if (e.d == p)continue;
				st.emplace(e.d, s, d + 1);
			}
		}
	}
	int get(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

//#include "UnionFind.cpp"
//素集合データ構造
struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
};

//最小全域木
//Kruskal O(|E|log|E|)
pair<Weight, Edges> kruskal(const Graph &g) {
	UnionFind UF(g.size());
	Edges es;
	for (int i = 0; i < g.size(); i++) for (auto &e : g[i]) es.emplace_back(e);
	sort(es.begin(), es.end());
	Weight total = 0;
	Edges T;
	for (auto &e : es) if (!UF.same(e.s, e.d)) {
		T.push_back(e); total += e.w; UF.unite(e.s, e.d);
	}
	return make_pair(total, T);
}

//最小全域木
//Prim O(ElogV)
//rから到達可能な頂点が対象
//Edgeを bool operator<(const Edge &e)const { return w > e.w; } にする必要がある
pair<Weight, Edges> prim(const Graph &g, int r = 0) {
	Edges T; Weight total = 0; vector<int> v(g.size());
	priority_queue <Edge> q;
	q.emplace(-1, r, 0);
	while (q.size()) {
		Edge e = q.top(); q.pop();
		if (v[e.d]) continue;
		v[e.d] = true;
		total += e.w; if (e.s != -1) T.emplace_back(e);
		for (auto &f : g[e.d]) if (!v[f.d]) q.emplace(f);
	}
	return make_pair(total, T);
}

//無向グラフが連結グラフか判定 O(Eα(E))
bool is_connected_graph(const Graph &udg) {
	int n = udg.size();
	UnionFind UF(n);
	for (auto &es : udg)for (auto &e : es) UF.unite(e.d, e.s);
	return UF.size == 1;
}

//無向グラフがオイラーグラフか判定（オイラー閉路を持つ）
bool is_eulerian_graph(const Graph &udg) {
	if (!is_connected_graph(udg))return false;
	int n = udg.size();
	vector<int> degree(n, 0);
	for (auto &es : udg)for (auto &e : es) degree[e.d]++, degree[e.s]++;
	dump(degree);
	for (auto &d : degree)if ((d / 2) % 2)return false;
	return true;
}

//無向グラフが準オイラーグラフか判定（閉路でないオイラー路を持つ）
bool is_semi_eulerian_graph(const Graph &udg) {
	if (!is_connected_graph(udg))return false;
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

//二部グラフ O(f(N+M)) fは最大マッチングの数で高々N
class BipartiteMatching {
public:
	int n;
	vector<vector<int>> g;
	vector<int> match;
	BipartiteMatching(int n) : n(n), g(n), match(n), used(n) {}
	void add_edge(int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	//最大マッチング
	int maximum_matching() {
		int ret = 0;
		fill(match.begin(), match.end(), -1);
		for (int v = 0; v < n; v++) {
			if (match[v] == -1) {
				fill(used.begin(), used.end(), false);
				if (dfs(v)) ret++;
			}
		}
		return ret;
	}
private:
	vector<int> used;
	bool dfs(int v) {
		used[v] = true;
		for (int u : g[v]) {
			int w = match[u];
			if (w == -1 || (!used[w] && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
};