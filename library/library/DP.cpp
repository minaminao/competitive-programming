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

//���[�x���V���^�C������(�ҏW����)
//a�ɑ���{�}��, �폜, �u��}���s��b�Ɠ��������邽�߂̑���̍ŏ���
//����O(mn) ���O(mn)
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

//����O(mn) ���O(m)
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