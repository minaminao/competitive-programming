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
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//using State = pair<int, vector<P>>;
////State dfs3(int p, int q, int cnt) {
////	if (!inrange(p, q))return State(0, vector<P>());
////	if (s[p][q] == '0')return State(0, vector<P>());
////	if (f[p][q])return State(0, vector<P>());
////	if (cnt == 0)return State(0, vector<P>());
////	else if (cnt == 1)return State(t[p][q], vector<P>(1, P(p, q)));
////	f[p][q] = true;
////	vector<P> ret;
////	char maxi = '0';
////	rep(i, 0, 4) {
////		int ni = p + dy[i], nj = q + dx[i];
////		State res = dfs3(ni, nj, cnt - 1);
////		if (res.second.size() != cnt - 1)continue;
////		//if (chmax(maxi, s[ni][nj]))
////		//	ret = res;
////		{
////			ret = res;
////			break;
////		}
////	}
////	ret.emplace_back(p, q);
////	f[p][q] = false;
////	return ret;
////}
//
//vector<P> search(int p, int q) {
//	if (!inrange(p, q))return vector<P>();
//	if (s[p][q] == '0')return vector<P>();
//	if (f[p][q])return vector<P>();
//	if (cnt == 0)return vector<P>();
//	else if (cnt == 1)return vector<P>(1, P(p, q));
//	f[p][q] = true;
//	vector<P> ret;
//	char maxi = '0';
//	rep(i, 0, 4) {
//		int ni = p + dy[i], nj = q + dx[i];
//		vector<P> res = dfs(ni, nj, cnt - 1);
//		if (res.size() != cnt - 1)continue;
//		if (chmax(maxi, s[ni][nj]))
//			ret = res;
//	}
//	ret.emplace_back(p, q);
//	f[p][q] = false;
//	return ret;
//}
//
//vector<P> dfs(int p, int q, int cnt) {
//	if (!inrange(p, q))return vector<P>();
//	if (s[p][q] == '0')return vector<P>();
//	if (f[p][q])return vector<P>();
//	if (cnt == 0)return vector<P>();
//	else if (cnt == 1)return vector<P>(1, P(p, q));
//	f[p][q] = true;
//	vector<P> ret;
//	char maxi = '0';
//	rep(i, 0, 4) {
//		int ni = p + dy[i], nj = q + dx[i];
//		vector<P> res = dfs(ni, nj, cnt - 1);
//		if (res.size() != cnt - 1)continue;
//		if (chmax(maxi, s[ni][nj]))
//			ret = res;
//	}
//	ret.emplace_back(p, q);
//	f[p][q] = false;
//	return ret;
//}
//
//void solve4() {
//	vector<vector<P>> ans;
//	rep(i, 0, H)rep(j, 0, W) {
//		if (f[i][j])continue;
//		vector<P> res = dfs(i, j, 8);
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
//void solve1() {
//	cout << 50 * 6 + 2 * 6 << endl;
//	rep(i, 0, 50) {
//		rep(j, 0, 8 * 6) {
//			cout << i + 1 << " " << j + 1 << endl;
//		}
//	}
//	rep(j, 48, 50) {
//		rep(i, 0, 8 * 6) {
//			cout << i + 1 << " " << j + 1 << endl;
//		}
//	}
//}
//
//
//void solve5() {
//	vector<vector<P>> ans;
//	vector<pair<int, P>> ps;
//	rep(i, 0, H)rep(j, 0, W) {
//		ps.emplace_back(t[i][j], P(i, j));
//	}
//	sort(all(ps));
//	reverse(all(ps));
//
//	rep(k, 0, H*W) {
//		P p = ps[k].second;
//		int i = p.first, j = p.second;
//		if (f[i][j])continue;
//		vector<P> res = dfs(i, j, 8);
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
//void solve3() {
//	vector<vector<P>> ans;
//	vector<pair<int, P>> ps;
//	rep(i, 0, H)rep(j, 0, W) {
//		ps.emplace_back(t[i][j], P(i, j));
//	}
//	sort(all(ps));
//	reverse(all(ps));
//
//	rep(k, 0, H*W) {
//		P p = ps[k].second;
//		int i = p.first, j = p.second;
//		if (f[i][j])continue;
//		vector<P> res = dfs(i, j, 8);
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
//void solve2() {
//	vector<vector<P>> ans;
//	rep(i, 0, H)rep(j, 0, W) {
//		if (f[i][j])continue;
//		vector<P> res = dfs(i, j, 8);
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
//	solve3();
//	return 0;
//}