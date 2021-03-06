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
//	int n, m, k; cin >> n >> m >> k;
//	using P = pair<int, int>;
//	map<P, int> mp;
//	vector<int> x(k), y(k); rep(i, 0, k) {
//		cin >> x[i] >> y[i];
//		mp[P(x[i], y[i])] = i;
//	}
//	auto inrange = [&](int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; };
//	int ans = 2;
//
//	//左下から
//	UnionFind uf(k);
//	rep(i, 1, n) {
//		
//	}
//
//	rep(i, 0, k) {
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[i] + dx, ny = y[i] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			q.emplace(nidx);
//		}
//	}
//
//	queue<int> q, q2;
//	rep(i, 0, k) {
//		if (x[i] == 0 || y[i] == m - 1) {
//			q.emplace(i);
//		}
//	}
//
//	vector<bool> f(k);
//	vector<bool> tmp(k);
//	while (q.size()) {
//		int idx = q.front(); q.pop();
//		f[idx] = true;
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			q.emplace(nidx);
//		}
//		rep(dx, -2, 3)rep(dy, -2, 3) {
//			if (max(abs(dx), abs(dy)) <= 1)continue;
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			if (tmp[nidx])continue;
//			tmp[nidx] = true;
//			q2.emplace(nidx);
//		}
//	}
//	vector<bool> f2(k);
//	while (q2.size()) {
//		int idx = q2.front(); q2.pop();
//		f2[idx] = true;
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f2[nidx])continue;
//			q2.emplace(nidx);
//		}
//	}
//
//	rep(i, 0, k) {
//		if (x[i] == n - 1 || y[i] == 0) {
//			if (f[i]) {
//				chmin(ans, 0);
//			}
//		}
//	}
//	rep(i, 0, k) {
//		if (x[i] == n - 2 || y[i] == 1) {
//			if (f[i]) {
//				chmin(ans, 1);
//			}
//		}
//		if (x[i] == n - 1 || y[i] == 0) {
//			if (f2[i]) {
//				chmin(ans, 1);
//			}
//		}
//	}
//	dump(ans);
//
//	//右上から
//	q = queue<int>();
//	q2 = queue<int>();
//
//	rep(i, 0, k) {
//		if (x[i] == n - 1 || y[i] == 0) {
//			q.emplace(i);
//		}
//	}
//
//	f = vector<bool>(k);
//	tmp = vector<bool>(k);
//	while (q.size()) {
//		int idx = q.front(); q.pop();
//		f[idx] = true;
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			q.emplace(nidx);
//		}
//		rep(dx, -2, 3)rep(dy, -2, 3) {
//			if (max(abs(dx), abs(dy)) <= 1)continue;
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			if (tmp[nidx])continue;
//			tmp[nidx] = true;
//			q2.emplace(nidx);
//		}
//	}
//	f2 = vector<bool>(k);
//	while (q2.size()) {
//		int idx = q2.front(); q2.pop();
//		f2[idx] = true;
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (!mp.count(P(nx, ny)))continue;
//			int nidx = mp[P(nx, ny)];
//			if (f2[nidx])continue;
//			q2.emplace(nidx);
//		}
//	}
//
//	rep(i, 0, k) {
//		if (x[i] == 0 || y[i] == m - 1) {
//			if (f[i]) {
//				chmin(ans, 0);
//			}
//		}
//	}
//	rep(i, 0, k) {
//		if (x[i] == 1 || y[i] == m - 2) {
//			if (f[i]) {
//				chmin(ans, 1);
//			}
//		}
//		if (x[i] == 0 || y[i] == m - 1) {
//			if (f2[i]) {
//				chmin(ans, 1);
//			}
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}