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
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//struct UnionFind {
//	vector<int> parent;
//	int size;
//	UnionFind(int n) :parent(n, -1), size(n) {}
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
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, K, Q; cin >> N >> K >> Q;
//	vector<vector<char>> s(N, vector<char>(N));
//	rep(i, 0, N) rep(j, 0, N) { cin >> s[i][j]; }
//	UnionFind uf(N*N);
//	auto inrange = [&](int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; };
//	static const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
//	rep(i, 0, N) {
//		rep(j, 0, N) {
//			if (s[i][j] == '#')continue;
//			rep(k, 0, 4) {
//				int ni = i + di[k], nj = j + dj[k];
//				if (!inrange(ni, nj))continue;
//				if (s[ni][nj] == '#')continue;
//				uf.unite(i*N + j, ni*N + nj);
//			}
//		}
//	}
//	rep(i, 0, Q) {
//		int a, b, c, d; cin >> a >> b >> c >> d;
//		a--, b--, c--, d--;
//		if (uf.same(a*N + b, c*N + d)) {
//			cout << "Yes" << endl;
//		}
//		else {
//			cout << "No" << endl;
//		}
//	}
//	return 0;
//}