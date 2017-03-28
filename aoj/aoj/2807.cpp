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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	double p; cin >> p;
	int N; cin >> N;
	Graph g(N);
	rep(i, 0, N - 1) {
		int x, y, c; cin >> x >> y >> c;
		x--, y--;
		add_edge(g, x, y, c);
	}
	vector<int> d = depth(g, 0);
	double a = 0;
	auto dfs = [&](const Graph &g, int root) {
		int n = g.size();
		vector<bool> f(n);
		stack<int> st; st.emplace(root);
		while (st.size()) {
			int u = st.top(); st.pop();
			f[u] = true;
			for (auto &e : g[u]) {
				if (f[e.d])continue;
				a += e.w * pow(p, d[e.d]);
				st.emplace(e.d);
			}
		}
	};
	dfs(g, 0);
	dump(a);
	double ans = a;
	auto dfs2 = [&](const Graph &g, int root) {
		int n = g.size();
		vector<bool> f(n);
		stack<int> st; st.emplace(root);
		while (st.size()) {
			int u = st.top(); st.pop();
			f[u] = true;
			ans += a * pow(p, d[u]);
			for (auto &e : g[u]) {
				if (f[e.d])continue;
				st.emplace(e.d);
			}
		}
	};
	dfs2(g, 0);
	cout << ans << endl;
	return 0;
}