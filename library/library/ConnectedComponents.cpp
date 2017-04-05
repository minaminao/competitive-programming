#include "GraphTheory.cpp"

//�P�������A���O���t��lowlink
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

//�P�������A���O���t�̊֐ߓ_
vector<int> articulation_points(const Graph &g, int root = 0) {
	/*
	u ����
	u ���֐ߓ_ <=> �q�� 2 �ȏ㑶�݂���

	u �����ȊO
	u ���֐ߓ_ <=> ord[u] <= low[v] �ƂȂ�q v �����݂���
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

//�P�������A���O���t�̋�
Edges bridges(const Graph &g, int root = 0) {
	/*
	e(u, v) �����łȂ� <=> ord[u] >= low[v]
	e(u, v) ���� <=> ord[u] < low[v]
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

//�ӂ��t�ɒ������O���t
Graph reverse(const Graph &g) {
	Graph rg(g.size());
	for (auto &es : g)
		for (auto &e : es)
			rg[e.d].emplace_back(e.d, e.s, e.w);
	return rg;
}

//���A���������� O(|V|+|E|)
//ret[u] = u �������Ă��鋭�A�������̃C���f�b�N�X
vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> cc(n, -1);
	vector<int> post;
	function<void(int, int)> dfs_cc = [&](int u, int cc_id) {
		if (cc[u] != -1)return;
		cc[u] = cc_id;
		for (auto &e : g[u])
			dfs_cc(e.d, cc_id);
		post.emplace_back(u);
	};
	int count_cc = 0;
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, count_cc++);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	int count_scc = 0;
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, count_scc++, cc[u]);
	return scc;
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2244415

//�H�̌��o O(|V|+|E|)
bool detect_cycle(const vector<int> &idx) {
	return find(all(idx), idx.size() - 1) == idx.end();
}
bool detect_cycle(const Graph &g) {
	vector<int> idx = kosaraju(g);
	return find(all(idx), idx.size() - 1) == idx.end();
}

//���A���������� O(|V|+|E|)
//ret[u] = u �������Ă��鋭�A���������̒��_�̃C���f�b�N�X
vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> cc(n, -1);
	vector<int> post;
	function<void(int, int)> dfs_cc = [&](int u, int cc_id) {
		if (cc[u] != -1)return;
		cc[u] = cc_id;
		for (auto &e : g[u])
			dfs_cc(e.d, cc_id);
		post.emplace_back(u);
	};
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, u);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, u, cc[u]);
	return scc;
}
/*
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2244420
cc�Ƃ��Ă���ӏ��͘A�������ł͂Ȃ����B�ł���͈�
�ϐ�����ς�����
*/

bool detect_cycle(const vector<int> &idx) {
	int n = idx.size();
	vector<bool> f(n);
	for (auto &u : idx) {
		if (f[u])return true;
		f[u] = true;
	}
	return false;
}
