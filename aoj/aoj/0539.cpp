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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

//ソート済み配列の要素との差の最小値
template<typename T>
T min_diff(const vector<T> &v, T x) {
	auto u = upper_bound(v.begin(), v.end(), x);
	if (u == v.begin())return v.front() - x;
	if (u == v.end())return x - v.back();
	return min(*u - x, x - *(u - 1));
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int d; cin >> d&&d;) {
		int n; cin >> n;
		int m; cin >> m;
		vector<int> D(n); rep(i, 1, n) { cin >> D[i]; }
		vector<int> k(m); rep(i, 0, m) { cin >> k[i]; }
		sort(all(D));
		D.emplace_back(d);
		dump(D);
		int ans = 0;
		rep(i, 0, m) {
			int u = upper_bound(D.begin(), D.end(), k[i]) - D.begin();
			ans += min_diff(D, k[i]);
			dump(ans);
		}
		cout << ans << endl;
	}
	return 0;
}