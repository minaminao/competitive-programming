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

int digitsum(int x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> ans;
	rep(i, 0, 19 * 9) {
		int x = N - i;
		if (x <= 0)continue;
		if (digitsum(x) + x == N) {
			ans.emplace_back(x);
		}
	}
	sort(all(ans));
	cout << ans.size() << endl;
	rep(i, 0, ans.size()) { cout << ans[i] << endl; }
	return 0;
}