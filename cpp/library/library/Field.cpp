//chokudai003_a.cpp

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