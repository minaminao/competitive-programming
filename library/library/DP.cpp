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