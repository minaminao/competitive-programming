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

void eight_queens_puzzle() {
	static const int N = 8;
	static bool row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];
	static bool board[N][N];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(dpos, 0, sizeof(dpos));
	memset(dneg, 0, sizeof(dneg));
	memset(board, 0, sizeof(board));

	auto placeable = [&](int i, int j) {
		return !(row[i] || col[j] || dpos[i + j] || dneg[i - j + N - 1]);
	};

	auto update = [&](int i, int j, bool is_queen) {
		board[i][j] = is_queen;
		row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = is_queen;
	};

	auto input_board1 = [&]() {
		bool invalid = false;
		int n; cin >> n;
		rep(k, 0, n) {
			int i, j; cin >> i >> j;
			if (!placeable(i, j))
				invalid = true;
			update(i, j, true);
		}
		return invalid;
	};

	auto input_board2 = [&]() {
		bool invalid = false;
		rep(i, 0, N) {
			rep(j, 0, N) {
				char c; cin >> c;
				if (c == 'Q') {
					if (!placeable(i, j))
						invalid = true;
					update(i, j, true);
				}
			}
		}
		return invalid;
	};

	auto print_board = [&]() {
		rep(i, 0, N) {
			rep(j, 0, N) {
				if (board[i][j])cout << 'Q';
				else cout << '.';
			}
			cout << endl;
		}
	};

	function<bool(int)> dfs = [&](int i) {
		if (i == N) return true;
		rep(j, 0, N)
			if (board[i][j])
				return dfs(i + 1);

		rep(j, 0, N) {
			if (!placeable(i, j))continue;
			update(i, j, true);
			if (dfs(i + 1))return true;
			update(i, j, false);
		}
		return false;
	};

	if (input_board2()) {
		cout << "No Answer" << endl;
		return;
	}
	if (dfs(0)) {
		print_board();
	}
	else {
		cout << "No Answer" << endl;
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	eight_queens_puzzle();
	return 0;
}