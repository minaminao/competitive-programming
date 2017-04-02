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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K, L; cin >> N >> K >> L;
	UnionFind uf1(N), uf2(N);
	rep(i, 0, K) {
		int p, q; cin >> p >> q; p--, q--;
		uf1.unite(p, q);
	}
	rep(i, 0, L) {
		int r, s; cin >> r >> s; r--, s--;
		uf2.unite(r, s);
	}
	using P = pair<int, int>;
	map<P, int> cnt;
	rep(i, 0, N) {
		cnt[P(uf1.root(i), uf2.root(i))]++;
	}
	vector<int> ans(N);
	rep(i, 0, N) {
		ans[i] = cnt[P(uf1.root(i), uf2.root(i))];
	}
	cout << ans[0]; rep(i, 1, ans.size()) { cout << " " << ans[i]; } cout << endl;
	return 0;
}