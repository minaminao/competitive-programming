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


void dfs(const Graph &g, int root) {
	int n = g.size();
	vector<bool> f(n);
	stack<int> st; st.emplace(root);
	while (st.size()) {
		int u = st.top(); st.pop();
		if (f[u])continue;
		f[u] = true;
		/* ���� */
		for (auto &e : g[u]) {
			if (f[e.d])continue;
			/* ���� */
			st.emplace(e.d);
		}
	}
}

void bfs(const Graph &g, int root) {
	int n = g.size();
	vector<bool> f(n);
	queue<int> q; q.emplace(root);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (f[u])continue;
		f[u] = true;
		/* ���� */
		for (auto &e : g[u]) {
			if (f[e.d])continue;
			/* ���� */
			q.emplace(e.d);
		}
	}
}

void solve() {
	auto dfs = [&](const Graph &g, int root) {
		int n = g.size();
		vector<bool> f(n);
		stack<int> st; st.emplace(root);
		while (st.size()) {
			int u = st.top(); st.pop();
			if (f[u])continue;
			f[u] = true;
			/* ���� */
			for (auto &e : g[u]) {
				if (f[e.d])continue;
				/* ���� */
				st.emplace(e.d);
			}
		}
	};
	auto bfs = [&](const Graph &g, int root) {
		int n = g.size();
		vector<bool> f(n);
		queue<int> q; q.emplace(root);
		while (q.size()) {
			int u = q.front(); q.pop();
			if (f[u])continue;
			f[u] = true;
			/* ���� */
			for (auto &e : g[u]) {
				if (f[e.d])continue;
				/* ���� */
				q.emplace(e.d);
			}
		}
	};
}


//�P��n�_�ŒZ�o�H(���H�Ȃ�)
//Dijkstra O((E+V)logV)
//dist: �n�_����e���_�܂ł̍ŒZ����
//�߂�l: �ŒZ�o�H�؂̐e���_(����-1)
vector<int> dijkstra(const Graph &g, int s, Array &dist) {
	int n = g.size();
	assert(s < n);
	enum { WHITE, GRAY, BLACK };
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //�n�_����̍ŒZ���� �q �e
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

//�P��n�_�ŒZ�o�H(���H����)
//Bellman-Ford O(VE)
//dist: �n�_����e���_�܂ł̍ŒZ����
//�߂�l: �ŒZ�o�H�؂̐e���_, ���H�Ȃ�:true ����:false
pair<vector<int>, bool> bellman_ford(const Graph &g, int s, Array &dist) {
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

//�o�H����
//�n�_����I�_�܂ł̌o�H���擾
//�I�_����e���ċA�I�ɒH��n�_�ɒ����܂ł̌o�H�𔽓]���Ă���
//���݂��Ȃ��ꍇ�̖߂�l: vector<int>()
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
////�o�H����(Warshall-Floyd)
////���݂��Ȃ��ꍇ�̖߂�l: ?
//vector<int> get_path(int s, int g, vector<vector<int>> next) {
//	vector<int> path;
//	for (int i = s; i != g; i = next[i][g])
//		path.emplace_back(i);
//	path.emplace_back(g);
//	return path;
//}
//
////�S�_�ΊԍŒZ�o�H All Pairs Shortest Path �o�O����
////Warshall Floyd O(V^3)
////�߂�l:
////next[i][j]: i����j�ւ̍ŒZ�o�H�ɂ�����i��1��̓_ �������ŏ�
////���H�Ȃ�:true ����:false
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
//					next[i][j] = min(next[i][j], next[i][k]); //�������ŏ�
//			}
//	bool negative_cycle = false;
//	for (int i = 0; i < n; i++)
//		if (dist[i][i] != 0)
//			negative_cycle = true;
//	return make_pair(next, !negative_cycle);
//}

//�S�_�ΊԍŒZ�o�H 
//Warshall-Floyd O(V^3)
//�߂�l: ���H�Ȃ�:true ����:false
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

//�S�_�ΊԍŒZ�o�H 
void all_pairs_shortest_paths_by_dijkstra(const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
}

//�ŒZ�o�HDAG���\�z
//�ǂ̂悤�Ȍo�H��ʂ��Ă��ŒZ�o�H�ɂȂ�
Graph build_dag(const Graph &g, int s) {
	Graph dag(g.size());
	Array dist; dijkstra(g, s, dist);
	for (auto &es : g)for (auto &e : es)
		if (dist[e.s] + e.w == dist[e.d])
			dag[e.s].emplace_back(e);
	return dag;
}

//�g�|���W�J���\�[�g O(E+V)
//��������0�̓_�ƕӂ���菜���Ȃ���ret�ɓ˂�����
vector<int> topological_sort(const Graph &g) {
	int n = g.size(), k = 0;
	vector<int> ord(n), indeg(n); //������
	for (auto &es : g) for (auto &e : es) indeg[e.d]++;
	queue<int> Q;
	for (int i = 0; i < n; i++) if (indeg[i] == 0) Q.push(i);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop(); ord[k++] = v;
		for (auto &e : g[v]) if (--indeg[e.d] == 0) Q.push(e.d);
	}
	return *max_element(indeg.begin(), indeg.end()) == 0 ? ord : vector<int>();
}

//Tarjan's off-line lowest common ancestors (dfs�ċA)
//�\�zO(N) �N�G��(1)
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



#include "UnionFind.cpp"

//�ŏ��S���
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

//�ŏ��S���
//Prim O(ElogV)
//r���瓞�B�\�Ȓ��_���Ώ�
//Edge�� bool operator<(const Edge &e)const { return w > e.w; } �ɂ���K�v������
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

//�����O���t���A���O���t������ O(E��(E))
bool is_connected_graph(const Graph &udg) {
	int n = udg.size();
	UnionFind UF(n);
	for (auto &es : udg)for (auto &e : es) UF.unite(e.d, e.s);
	return UF.size == 1;
}

//�����O���t���I�C���[�O���t������i�I�C���[�H�����j
bool is_eulerian_graph(const Graph &udg) {
	if (!is_connected_graph(udg))return false;
	int n = udg.size();
	vector<int> degree(n, 0);
	for (auto &es : udg)for (auto &e : es) degree[e.d]++, degree[e.s]++;
	dump(degree);
	for (auto &d : degree)if ((d / 2) % 2)return false;
	return true;
}

//�����O���t�����I�C���[�O���t������i�H�łȂ��I�C���[�H�����j
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

//�񕔃O���t O(f(N+M)) f�͍ő�}�b�`���O�̐��ō��XN
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
	//�ő�}�b�`���O
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

//�񎟌��z�񂩂�Graph�𐶐�
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
			add_arc(g, s, d);
		}
	}
	return g;
}

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
			if (v[ni][nj] == '#')add_arc(g, s, d, w);
			else add_arc(g, s, d, 1);
		}
	}
	return g;
}


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

//s <= d ���� s1 <= s2 ���� d1 <= d2 �𖞂����悤�ɕ��ׂ�
void sort(Edges &es) {
	for (auto &e : es)
		if (e.s > e.d)
			swap(e.s, e.d);
	sort(es.begin(), es.end(), [](const Edge &e1, const Edge &e2) {return e1.s == e2.s ? e1.d < e2.d : e1.s < e2.s; });
}

//�ӂ��t�ɒ������O���t
Graph reverse(const Graph &g) {
	Graph rg(g.size());
	for (auto &es : g)
		for (auto &e : es)
			rg[e.d].emplace_back(e.d, e.s, e.w);
	return rg;
}

//���A����������
//ret[u] = u �������Ă��鋭�A�������̃C���f�b�N�X
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