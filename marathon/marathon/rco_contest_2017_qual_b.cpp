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
//int di[4] = { 0,1,0,-1 };
//int dj[4] = { 1,0,-1,0 };
//char dir[4] = { 'R','D','L','U' };
//
//
//int H, W, K, sr, sc;
//char s[51][51];
//int N;
//int fr[2510], fc[2510], F[2510], D[2510];
//
//bool inrange(int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; }
//
//void output(string ans) {
//	if (ans.size() >= 2500) {
//		cout << ans.substr(0, 2500) << endl;
//	}
//	else {
//		ans += string(2500 - ans.size(), '-');
//		cout << ans << endl;
//	}
//}
//
//string ans = "";
//bool ate[2510];
//string bfs() {
//	int d[51][51] = {};
//	int t = ans.size();
//	memset(d, 0x3f, sizeof(d));
//	using P = tuple<int, int, string>;
//	queue<P> q;
//	q.emplace(sr, sc, "");
//	while (q.size()) {
//		int ci, cj; string r; tie(ci, cj, r) = q.front(); q.pop();
//		if (!inrange(ci, cj))continue;
//		if (s[ci][cj] == '#')continue;
//		if (d[ci][cj] != INF)continue;
//		d[ci][cj] = r.size();
//		rep(i, 0, N) {
//			if (ate[i])continue;
//			if (ci == fr[i] && cj == fc[i]) {
//				if (F[i] - D[i] * (t + r.size()) > 0) {
//					sr = ci, sc = cj;
//					ate[i] = true;
//					return r;
//				}
//			}
//		}
//		rep(i, 0, 4) {
//			int ni = ci + di[i], nj = cj + dj[i];
//			q.emplace(ni, nj, r + dir[i]);
//		}
//	}
//	return "";
//}
//
//void solve() {
//	rep(i, 0, N) {
//		ans += bfs();
//	}
//	output(ans);
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> H >> W >> K >> sr >> sc; sr--, sc--;
//	rep(i, 0, H)rep(j, 0, W)cin >> s[i][j];
//	cin >> N;
//	rep(i, 0, N) {
//		cin >> fr[i] >> fc[i] >> F[i] >> D[i];
//		fr[i]--, fc[i]--;
//	}
//	solve();
//	return 0;
//}