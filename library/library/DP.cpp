//Å’·‘‰Á•”•ª—ñ
int longest_increasing_subsequence(const vector<int> &v) {
	int n = v.size();
	vector<int> dp(n, INF);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
	return find(dp.begin(), dp.end(), INF) - dp.begin();
}

void solve() {
	//dp‚Í %2 ‚ğg‚¤‚Æ‹óŠÔ‚ª 2‚Â ‚ÅÏ‚Ş
	int dp[2];
	int i; dp[i % 2];
}