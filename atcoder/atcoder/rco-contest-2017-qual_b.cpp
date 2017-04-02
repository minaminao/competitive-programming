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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };
char dir[4] = { 'R','D','L','U' };


int H, W, K, sr, sc;
char s[51][51];
int N;
int fr[2510], fc[2510], F[2510], D[2510];
bool flag[51][51];
bool flagever[51][51];

bool inrange(int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; }

string bfs(int si, int sj, int gi, int gj) {
	//dump(si, sj, gi, gj);
	memset(flag, false, sizeof(flag));
	using State = tuple<int, int, string>;
	queue<State> q;
	q.emplace(si, sj, "");
	while (q.size()) {
		int ci, cj; string ret;
		tie(ci, cj, ret) = q.front(); q.pop();
		//dump(ci, cj, ret);
		if (!inrange(ci, cj))continue;
		if (flag[ci][cj])continue;
		flag[ci][cj] = true;
		if (ci == gi&&cj == gj)return ret;
		//dump(ci, cj, s[ci][cj]);
		if (s[ci][cj] == '#')continue;
		rep(i, 0, 4) {
			int ni = ci + di[i], nj = cj + dj[i];
			q.emplace(ni, nj, ret + dir[i]);
		}
	}
	return "";
}

bool flagbfs2[2510];
string bfs2(int &si, int &sj) {
	//dump(si, sj, gi, gj);
	memset(flag, false, sizeof(flag));
	using State = tuple<int, int, string>;
	queue<State> q;
	q.emplace(si, sj, "");
	while (q.size()) {
		int ci, cj; string ret;
		tie(ci, cj, ret) = q.front(); q.pop();
		//dump(ci, cj, ret);
		if (!inrange(ci, cj))continue;
		if (flag[ci][cj])continue;
		flag[ci][cj] = true;
		rep(i, 0, N) {
			if (flagbfs2[i])continue;
			if (ci == fr[i] && cj == fc[i]) {
				si = ci, sj = cj;
				flagbfs2[i] = true;
				return ret;
			}
		}
		//dump(ci, cj, s[ci][cj]);
		if (s[ci][cj] == '#')continue;
		rep(i, 0, 4) {
			int ni = ci + di[i], nj = cj + dj[i];
			q.emplace(ni, nj, ret + dir[i]);
		}
	}
	return "";
}

void mark(int si, int sj, string s) {
	/*
	int di[4] = { 0,1,0,-1 };
	int dj[4] = { 1,0,-1,0 };
	char dir[4] = { 'R','D','L','U' };
	*/
	flagever[si][sj] = true;
	for (auto &c : s) {
		if (c == 'R')flagever[si][++sj] = true;
		else if (c == 'D')flagever[++si][sj] = true;
		else if (c == 'L')flagever[si][--sj] = true;
		else if (c == 'U')flagever[--si][sj] = true;
	}
}

void output(string ans) {
	if (ans.size() >= 2500) {
		cout << ans.substr(0, 2500) << endl;
	}
	else {
		ans += string(2500 - ans.size(), '-');
		cout << ans << endl;
	}
}

void solve5() {
	using Food = tuple<int, int, int, int>; // D F fr fc
}

void solve4() {
	int ci = sr, cj = sc;
	string ans = "";
	rep(i, 0, N) {
		dump(ci, cj);
		ans += bfs2(ci, cj);
	}
	output(ans);
}

void solve3() {
	string ans = bfs(sr, sc, fr[0], fc[0]);
	mark(sr, sc, ans);
	int ci = fr[0], cj = fc[0];
	rep(i, 0, N - 1) {
		int ni = fr[i + 1], nj = fc[i + 1];
		if (flagever[ni][nj])continue;
		string res = bfs(ci, cj, ni, nj);
		mark(ci, cj, res);
		ci = ni, cj = nj;
		ans += res;
	}
	output(ans);
}

void solve2() {
	string ans = bfs(sr, sc, fr[0], fc[0]);
	rep(i, 0, N - 1) {
		ans += bfs(fr[i], fc[i], fr[i + 1], fc[i + 1]);
	}
	output(ans);
}

void solve1() {
	string ans = bfs(sr, sc, fr[0], fc[0]);
	output(ans);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> H >> W >> K >> sr >> sc; sr--, sc--;
	rep(i, 0, H)rep(j, 0, W)cin >> s[i][j];
	cin >> N;
	rep(i, 0, N) {
		cin >> fr[i] >> fc[i] >> F[i] >> D[i];
		fr[i]--, fc[i]--;
	}
	solve4();
	return 0;
}