#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int r; cin >> r;
	rep(i, 0, r) {
		int n, k; cin >> n >> k;
		vector<int> x(n); rep(i, 0, n) { cin >> x[i]; }
		vector<int>	d(n - 1);
		rep(i, 0, n - 1)d[i] = x[i + 1] - x[i];
		sort(all(d));
		k = min(n, k);
		int ans = accumulate(d.begin(), d.end() - (k - 1), 0);
		cout << ans << endl;
	}
	return 0;
}