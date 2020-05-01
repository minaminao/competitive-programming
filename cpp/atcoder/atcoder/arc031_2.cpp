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

const int H = 10, W = 10;
char a[H][W];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int cnto = 0;
	rep(i, 0, H)rep(j, 0, W) {
		cin >> a[i][j];
		if (a[i][j] == 'o')cnto++;
	}
	UnionFind uf(H*W);
	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	static const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
	rep(i, 0, H)rep(j, 0, W) {
		if (a[i][j] == 'x')continue;
		rep(k, 0, 4) {
			int ni = i + di[k], nj = j + dj[k];
			if (!inrange(ni, nj))continue;
			if (a[ni][nj] == 'x')continue;
			uf.unite(i*W + j, ni*W + nj);
		}
	}
	bool flag = true;
	rep(i, 0, H)rep(j, 0, W) {
		if (a[i][j] == 'x')continue;
		if (uf.size_of(i*W + j) < cnto) {
			flag = false;
		}
	}
	if (flag) {
		cout << "YES" << endl;
		return 0;
	}
	rep(i, 0, H)rep(j, 0, W) {
		UnionFind uf2 = uf;
		if (a[i][j] == 'o')continue;
		rep(k, 0, 4) {
			int ni = i + di[k], nj = j + dj[k];
			if (!inrange(ni, nj))continue;
			if (a[ni][nj] == 'x')continue;
			uf2.unite(i*W + j, ni*W + nj);
		}
		if (uf2.size_of(i*W + j) == cnto + 1) {
			flag = true;
		}
	}
	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}