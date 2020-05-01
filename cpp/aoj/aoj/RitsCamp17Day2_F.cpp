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
//bool f[100010], f2[100010], tmp[100010];
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
//	//¶‰º‚©‚ç
//	queue<int> q, q2;
//	rep(i, 0, k) {
//		if (x[i] == 0 || y[i] == m - 1) {
//			q.emplace(i);
//		}
//	}
//
//	memset(f, 0, sizeof(f));
//	memset(tmp, 0, sizeof(tmp));
//	while (q.size()) {
//		int idx = q.front(); q.pop();
//		if (f[idx])continue;
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
//			if (mp.find(P(nx, ny)) == mp.end())continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			if (tmp[nidx])continue;
//			tmp[nidx] = true;
//			q2.emplace(nidx);
//		}
//	}
//	memset(f2, 0, sizeof(f2));
//	while (q2.size()) {
//		int idx = q2.front(); q2.pop();
//		if (f2[idx])continue;
//		f2[idx] = true;
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (mp.find(P(nx, ny)) == mp.end())continue;
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
//	//‰Eã‚©‚ç
//	//q = queue<int>();
//	//q2 = queue<int>();
//
//	rep(i, 0, k) {
//		if (x[i] == n - 1 || y[i] == 0) {
//			q.emplace(i);
//		}
//	}
//
//	memset(f, 0, sizeof(f));
//	memset(tmp, 0, sizeof(tmp));
//	while (q.size()) {
//		int idx = q.front(); q.pop();
//		if (f[idx])continue;
//		f[idx] = true;
//		rep(dx, -1, 2)rep(dy, -1, 2) {
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (mp.find(P(nx, ny)) == mp.end())continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			q.emplace(nidx);
//		}
//		rep(dx, -2, 3)rep(dy, -2, 3) {
//			if (max(abs(dx), abs(dy)) <= 1)continue;
//			int nx = x[idx] + dx, ny = y[idx] + dy;
//			if (!inrange(nx, ny))continue;
//			if (mp.find(P(nx, ny)) == mp.end())continue;
//			int nidx = mp[P(nx, ny)];
//			if (f[nidx])continue;
//			if (tmp[nidx])continue;
//			tmp[nidx] = true;
//			q2.emplace(nidx);
//		}
//	}
//	memset(f2, 0, sizeof(f2));
//	while (q2.size()) {
//		int idx = q2.front(); q2.pop();
//		if (f2[idx])continue;
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