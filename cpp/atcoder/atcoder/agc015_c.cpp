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
//	int N, M, Q; cin >> N >> M >> Q;
//	vector<vector<bool>> S(N, vector<bool>(M));
//	rep(i, 0, N) rep(j, 0, M) {
//		char c; cin >> c;
//		if (c == '1')
//			S[i][j] = true;
//	}
//
//	vector<vector<int>> v(N, vector<int>(M));
//	rep(i, 0, N)rep(j, 0, M) {
//		if (S[i][j])
//			v[i][j] = 1;
//	}
//
//	vector<vector<int>> sum(v);
//	rep(i, 1, N)rep(j, 1, M) {
//		sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//	}
//	dump(sum);
//
//	vector<vector<int>> h(N - 1, vector<int>(M));
//	vector<vector<int>> w(N, vector<int>(M - 1));
//
//	rep(i, 0, N - 1)rep(j, 0, M) {
//		if (S[i][j] && S[i + 1][j])
//			h[i][j] = 1;
//	}
//	rep(i, 0, N)rep(j, 0, M - 1) {
//		if (S[i][j] && S[i][j + 1])
//			w[i][j] = 1;
//	}
//
//	rep(i, 0, N - 1)rep(j, 0, M - 1) {
//		h[i][j + 1] += h[i][j];
//		w[i + 1][j] += w[i][j];
//	}
//
//	dump(h);
//	dump(w);
//
//	rep(i, 0, N - 1) {
//		v[i + 1][0] += v[i][0];
//		if (S[i + 1][0] && S[i][0])
//			v[i + 1][0]--;
//	}
//
//	rep(j, 0, M - 1) {
//		v[0][j + 1] += v[0][j];
//		if (S[0][j + 1] && S[0][j])
//			v[0][j + 1]--;
//	}
//	dump(v);
//
//	rep(i, 1, N)rep(j, 1, M) {
//		v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1]
//			- h[i - 1][j - 1] - w[i - 1][j - 1];
//		dump(v[i - 1][j], v[i][j - 1], v[i - 1][j - 1]
//			, h[i - 1][j - 1], w[i - 1][j - 1]);
//		dump(i, j, v[i][j]);
//		if (S[i][j]) {
//			if (S[i - 1][j] && S[i][j - 1])v[i][j]--;
//		}
//		dump(i, j, v[i][j]);
//	}
//
//	dump(v);
//
//	rep(i, 0, Q) {
//		int a, b, c, d; cin >> a >> b >> c >> d;
//	}
//	return 0;
//}