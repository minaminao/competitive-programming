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
//int H, W, K;
//char s[51][51];
//int t[51][51];
//bool f[51][51];
//
//bool inrange(int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; }
//
//using P = pair<int, int>;
//int di[4] = { 0,1,0,-1 };
//int dj[4] = { 1,0,-1,0 };
//
//using State = tuple<int, P>;
//vector<P> bfs(int si, int sj) {
//	priority_queue<State> pq;
//	pq.emplace(t[si][sj], P(si, sj));
//	vector<P> ret;
//	while (ret.size() != 8 && pq.size()) {
//		int s, s2; P p, p2;
//		tie(s, p) = pq.top(); pq.pop();
//		dump(p.first, p.second);
//		if (pq.size()) {
//			tie(s2, p2) = pq.top(); pq.pop();
//			int maxi = 0, maxi2 = 0;
//			rep(i, 0, 4) {
//				int ti = p.first + di[i], tj = p.second + dj[i];
//				int ti2 = p2.first + di[i], tj2 = p2.second + dj[i];
//				if (!inrange(ti, tj) || !inrange(ti2, tj2))continue;
//				if (!f[ti][tj])chmax(maxi, t[ti][tj]);
//				if (!f[ti2][tj2])chmax(maxi2, t[ti2][tj2]);
//			}
//			dump(s, maxi, s2, maxi2);
//			maxi *= s; maxi2 *= s2;
//			if (maxi < maxi2) {
//				pq.emplace(s, p);
//				s = s2, p = p2;
//				dump("maxi<max2");
//			}
//			else {
//				pq.emplace(s2, p2);
//			}
//		}
//		int ci = p.first, cj = p.second;
//		dump(p.first, p.second);
//		if (f[ci][cj])continue;
//		f[ci][cj] = true;
//		ret.emplace_back(ci, cj);
//		rep(i, 0, 4) {
//			int ti = ci + di[i], tj = cj + dj[i];
//			if (!inrange(ti, tj))continue;
//			if (t[ti][tj] == 0)continue;
//			pq.emplace(t[ti][tj], P(ti, tj));
//		}
//	}
//	return ret;
//}
//
//void solve5() {
//	vector<vector<P>> ans;
//	vector<pair<int, P>> ps;
//	rep(i, 0, H)rep(j, 0, W) {
//		if (t[i][j] == 0)continue;
//		ps.emplace_back(t[i][j], P(i, j));
//	}
//	sort(all(ps));
//	reverse(all(ps));
//
//	rep(k, 0, ps.size()) {
//		P p = ps[k].second;
//		int i = p.first, j = p.second;
//		if (f[i][j])continue;
//		vector<P> res = bfs(i, j);
//		if (res.size() != 8)continue;
//		rep(k, 0, res.size()) {
//			f[res[k].first][res[k].second] = true;
//		}
//		ans.emplace_back(res);
//	}
//
//	cout << ans.size() << endl;
//	rep(i, 0, ans.size()) {
//		rep(j, 0, ans[i].size()) {
//			cout << ans[i][j].first + 1 << " " << ans[i][j].second + 1 << endl;
//		}
//	}
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> H >> W >> K;
//	rep(i, 0, H) rep(j, 0, W) {
//		cin >> s[i][j];
//		t[i][j] = s[i][j] - '0';
//	}
//	memset(f, false, sizeof(f));
//	solve5();
//	return 0;
//}