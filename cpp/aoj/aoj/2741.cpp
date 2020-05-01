//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n, m; cin >> n >> m;
//	vector<int> a(n); rep(i, 0, n) {
//		cin >> a[i];
//	}
//	vector<int> b(m); rep(i, 0, m) {
//		cin >> b[i];
//	}
//	using T = tuple<int, int, int, int, int, bool>;
//	queue<T> q;
//	q.emplace(n, m, n, m, 0, 0);
//	static int dp[51][51][51][51][2][3];
//	static bool flag[51][51][51][51][2][3];
//	dp[n][m][n][m][0][0] = 0;
//	flag[n][m][n][m][0][0] = true;
//	while (q.size()) {
//		int x, y, px, py, pass, f;
//		tie(x, y, px, py, pass, f) = q.front(); q.pop();
//		dump(x, y, px, py, pass, f, dp[x][y][px][py][pass][f]);
//		int tmp;
//		if (f) { // player 2
//			if (y) {
//				if (b[m - y] == -1) {
//					tmp = dp[x][y][px][py][pass][f];
//					if (!flag[x][y - 1][x][py][0][!f]) {
//						flag[x][y - 1][x][py][0][!f] = true;
//						dp[x][y - 1][x][py][0][!f] = tmp;
//						q.emplace(x, y - 1, x, py, 0, !f);
//					}
//					else if (chmin(dp[x][y - 1][x][py][0][!f], tmp))
//						q.emplace(x, y - 1, x, py, 0, !f);
//				}
//				else {
//					tmp = dp[x][y][px][py][pass][f];
//
//					if (!flag[x][y - 1][px][py][0][!f]) {
//						flag[x][y - 1][px][py][0][!f] = true;
//						dp[x][y - 1][px][py][0][!f] = tmp;
//						q.emplace(x, y - 1, px, py, 0, !f);
//					}
//					else if (chmin(dp[x][y - 1][px][py][0][!f], tmp))
//						q.emplace(x, y - 1, px, py, 0, !f);
//				}
//			}
//			if (pass < 2) {
//				if (y != py) {
//					tmp = dp[x][y][px][py][pass][f];
//					for (int cx = px; cx > x; cx--) {
//						if (a[n - cx] > 0)
//							tmp += a[n - cx];
//					}
//					for (int cy = py; cy > y; cy--) {
//						if (b[m - cy] > 0)
//							tmp -= b[m - cy];
//					}
//					if (!flag[x][y][x][y][pass + 1][!f]) {
//						flag[x][y][x][y][pass + 1][!f] = true;
//						dp[x][y][x][y][pass + 1][!f] = tmp;
//						q.emplace(x, y, x, y, pass + 1, !f);
//					}
//					else if (chmin(dp[x][y][x][y][pass + 1][!f], tmp))
//						q.emplace(x, y, x, y, pass + 1, !f);
//				}
//				else if (y == 0) {
//					tmp = dp[x][y][px][py][pass][f];
//					for (int cx = px; cx > x; cx--) {
//						if (a[n - cx] > 0)
//							tmp += a[n - cx];
//					}
//					for (int cy = py; cy > y; cy--) {
//						if (b[m - cy] > 0)
//							tmp -= b[m - cy];
//					}
//					if (!flag[x][y][x][y][pass + 1][!f]) {
//						flag[x][y][x][y][pass + 1][!f] = true;
//						dp[x][y][x][y][pass + 1][!f] = tmp;
//						q.emplace(x, y, x, y, pass + 1, !f);
//					}
//					else if (chmin(dp[x][y][x][y][pass + 1][!f], tmp))
//						q.emplace(x, y, x, y, pass + 1, !f);
//				}
//			}
//		}
//		else {
//			if (x) {
//				if (a[n - x] == -1) {
//					tmp = dp[x][y][px][py][pass][f];
//					if (!flag[x - 1][y][px][y][0][!f]) {
//						flag[x - 1][y][px][y][0][!f] = true;
//						dp[x - 1][y][px][y][0][!f] = tmp;
//						q.emplace(x - 1, y, px, y, 0, !f);
//					}
//					else if (chmax(dp[x - 1][y][px][y][0][!f], tmp))
//						q.emplace(x - 1, y, px, y, 0, !f);
//				}
//				else {
//					tmp = dp[x][y][px][py][0][f];
//
//					if (!flag[x - 1][y][px][py][0][!f]) {
//						flag[x - 1][y][px][py][0][!f] = true;
//						dp[x - 1][y][px][py][0][!f] = tmp;
//						q.emplace(x - 1, y, px, py, 0, !f);
//					}
//					else if (chmax(dp[x - 1][y][px][py][0][!f], tmp))
//						q.emplace(x - 1, y, px, py, 0, !f);
//				}
//			}
//			if (pass < 2) {
//				if (x != px) {
//					tmp = dp[x][y][px][py][pass][f];
//					for (int cx = px; cx > x; cx--) {
//						if (a[n - cx] > 0)
//							tmp += a[n - cx];
//					}
//					for (int cy = py; cy > y; cy--) {
//						if (b[m - cy] > 0)
//							tmp -= b[m - cy];
//					}
//					if (!flag[x][y][x][y][pass + 1][!f]) {
//						flag[x][y][x][y][pass + 1][!f] = true;
//						dp[x][y][x][y][pass + 1][!f] = tmp;
//						q.emplace(x, y, x, y, pass + 1, !f);
//					}
//					else if (chmax(dp[x][y][x][y][pass + 1][!f], tmp))
//						q.emplace(x, y, x, y, pass + 1, !f);
//				}
//				else if (x == 0) {
//					tmp = dp[x][y][px][py][pass][f];
//					for (int cx = px; cx > x; cx--) {
//						if (a[n - cx] > 0)
//							tmp += a[n - cx];
//					}
//					for (int cy = py; cy > y; cy--) {
//						if (b[m - cy] > 0)
//							tmp -= b[m - cy];
//					}
//					if (!flag[x][y][x][y][pass + 1][!f]) {
//						flag[x][y][x][y][pass + 1][!f] = true;
//						dp[x][y][x][y][pass + 1][!f] = tmp;
//						q.emplace(x, y, x, y, pass + 1, !f);
//					}
//					else if (chmin(dp[x][y][x][y][pass + 1][!f], tmp))
//						q.emplace(x, y, x, y, pass + 1, !f);
//				}
//			}
//		}
//	}
//	int ans1 = INF;
//	rep(f, 0, 2) {
//		if (flag[0][0][0][0][2][f])
//			dump(f, dp[0][0][0][0][2][f]);
//	}
//	return 0;
//}