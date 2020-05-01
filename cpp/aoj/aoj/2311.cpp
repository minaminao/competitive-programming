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

const char B = 'o';
const char W = 'x';
const char S = '.';
char board[8][8];

int reversible(char player, int y, int x) {
	if (board[y][x] != S)return 0;
	int ret = 0;
	for (int dy = -1; dy <= 1; dy++)
		for (int dx = -1; dx <= 1; dx++)
			if (!(dy == 0 && dx == 0)) {
				int cnt = 0;
				int yy = y + dy, xx = x + dx;
				while (true) {
					if (!(0 <= yy && yy < 8 && 0 <= xx && xx < 8))break;
					char c = board[yy][xx];
					if (c == S) break;
					if (c == player) {
						ret += cnt;
						break;
					}
					yy += dy; xx += dx;
					cnt++;
				}
			}
	return ret;
}

void reverse(char player, int y, int x, int dy, int dx) {
	int yy = y + dy, xx = x + dx;
	while (true) {
		if (!(0 <= yy && yy < 8 && 0 <= xx && xx < 8)) return;
		char c = board[yy][xx];
		if (c == S) return;
		if (c == player) break;
		yy += dy; xx += dx;
	}
	while (true) {
		yy -= dy; xx -= dx;
		if (yy == y && xx == x) break;
		board[yy][xx] = player;
	}
}

void reverse(char player, int y, int x) {
	assert(reversible(player, y, x));
	board[y][x] = player;
	for (int dy = -1; dy <= 1; dy++)
		for (int dx = -1; dx <= 1; dx++)
			if (!(dy == 0 && dx == 0))
				reverse(player, y, x, dy, dx);
}

pair<int, int> status() {
	int cntB = 0, cntW = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			char c = board[y][x];
			if (c == B) cntB++;
			if (c == W) cntW++;
		}
	}
	return make_pair(cntB, cntW);
}

signed main() {
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			cin >> board[y][x];
	while (true) {
		int Bx, By, Bmaxcnt = 0;
		rep(y, 0, 8)rep(x, 0, 8)
			if (chmax(Bmaxcnt, reversible(B, y, x)))
				Bx = x, By = y;
		if (Bmaxcnt)reverse(B, By, Bx);
		int Wx, Wy, Wmaxcnt = 0;
		rrep(y, 0, 8)rrep(x, 0, 8)
			if (chmax(Wmaxcnt, reversible(W, y, x)))
				Wx = x, Wy = y;
		if (Wmaxcnt)reverse(W, Wy, Wx);
		if (Bmaxcnt == 0 && Wmaxcnt == 0)break;
	}
	rep(i, 0, 8) {
		rep(j, 0, 8) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}
