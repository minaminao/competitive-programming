//�Œ�����������
int longest_increasing_subsequence(const vector<int> &v) {
	int n = v.size();
	vector<int> dp(n, INF);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
	return find(dp.begin(), dp.end(), INF) - dp.begin();
}

void solve() {
	//dp�� & 1 ���g���Ƌ�Ԃ� 2�� �ōς�
	int dp[2];
	int i; dp[i & 1]; dp[(i + 1) & 1];
}

//���[�x���V���^�C������ (�ҏW����)
//a �ɑ��� {�}��, �폜, �u��} ���s�� b �Ɠ��������邽�߂̑���̍ŏ���
//���� O(mn) ��� O(mn)
int levenshtein_distance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	vector<vector<int>> ld(m + 1, vector<int>(n + 1, INF));
	rep(i, 0, m + 1)ld[i][0] = i;
	rep(i, 0, n + 1)ld[0][i] = i;
	rep(i, 1, m + 1)rep(j, 1, n + 1) {
		ld[i][j] = min({
			//�}��
			ld[i - 1][j] + 1,
			//�폜
			ld[i][j - 1] + 1,
			//�u��
			ld[i - 1][j - 1] + (a[i - 1] != b[j - 1])
		});
	}
	return ld[m][n];
}

//���[�x���V���^�C������ (�ҏW����)
//���� O(mn) ��� O(m)
int levenshtein_distance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	int column_start = 1;
	vector<int> column(m + 1);
	iota(column.begin() + column_start, column.begin() + m + 1, column_start);
	for (int x = column_start; x <= n; x++) {
		column[0] = x;
		int last_diagonal = x - column_start;
		for (int y = column_start; y <= m; y++) {
			int old_diagonal = column[y];
			column[y] = min({
				column[y] + 1,
				column[y - 1] + 1,
				last_diagonal + (a[y - 1] != b[x - 1])
			});
			last_diagonal = old_diagonal;
		}
	}
	return column[m];
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235636

//����Z�[���X�}�����
//�L���O���t�ɂ����Ċe���_�����傤��1��ʂ�ŒZ�H
void traveling_salesman_problem() {
	static const int MAX_V = 15;
	static int dp[1 << MAX_V][MAX_V];
	static int g[MAX_V][MAX_V];
	memset(dp, 0x3f, sizeof(dp));
	memset(g, 0x3f, sizeof(g));
	int V, E; cin >> V >> E;
	rep(i, 0, E) {
		int s, t, d; cin >> s >> t >> d;
		g[s][t] = d;
	}
	dp[0][0] = 0;
	for (int mask = 0; mask < (1 << V); mask++) {
		rep(i, 0, V) {
			rep(j, 0, V) {
				if (mask >> j & 1)continue;
				if (dp[mask][i] == INF || g[i][j] == INF)continue;
				chmin(dp[mask | (1 << j)][j], dp[mask][i] + g[i][j]);
			}
		}
	}
	cout << (dp[(1 << V) - 1][0] == INF ? -1 : dp[(1 << V) - 1][0]) << endl;
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236237

//�ő吳���` O(H*W)
void largest_square() {
	int H, W; cin >> H >> W;
	vector<vector<int>> dp(H + 1, vector<int>(W + 1));
	rep(i, 0, H) rep(j, 0, W) {
		int x; cin >> x;
		dp[i + 1][j + 1] = !x;
	}
	int ans = 0;
	rep(i, 1, H + 1)rep(j, 1, W + 1) {
		if (dp[i][j] == 0)continue;
		dp[i][j] = min({
			dp[i - 1][j],
			dp[i][j - 1],
			dp[i - 1][j - 1]
		}) + 1;
		chmax(ans, dp[i][j]);
	}
	cout << ans*ans << endl;
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236860

//�q�X�g�O�����̍ő咷���` O(N)
int largest_rectangle_in_a_histogram(const vector<int> &h) {
	int n = h.size();
	using P = pair<int, int>;
	stack<P> st;
	st.emplace(-1, -1);
	int area = 0;
	for (int i = 0; i < n; i++) {
		if (st.top().first == h[i])
			continue;
		int pos = i;
		while (st.top().first >= h[i]) {
			chmax(area, st.top().first*(i - st.top().second));
			pos = st.top().second;
			st.pop();
		}
		st.emplace(h[i], pos);
	}
	while (st.size()) {
		chmax(area, st.top().first*(n - st.top().second));
		st.pop();
	}
	return area;
}

//0-1�񎟌��z���̍ő咷���` O(H*W)
//�q�X�g�O�����̍ő咷���`�����߂�̂Ɠ��l
int largest_rectangle(vector<vector<int>> v) {
	int H = v.size(), W = v.front().size();
	rep(i, 0, H - 1)rep(j, 0, W) {
		if (v[i + 1][j] == 0)continue;
		v[i + 1][j] += v[i][j];
	}
	int area = 0;
	rep(i, 0, H)
		chmax(area, largest_rectangle_in_a_histogram(v[i]));
	return area;
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236876