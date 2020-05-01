//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
////素集合データ構造
//using P = pair<int, int>;
//struct UnionFind {
//	vector<int> parent;
//	int size;
//	UnionFind(int n) :parent(n, -1), size(n) {}
//	map<P, int> key;
//	bool unite(int x, int y) {
//		x = root(x); y = root(y);
//		if (x == y)return false;
//		if (size_of(x) < size_of(y))swap(x, y);
//		parent[x] += parent[y]; parent[y] = x; size--;
//		return true;
//	}
//	bool same(int x, int y) { return root(x) == root(y); }
//	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
//	int size_of(int x) { return -parent[root(x)]; }
//	void add(P p) {
//		if (key.count(p))return;
//		key[p] = parent.size();
//		parent.emplace_back(-1);
//		size++;
//	}
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, M; cin >> N >> M;
//	UnionFind UF(0);
//	rep(i, 0, M) {
//		int u, v; cin >> u >> v;
//		u--, v--;
//		UF.add(P(u, v));
//		UF.add(P(v, u));
//		UF.add(P(u, u));
//		UF.add(P(v, v));
//		UF.unite(UF.key[P(u, v)], UF.key[P(v, u)]);
//		UF.unite(UF.key[P(u, u)], UF.key[P(v, v)]);
//	}
//	dump(N*N, UF.parent.size(), UF.size);
//	cout << N*N - (UF.parent.size() - UF.size) << endl;
//	return 0;
//}