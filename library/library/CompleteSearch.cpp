/*
bfs�������ł���ꍇ�Astack���g����dfs�ł������ł���
*/

//dxdy
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };
char dir[4] = { 'R','D','L','U' };

//�񎟌��ō��W���͈͓��ɂ��邩�ǂ������܂Ƃ߂Ĕ���
int R, C;
bool inrange(int i, int j) { return i >= 0 && i < R && j >= 0 && j < C; }
int X, Y;
bool inrange(int x, int y) { return x >= 0 && x < X && y >= 0 && y < Y; }

//xy���W�ł̐[���D��T��
void dfs(int x, int y) {
	/* ���� */
	//�ړ�4�����̒T��
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (inrange(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

//xy���W�ł̕��D��T��
//�ŒZ����
void bfs() {
	cin >> R >> C;
	int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
	sy--, sx--, gy--, gx--;
	vector<vector<char>> c(R, vector<char>(C, 0));
	rep(i, 0, R) rep(j, 0, C) { cin >> c[i][j]; }

	//�ŒZ����
	vector<vector<int>> d(R, vector<int>(C, INF));
	d[sy][sx] = 0;

	using pii = pair<int, int>;
	queue<pii> Q;
	Q.push(pii(sy, sx));
	for (pii u; !Q.empty();) {
		u = Q.front(); Q.pop();
		if (u == pii(gy, gx))break; //�S�[���Ȃ�T�����I���
		for (int i = 0; i < 4; i++) {
			int ny = u.first + dy[i], nx = u.second + dx[i];
			if (!inrange(ny, nx))continue;
			if (c[ny][nx] == '#')continue;
			if (d[ny][nx] != INF)continue;
			d[ny][nx] = d[u.first][u.second] + 1;
			Q.push(pii(ny, nx));
		}
	}
	cout << d[gy][gx] << endl;
}


bool f[100][100] = {};
int d[100][100] = {};

//�O���b�h��̕��D��T��
using P = pair<int, int>;
P bfs(int si, int sj) {
	P ret;
	int maxd = 0;
	d[si][sj] = 0;

	queue<P> Q;
	Q.push(P(si, sj));
	for (P u; !Q.empty();) {
		u = Q.front(); Q.pop();
		//if (u == pii(gy, gx))break; //�S�[���Ȃ�T�����I���
		for (int i = 0; i < 4; i++) {
			int ni = u.first + di[i], nj = u.second + dj[i];
			if (!inrange(ni, nj))continue;
			if (!f[ni][nj])continue;
			if (d[ni][nj] != INF)continue;
			d[ni][nj] = d[u.first][u.second] + 1;
			Q.push(P(ni, nj));
			if (chmax(maxd, d[ni][nj]))ret = P(ni, nj);
		}
	}
	return ret;
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