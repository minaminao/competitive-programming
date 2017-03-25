//最長増加部分列
int longest_increasing_subsequence(const vector<int> &v) {
	int n = v.size();
	vector<int> dp(n, INF);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
	return find(dp.begin(), dp.end(), INF) - dp.begin();
}

void solve() {
	//dpは %2 を使うと空間が 2つ で済む
	int dp[2];
	int i; dp[i % 2];
}

//レーベンシュタイン距離(編集距離)
//aに操作{挿入, 削除, 置換}を行いbと等しくするための操作の最小回数
//時間O(mn) 空間O(mn)
int levenshtein_distance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	vector<vector<int>> ld(m + 1, vector<int>(n + 1, INF));
	rep(i, 0, m + 1)ld[i][0] = i;
	rep(i, 0, n + 1)ld[0][i] = i;
	rep(i, 1, m + 1)rep(j, 1, n + 1) {
		ld[i][j] = min({
			//挿入
			ld[i - 1][j] + 1,
			//削除
			ld[i][j - 1] + 1,
			//置換
			ld[i - 1][j - 1] + (a[i - 1] != b[j - 1])
		});
	}
	return ld[m][n];
}

//時間O(mn) 空間O(m)
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