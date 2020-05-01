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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

#define N 8
bool row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];
bool X[N][N];

void print_board() {
	rep(i, 0, N) {
		rep(j, 0, N) {
			if (X[i][j])cout << 'Q';
			else cout << '.';
		}
		cout << endl;
	}
}

void dfs(int i) {
	if (i == N) {
		print_board();
		return;
	}
	rep(j, 0, N) {
		if (X[i][j]) {
			dfs(i + 1);
			return;
		}
	}

	rep(j, 0, N) {
		if (row[i] || col[j] || dpos[i + j] || dneg[i - j + N - 1])continue;
		X[i][j] = true;
		row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = true;
		dfs(i + 1);
		X[i][j] = false;
		row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = false;
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, 0, n) {
		int y, x; cin >> y >> x;
		X[y][x] = true;
		row[y] = col[x] = dpos[y + x] = dneg[y - x + N - 1] = true;
	}
	dfs(0);
	return 0;
}