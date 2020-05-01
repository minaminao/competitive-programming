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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

struct Dice {
	static const int tbl[6][4];
	int t, f;
	Dice(int top, int front) : t(top), f(front) {}
	int top() { return t; }
	int front() { return f; }
	int right() {
		for (int i = 0; i < 4; i++)
			if (tbl[t - 1][i] == f)
				return tbl[t - 1][(i + 1) % 4];
		return -1;
	}
	int bottom() { return 7 - top(); }
	int left() { return 7 - right(); }
	int rear() { return 7 - front(); }
};
const int Dice::tbl[6][4] = {
	{ 5, 4, 2, 3 },
	{ 3, 1, 4, 6 },
	{ 6, 5, 1, 2 },
	{ 1, 5, 6, 2 },
	{ 1, 3, 6, 4 },
	{ 3, 2, 4, 5 },
};

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
Dice next(int top, int front, int dir) {
	Dice d(top, front);
	switch (dir) {
	case 0: return Dice(d.front(), d.bottom());
	case 1: return Dice(d.left(), d.front());
	case 2: return Dice(d.rear(), d.top());
	case 3: return Dice(d.right(), d.front());
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int n; cin >> n&&n;) {
		using P = pair<int, int>;
		map<P, int> h;
		map<P, int> top;
		rep(i, 0, n) {
			int t, f; cin >> t >> f;
			dump(i, t, f);
			int x = 0, y = 0;
			while (true) {
				int dir = -1, mini = INF;
				rep(k, 0, 4) {
					int nx = x + dx[k], ny = y + dy[k];
					if (h[P(nx, ny)] >= h[P(x, y)])
						continue;
					Dice res = next(t, f, k);
					if (res.top() < 4 && chmin(mini, res.top()))
						dir = k;
				}
				if (dir == -1)
					break;
				Dice res = next(t, f, dir);
				t = res.top(), f = res.front();
				x += dx[dir], y += dy[dir];
				dump(t, f, x, y);
			}
			dump(t, f, x, y);
			h[P(x, y)]++;
			top[P(x, y)] = t;
		}
		vector<int> ans(6);
		for (auto e : top) {
			ans[e.second - 1]++;
		}
		cout << ans[0]; rep(i, 1, ans.size()) { cout << " " << ans[i]; } cout << endl;
	}
	return 0;
}