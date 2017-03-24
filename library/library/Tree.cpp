/*
基本的には木もグラフ同様、Graphを使えばいい
*/

#include "GraphTheory.cpp"

//preorder と inorder から postorder を構築
vector<int> reconstruct_tree(const vector<int> &pre, const vector<int> &in) {
	vector<int> post;
	int pos = 0;
	function<void(int, int)> rec = [&](int l, int r) {
		if (l >= r)return;
		int root = pre[pos++];
		int m = distance(in.begin(), find(in.begin(), in.end(), root));
		rec(l, m);
		rec(m + 1, r);
		post.emplace_back(root);
	};
	rec(0, pre.size());
	return post;
}


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

//木の直径
Edge diameter(const Graph &g, int s = 0) {
	Array dist;
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
Array height(const Graph &g) {
	Edge e = diameter(g);
	Array dist1, dist2;
	dijkstra(g, e.s, dist1);
	dijkstra(g, e.d, dist2);
	int n = g.size();
	Array height(n);
	for (int i = 0; i < n; i++)
		height[i] = max(dist1[i], dist2[i]);
	return height;
}

//木の深さ
//戻り値: 各ノードから根ノードまでのエッジ数
vector<int> depth(const Graph &g, int root) {
	vector<int> ret(g.size(), INF);
	using State = tuple<int, int, int>;
	stack<State> st; st.emplace(root, -1, 0);
	while (st.size()) {
		int s, p, d; tie(s, p, d) = st.top(); st.pop();
		ret[s] = d;
		for (auto &e : g[s]) {
			if (e.d == p)continue;
			st.emplace(e.d, s, d + 1);
		}
	}
	return ret;
}