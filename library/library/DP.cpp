//�Œ�����������
int longest_increasing_subsequence(const vector<int> &v) {
	int n = v.size();
	vector<int> dp(n, INF);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
	return find(dp.begin(), dp.end(), INF) - dp.begin();
}

void solve() {
	//dp�� %2 ���g���Ƌ�Ԃ� 2�� �ōς�
	int dp[2];
	int i; dp[i % 2];
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