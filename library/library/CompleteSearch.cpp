/*
bfs‚ªŽÀ‘•‚Å‚«‚éê‡Astack‚ðŽg‚Á‚½dfs‚Å‚àŽÀ‘•‚Å‚«‚é
*/

//dxdy
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };
char dir[4] = { 'R','D','L','U' };
//rep(dy, -1, 2) rep(dx, -1, 2);

//“ñŽŸŒ³‚ÅÀ•W‚ª”ÍˆÍ“à‚É‚ ‚é‚©‚Ç‚¤‚©‚ð‚Ü‚Æ‚ß‚Ä”»’è
int R, C;
bool inrange(int i, int j) { return i >= 0 && i < R && j >= 0 && j < C; }
int X, Y;
bool inrange(int x, int y) { return x >= 0 && x < X && y >= 0 && y < Y; }

//xyÀ•W‚Å‚Ì[‚³—Dæ’Tõ
void dfs(int x, int y) {
	/* “®ì */
	//ˆÚ“®4•ûŒü‚Ì’Tõ
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (inrange(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

//ƒOƒŠƒbƒhã‚Å‚Ì•—Dæ’Tõ
//Å’Z‹——£
void bfs() {
	int H, W, K; cin >> H >> W;
	vector<vector<char>> v(H, vector<char>(W));
	int si, sj;
	rep(i, 0, H) rep(j, 0, W) {
		cin >> v[i][j];
		if (v[i][j] == 'S')si = i, sj = j;
	}

	vector<vector<int>> d(H, vector<int>(W, INF));
	d[si][sj] = 0;

	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	static const int di[] = { 1,0,-1,0 };
	static const int dj[] = { 0,1,0,-1 };

	using P = pair<int, int>;
	queue<P> q;
	q.push(P(si, sj));
	for (int ci, cj; !q.empty();) {
		tie(ci, cj) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i], nj = cj + dj[i];
			if (!inrange(ni, nj))continue;
			if (v[ni][nj] == '#')continue;
			if (d[ni][nj] != INF)continue;
			d[ni][nj] = d[ci][cj] + 1;
			q.push(P(ni, nj));
		}
	}
}

void solve() {
	vector<string> v;
	int H, W;

	using State = tuple<int, int, int>;
	vector<vector<bool>> f(H, vector<bool>(W));
	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	auto bfs = [&](int si, int sj, int gi, int gj) {
		queue<State> q;
		q.emplace(0, si, sj);
		while (q.size()) {
			int d, ci, cj; tie(d, ci, cj) = q.front(); q.pop();
			if (ci == gi&&cj == gj)return d;
			rep(i, 0, 4) {
				int ni = ci + di[i], nj = cj + dj[i];
				if (!inrange(ni, nj))continue;
				if (f[ni][nj])continue;
				f[ni][nj] = true;
				q.emplace(d + 1, ni, nj);
			}
		}
	};
}