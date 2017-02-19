const char B = 'o';
const char W = 'x';
const char S = '.';
char board[8][8];

//playerが(x,y)に置いたときに相手の駒をいくつ裏返せるか
//両プレイヤーが0のとき試合終了
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
			board[y][x] = '.';
	board[3][3] = board[4][4] = 'W';
	board[3][4] = board[4][3] = 'B';

	int turn; cin >> turn;
	for (int i = 0; i < turn; i++) {
		rep(i, 0, 8) {
			rep(j, 0, 8)
				cout << board[i][j];
			cout << endl;
		}
		char player; int x, y;
		cin >> player >> x >> y; x--, y--;
		reverse(player, y, x);
	}
	int cntB = 0, cntW = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			char c = board[y][x];
			if (c == 'B') cntB++;
			if (c == 'W') cntW++;
		}
	}
	auto s = status();
	int cntB = s.first, cntW = s.second;
	printf("%02d-%02d %s\n", cntB, cntW, cntB == cntW ? "Draw!" : cntB > cntW ? "The black won!" : "The white won!");
	return 0;
}
