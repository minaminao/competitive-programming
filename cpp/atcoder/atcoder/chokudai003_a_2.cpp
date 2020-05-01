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

static const int dx[4] = { 1,-1,0,0 };
static const int dy[4] = { 0,0,1,-1 };
static const int N = 50;
static const int H = 2;
vector<vector<bool>> flag(N, vector<bool>(N));

inline bool inrange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

struct State {
	int score;
	vector<vector<char>> f;
	State() :score(0), f(N, vector<char>(N)) {};
	State(int score, vector<vector<char>> f) :score(score), f(f) {};
	bool operator<(const State &s)const { return score < s.score; }
};

void erase(State &s) {
	rep(j, 0, N) {
		for (int i = N - 1, cnt = 0; i >= 0; i--) {
			if (s.f[i][j] == '.')
				cnt++;
			else if (s.f[i][j] == '-')
				cnt = 0;
			else {
				s.f[i + cnt][j] = s.f[i][j];
				if (cnt != 0)s.f[i][j] = '.';
			}
		}
	}
}
int dfs(const State &s, char c, int i, int j) {
	if (!inrange(i, j))return 0;
	if (s.f[i][j] != c)return 0;
	if (flag[i][j])return 0;
	flag[i][j] = true;
	int ret = 1;
	rep(k, 0, 4) {
		int ni = i + dy[k], nj = j + dx[k];
		ret += dfs(s, c, ni, nj);
	}
	return ret;
}
//”ñ”j‰ó“I
int score(State s) {
	erase(s);
	flag.assign(N, vector<bool>(N));
	int o = 0, x = 0;
	rep(i, 0, N) {
		rep(j, 0, N) {
			chmax(o, dfs(s, 'o', i, j));
			chmax(x, dfs(s, 'x', i, j));
		}
	}
	return o + x;
}
inline ostream &operator<<(ostream &os, const State &s) {
	rep(i, 0, N) {
		rep(j, 0, N)
			cout << s.f[i][j];
		cout << endl;
	}
	return os;
}
inline istream &operator >> (istream &is, State &s) {
	rep(i, 0, N)rep(j, 0, N)cin >> s.f[i][j];
	s.score = score(s);
	return is;
}

void solve4() {
	State s;
	cin >> s;

	priority_queue<State> q;
	q.emplace(s);

	State t, u(-1, s.f);
	State ans = s;

	rep(k, 0, 34) {
		t = q.top(); q.pop();
		dump(k, t.score);
		chmax(ans, t);
		if (k % 2 == 1 && q.size()) {
			u = q.top();
			q.pop();
			chmax(ans, u);
			int basescore = u.score;
			rep(i, 0, N)rep(j, 0, N) {
				bool changed = false;
				if (u.f[i][j] == '.') {
					int uscore;
					u.f[i][j] = '-';
					uscore = score(u);
					if (chmax(basescore, uscore)) {
						q.emplace(uscore, u.f);
					}
					u.f[i][j] = '.';

					u.f[i][j] = '+';
					uscore = score(u);
					if (chmax(basescore, uscore)) {
						q.emplace(uscore, u.f);
					}
					u.f[i][j] = '.';
				}
				else if (u.f[i][j] == '+') {
					int uscore;
					u.f[i][j] = '.';
					uscore = score(u);
					if (chmax(basescore, uscore)) {
						q.emplace(uscore, u.f);
					}
					u.f[i][j] = '+';
				}
				else if (u.f[i][j] == '-') {
					int uscore;
					u.f[i][j] = '.';
					uscore = score(u);
					if (chmax(basescore, uscore)) {
						q.emplace(uscore, u.f);
					}
					u.f[i][j] = '-';
				}
			}
		}
		{
			int basescore = t.score;
			rep(i, 0, N)rep(j, 0, N) {
				bool changed = false;
				if (t.f[i][j] == '.') {
					int tscore;
					t.f[i][j] = '-';
					tscore = score(t);
					if (chmax(basescore, tscore)) {
						q.emplace(tscore, t.f);
					}
					t.f[i][j] = '.';

					t.f[i][j] = '+';
					tscore = score(t);
					if (chmax(basescore, tscore)) {
						q.emplace(tscore, t.f);
					}
					t.f[i][j] = '.';
				}
				else if (t.f[i][j] == '+') {
					int tscore;
					t.f[i][j] = '.';
					tscore = score(t);
					if (chmax(basescore, tscore)) {
						q.emplace(tscore, t.f);
					}
					t.f[i][j] = '+';
				}
				else if (t.f[i][j] == '-') {
					int tscore;
					t.f[i][j] = '.';
					tscore = score(t);
					if (chmax(basescore, tscore)) {
						q.emplace(tscore, t.f);
					}
					t.f[i][j] = '-';
				}
			}
		}
	}
	if (q.size())cout << max(q.top(), ans);
	else cout << ans;
}

void io() {
	State s;
	cin >> s;
	dump(score(s));
	erase(s);
	cout << s;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve4();
	return 0;
}