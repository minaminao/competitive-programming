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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

using Weight = int;
struct Edge {
	int s, d; Weight w;
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w) {};
	bool operator<(const Edge &e)const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += MOD;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
template <int M>
ostream &operator << (ostream &os, const ModInt<M> &m) { return os << m.x; }
template <int M>
istream &operator >> (istream &is, ModInt<M> &m) { signed long long s; is >> s; m = ModInt<M>(s); return is; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

using mint = ModInt<1000000007>;

//–¢’Tõ, ’Tõ’†, ’TõÏ
enum { WHITE, GRAY, BLACK };
//’Pˆên“_Å’ZŒo˜H(•‰•Â˜H‚È‚µ)
//Dijkstra O((E+V)logV)
//dist: n“_‚©‚çŠe’¸“_‚Ü‚Å‚ÌÅ’Z‹——£
//–ß‚è’l: Å’ZŒo˜H–Ø‚Ìe’¸“_(ª‚Í-1)
vector<int> dijkstra(const Graph &g, int s, vector<Weight> &dist) {
	int n = g.size();
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //n“_‚©‚ç‚ÌÅ’Z‹——£ q e
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop(); //dist‚ªÅ¬‚Æ‚È‚éState‚ğæ‚èo‚·
		if (dist[v] < d)continue; //‚·‚Å‚ÉÅ’Z‚Å‚È‚¯‚ê‚Î–³‹
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

//‘S“_‘ÎŠÔÅ’ZŒo˜H 
void all_pairs_shortest_paths_by_dijkstra(const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
}

//Å’ZŒo˜HDAG‚ğ\’z
//‚Ç‚Ì‚æ‚¤‚ÈŒo˜H‚ğ’Ê‚Á‚Ä‚àÅ’ZŒo˜H‚É‚È‚é
Graph build_dag(const Graph &g, int s) {
	Graph dag(g.size());
	Array dist; dijkstra(g, s, dist);
	for (auto &es : g)for (auto &e : es)
		if (dist[e.s] + e.w == dist[e.d])
			dag[e.s].emplace_back(e);
	return dag;
}

signed main() {
	int N; cin >> N;
	int a, b; cin >> a >> b; a--, b--;
	int M; cin >> M;
	vector<int> x(M), y(M); rep(i, 0, M) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	Graph g(N);
	rep(i, 0, M) {
		g[x[i]].emplace_back(x[i], y[i]);
		g[y[i]].emplace_back(y[i], x[i]);
	}

	Graph dag = build_dag(g, a);

	vector<mint> dp(N, 0);
	dp[a] = 1;
	queue<pair<int, int>> q; q.emplace(a, 0);
	vector<bool> f(N);
	while (q.size()) {
		auto p = q.front(); q.pop();
		int s = p.first;
		if (f[s])continue;
		f[s] = true;
		dump(s, dp[s]);
		if (s == b)break;
		for (auto &e : dag[s]) {
			dp[e.d] += dp[s];
			q.emplace(e.d, p.second + 1);
		}
	}
	cout << dp[b] << endl;
	return 0;
}