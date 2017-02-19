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

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
const int N = 50;

bool inrange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

struct Field {
	vector<vector<char>> f;
	vector<vector<bool>> tmp;
	Field() :f(N, vector<char>(N)), tmp(N, vector<bool>(N)) {}
	void input() {
		rep(i, 0, N)rep(j, 0, N)cin >> f[i][j];
	}
	void erase() {
		rep(j, 0, N) {
			for (int i = N - 1, cnt = 0; i >= 0; i--) {
				if (f[i][j] == '.') {
					cnt++;
				}
				else if (f[i][j] == '-') {
					cnt = 0;
				}
				else {
					f[i + cnt][j] = f[i][j];
					if (cnt != 0)f[i][j] = '.';
				}
			}
		}
	}
	void output() {
		rep(i, 0, N) {
			rep(j, 0, N) {
				cout << f[i][j];
			}
			cout << endl;
		}
	}
	int dfs(char c, int i, int j) {
		if (!inrange(i, j))return 0;
		if (f[i][j] != c)return 0;
		if (tmp[i][j])return 0;
		tmp[i][j] = true;
		int ret = 1;
		rep(k, 0, 4) {
			int ni = i + dy[k], nj = j + dx[k];
			ret += dfs(c, ni, nj);
		}
		//dump(c, i, j, ret);
		return ret;
	}
	int score() {
		tmp.assign(N, vector<bool>(N));
		int o = 0, x = 0;
		rep(i, 0, N) {
			rep(j, 0, N) {
				chmax(o, dfs('o', i, j));
				chmax(x, dfs('x', i, j));
			}
		}
		//dump(o, x);
		return o + x;
	}
};

void simulate(Field f) {
	f.erase();
	f.output();
	dump(f.score());
}

void solve1() {
	Field f, tmp;
	f.input();

	tmp = f;
	tmp.erase();
	int maxi = tmp.score();

	Field ans = f;
	rep(k, 0, 45) {
		char c;
		int cnt = 0;
		int ci = -1, cj = -1;
		//-
		rrep(i, 0, N)rep(j, 0, N) {
			tmp = ans;
			if (tmp.f[i][j] == '.') {
				tmp.f[i][j] = '-';
				cnt++;
				//if (cnt > 100)continue;
			}
			else continue;
			tmp.erase();
			int s = tmp.score();
			if (chmax(maxi, s)) {
				c = '-';
				ci = i, cj = j;
			}
			//dump(i, j, s);
			//tmp.output();
		}
		//+
		cnt = 0;
		rrep(i, 0, N)rep(j, 0, N) {
			tmp = ans;
			if (tmp.f[i][j] == '.') {
				tmp.f[i][j] = '+';
				cnt++;
				//if (cnt > 100)continue;
			}
			else continue;
			tmp.erase();
			int s = tmp.score();
			if (chmax(maxi, s)) {
				c = '+';
				ci = i, cj = j;
			}
			//dump(i, j, s);
			//tmp.output();
		}

		if (ci == -1)break;
		ans.f[ci][cj] = c;
		dump(ci, cj, maxi);
		//simulate(ans);
	}

	ans.output();
}

void solve2() {
	State s;
	cin >> s;

	queue<State> q;
	q.emplace(s);

	State t;

	rep(k, 0, 30) {
		vector<State> v;
		while (q.size()) {
			t = q.front(); q.pop();
			int basescore = t.score;
			rep(i, 0, N)rep(j, 0, N) {
				if (t.f[i][j] != '.')continue;
				int tscore;
				t.f[i][j] = '-';
				tscore = score(t);
				if (tscore >= basescore) {
					if (chmax(basescore, tscore))v.clear();
					//if (tmpscore > basescore) {
					//	basescore = (tmpscore + basescore) / 2;
					v.emplace_back(t);
					v.back().score = tscore;
				}
				t.f[i][j] = '.';

				t.f[i][j] = '+';
				tscore = score(t);
				if (tscore >= basescore) {
					if (chmax(basescore, tscore))v.clear();
					//if (tmpscore > basescore) {
					//	basescore = (tmpscore + basescore) / 2;
					v.emplace_back(t);
					v.back().score = tscore;
				}
				t.f[i][j] = '.';
			}
		}
		sort(all(v));
		dump(v.size(), v[0].score);
		int e = min(H, (int)v.size());
		rep(i, 0, e)q.emplace(v[v.size() - 1 - i]);
	}
	cout << q.front();
}


void solve3() {
	State s;
	cin >> s;

	queue<State> q;
	q.emplace(s);

	State t;
	State a, b;

	rep(k, 0, 30) {
		while (q.size()) {
			t = a = b = q.front(); q.pop();
			rep(i, 0, N)rep(j, 0, N) {
				if (t.f[i][j] != '.')continue;
				int tscore;
				t.f[i][j] = '-';
				tscore = score(t);
				if (a < b)swap(a, b);
				if (tscore >= b.score) {
					b = t;
					b.score = tscore;
				}
				t.f[i][j] = '.';

				t.f[i][j] = '+';
				tscore = score(t);
				if (a < b)swap(a, b);
				if (tscore >= b.score) {
					b = t;
					b.score = tscore;
				}
				t.f[i][j] = '.';
			}
		}
		dump(a.score, b.score);
		q.emplace(a);
		q.emplace(b);
	}
	cout << max(a, b);
}


void io() {
	Field f;
	f.input();
	f.erase();
	f.output();
	dump(f.score());
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve1();
	return 0;
}