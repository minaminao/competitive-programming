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

struct UnionFind {
	vector<int> parent;
	vector<bool> cycle;
	int size;
	UnionFind(int n) :parent(n, -1), size(n), cycle(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) {
			cycle[x] = true;
			return false;
		}
		if (cycle[x] || cycle[y])cycle[x] = cycle[y] = true;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
	bool has_cycle(int x) { return cycle[root(x)]; }
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<int> u(M), v(M); rep(i, 0, M) { cin >> u[i] >> v[i]; u[i]--, v[i]--; }
	UnionFind uf(N);
	rep(i, 0, M) {
		uf.unite(u[i], v[i]);
	}
	vector<bool> f(N);
	int cnt = 0;
	rep(i, 0, N) {
		int e = uf.root(i);
		if (f[e])continue;
		f[e] = true;
		if (!uf.cycle[e])cnt++;
	}
	cout << cnt << endl;
	return 0;
}