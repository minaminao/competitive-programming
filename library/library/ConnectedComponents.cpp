#include "GraphTheory.cpp"

//単純無向連結グラフのlowlink
pair<vector<int>, vector<int>> lowlink(const Graph &g, int root = 0) {
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	int o = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
	};
	dfs(root, -1);
	return make_pair(ord, low);
}

//単純無向連結グラフの関節点
vector<int> articulation_points(const Graph &g, int root = 0) {
	/*
	u が根
	u が関節点 <=> 子が 2 つ以上存在する

	u が根以外
	u が関節点 <=> ord[u] <= low[v] となる子 v が存在する
	*/
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	vector<int> art;
	int o = 0;
	int child = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		if (p == root)child++;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		bool is_art = false;
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
				if (u != root&&ord[u] <= low[e.d])is_art = true;
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
		if (is_art)art.emplace_back(u);
	};
	dfs(root, -1);
	if (child >= 2)art.emplace_back(root);
	sort(art.begin(), art.end());
	return art;
}

//単純無向連結グラフの橋
Edges bridges(const Graph &g, int root = 0) {
	/*
	e(u, v) が橋でない <=> ord[u] >= low[v]
	e(u, v) が橋 <=> ord[u] < low[v]
	*/
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	Edges bri;
	int o = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		bool is_art = false;
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
				if (ord[u] < low[e.d])bri.emplace_back(u, e.d);
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
	};
	dfs(root, -1);
	return bri;
}

//辺を逆に張ったグラフ
Graph reverse(const Graph &g) {
	Graph rg(g.size());
	for (auto &es : g)
		for (auto &e : es)
			rg[e.d].emplace_back(e.d, e.s, e.w);
	return rg;
}

//強連結成分分解 O(|V|+|E|)
//ret[u] = u が属している強連結成分のインデックス
vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> in(n, -1);
	vector<int> post;
	function<void(int, int)> dfs = [&](int u, int idx) {
		if (in[u] != -1)return;
		in[u] = idx;
		for (auto &e : g[u]) {
			if (in[e.d] != -1)continue;
			dfs(e.d, idx);
		}
		post.emplace_back(u);
	};
	int idx = 0;
	for (int u = 0; u < n; u++) {
		if (in[u] == -1) {
			dfs(u, idx++);
		}
	}
	vector<int> in2(n, -1);
	function<void(int, int, int)> dfs2 = [&](int u, int idx, int idx2) {
		if (in2[u] != -1)return;
		if (in[u] != idx)return;
		in2[u] = idx2;
		for (auto &e : rg[u]) {
			if (in2[e.d] != -1)continue;
			if (in[e.d] != idx)continue;
			dfs2(e.d, idx, idx2);
		}
	};
	int idx2 = 0;
	reverse(post.begin(), post.end());
	for (auto &u : post) {
		if (in2[u] == -1) {
			dfs2(u, in[u], idx2++);
		}
	}
	return in2;
}

//閉路の検出 O(|V|+|E|)
bool cycle_detection(const Graph &g) {
	vector<int> res = kosaraju(g);
	return find(all(res), g.size() - 1) == res.end();
}