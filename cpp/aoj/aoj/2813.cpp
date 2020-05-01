#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

void add_arc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void add_edge(Graph &g, int a, int b, Weight w = 1) {
	add_arc(g, a, b, w);
	add_arc(g, b, a, w);
}

struct Node {
	int size;
	int t;
	int p;
	Node(int size, int t) :size(size), t(t), p(-1) {};
};

template<class T, class ...Tail>
void tied_sort(vector<T> &a, vector<Tail>&... tail) {
	int n = a.size();
	using S = tuple<T, Tail...>;
	vector<S> s(n);
	for (int i = 0; i < n; i++)
		s[i] = make_tuple(a[i], tail[i]...);
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		tie(a[i], tail[i]...) = s[i];
}

struct UnionFind {
	vector<int> parent;
	vector<int> idx;
	int size;
	UnionFind(int n) :parent(n, -1), size(n), idx(n) {
		iota(all(idx), 0);
	}
	bool unite(int x, int y, int i) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		idx[x] = idx[y] = i;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
	int get_idx(int x) { return idx[root(x)]; }
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, T; cin >> N >> M >> T;
	Graph g(N);
	vector<int> a(M), b(M), t(M); rep(i, 0, M) {
		cin >> a[i] >> b[i] >> t[i];
		a[i]--, b[i]--;
		add_edge(g, a[i], b[i], t[i]);
	}
	vector<bool> f(N);
	using State = pair<int, int>;
	queue<State> q; q.emplace(0, 0);
	while (q.size()) {
		int u, ut;
		tie(u, ut) = q.front(); q.pop();
		if (f[u])continue;
		f[u] = true;
		for (auto &e : g[u]) {
			if (f[e.d])continue;
			if (e.w <= ut)continue;
			q.emplace(e.d, ut + 1);
		}
	}
	vector<Node> tree;
	rep(i, 0, N) {
		tree.emplace_back(1, T);
	}
	tied_sort(t, a, b);
	UnionFind uf(N);
	rrep(i, 0, M) {
		int ai = uf.get_idx(a[i]), bi = uf.get_idx(b[i]);
		dump(ai, bi);
		uf.unite(a[i], b[i], tree.size());
		tree.emplace_back(uf.size_of(a[i]), t[i]);
		tree[ai].p = tree.size() - 1;
		tree[bi].p = tree.size() - 1;
	}
	vector<int> dp(tree.size(), -1);
	rrep(i, 0, tree.size()) {
		Node s = tree[i];
		int score = 0;
		if (s.p == -1) {
			score = (s.t)*s.size;
		}
		else {
			score = dp[s.p] + (s.t - tree[s.p].t)*s.size;
		}
		dp[i] = score;
	}
	int ans = 0;
	rep(i, 0, N) {
		if (!f[i])continue;
		chmax(ans, dp[i]);
		//Node s = tree[i];
		//int score = 0;
		//while (true) {
		//	if (s.p == -1)break;
		//	dump(s.t, s.size, s.p, tree[s.p].p);
		//	score += (s.t - tree[s.p].t)*s.size;
		//	dump(score);
		//	s = tree[s.p];
		//}
		//score += (s.t)*s.size;
		//dump(i, score);
		//chmax(ans, score);
	}
	cout << ans << endl;
	return 0;
}