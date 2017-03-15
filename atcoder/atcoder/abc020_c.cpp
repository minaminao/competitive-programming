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
//
//using P = pair<int, int>;
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int H, W, T; cin >> H >> W >> T;
//	P S, G;
//	vector<string> s(H); rep(i, 0, H) {
//		cin >> s[i];
//	}
//	rep(i, 0, H)rep(j, 0, W) {
//		if (s[i][j] == 'S')S = P(i, j);
//		else if (s[i][j] == 'G')G = P(i, j);
//	}
//	vector<int>	di, dj;
//	if (G.first - S.first > 0)
//		di.emplace_back(1);
//	else if (G.first - S.first < 0)
//		di.emplace_back(-1);
//	else
//		di.emplace_back(0);
//	dj.emplace_back(0);
//	if (G.second - S.second > 0)
//		dj.emplace_back(1);
//	else if (G.second - S.second < 0)
//		dj.emplace_back(-1);
//	else
//		dj.emplace_back(0);
//	di.emplace_back(0);
//	dump(di, dj);
//	using State = tuple<int, int, int, int>;
//	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
//	auto bfs = [&](int si, int sj, int gi, int gj) {
//		priority_queue<State, vector<State>, greater<State>> q;
//		q.emplace(0, 0, si, sj);
//		while (q.size()) {
//			int a, b, ci, cj; tie(a, b, ci, cj) = q.top(); q.pop();
//			if (ci == gi&&cj == gj)return make_tuple(a, b);
//			rep(i, 0, 2) {
//				int ni = ci + di[i], nj = cj + dj[i];
//				if (!inrange(ni, nj))continue;
//				if (s[ni][nj] == '#')q.emplace(a + 1, b + 1, ni, nj);
//				else q.emplace(a + 1, b, ni, nj);
//			}
//		}
//	};
//	int a, b;
//	tie(a, b) = bfs(S.first, S.second, G.first, G.second);
//	cout << (T - (a - b)) / b << endl;
//	return 0;
//}