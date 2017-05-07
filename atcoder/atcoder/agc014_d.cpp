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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	if (N % 2) {
		cout << "First" << endl;
		return 0;
	}

	Graph g(N);
	rep(i, 0, N - 1) {
		int a, b; cin >> a >> b; a--, b--;
		add_edge(g, a, b);
	}
	vector<int> degree(N, 0);
	for (auto &es : g)for (auto &e : es) degree[e.d]++, degree[e.s]++;

	vector<int> idx(N);
	iota(all(idx), 0);

	tied_sort(degree, idx);
	reverse(all(degree));
	reverse(all(idx));

	dump(degree, idx);
	for (int i = 0; i < N; i++)
		degree[i] /= 2;


	using P = pair<int, int>;
	map<P, int> mp;

	vector<bool> vis(N);
	function<int(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return 0;
		if (mp.count(P(u, p)))
			return mp[P(u, p)];
		vis[u] = true;
		int ret = 0;
		ret++;
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			ret += dfs(e.d, u);
		}
		return mp[P(u, p)] = ret;
	};



	for (int i = 0; i < N; i++) {
		if (degree[i] <= 2)break;
		vis.assign(N, false);
		vis[idx[i]] = true;
		int odd = 0;
		for (auto &e : g[idx[i]]) {
			int cnt = dfs(e.d, idx[i]);
			dump(e.d, cnt);
			if (cnt % 2)odd++;
		}
		dump(odd);
		if (odd >= 2) {
			cout << "First" << endl;
			return 0;
		}
	}
	dump(mp);
	cout << "Second" << endl;
	return 0;
}