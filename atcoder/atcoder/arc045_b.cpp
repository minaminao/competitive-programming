#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<int> sum(N + 2);
	vector<int> s(M), t(M); rep(i, 0, M) {
		cin >> s[i] >> t[i];
		t[i]++;
		sum[s[i]]++, sum[t[i]]--;
	}
	rep(i, 0, N + 1) {
		sum[i + 1] += sum[i];
	}
	rep(i, 0, N + 1) {
		if (sum[i] >= 2)sum[i] = 0;
	}
	dump(sum);
	rep(i, 0, N + 1) {
		sum[i + 1] += sum[i];
	}
	dump(sum);
	vector<int> ans;
	rep(i, 0, M) {
		dump(s[i], t[i], t[i] - s[i]);
		if (0 == sum[t[i] - 1] - sum[s[i] - 1]) {
			ans.emplace_back(i + 1);
		}
	}
	cout << ans.size() << endl;
	rep(i, 0, ans.size()) { cout << ans[i] << endl; }
	return 0;
}