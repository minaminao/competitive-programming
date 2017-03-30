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
	int N; cin >> N;
	string s, t; cin >> s >> t;
	UnionFind uf(10 + 26 + 1);
	vector<bool> f(36);
	rep(i, 0, N) {
		int a = isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
		int b = isdigit(t[i]) ? t[i] - '0' : t[i] - 'A' + 10;
		uf.unite(a, b);
		f[a] = f[b] = true;
		if (i == 0) {
			uf.unite(a, 36);
			uf.unite(b, 36);
		}
	}
	bool top = 0;
	unordered_set<int> st;
	rep(i, 10, 36) {
		if (!f[i])continue;
		bool b = false;
		rep(j, 0, 10) {
			if (uf.same(j, i)) {
				b = true;
			}
		}
		if (b)continue;
		if (uf.same(36, i))top = true;
		st.emplace(uf.root(i));
	}
	dump(st);
	int ans = 1;
	if (top) {
		ans *= 9;
		rep(i, 1, st.size())ans *= 10;
	}
	else {
		rep(i, 0, st.size())ans *= 10;
	}
	cout << ans << endl;
	return 0;
}