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
	int N; cin >> N;
	vector<int> x(N), y(N); rep(i, 0, N) { cin >> x[i] >> y[i]; }
	int ans = 0;
	rep(i, 0, N)rep(j, i + 1, N)rep(k, j + 1, N) {
		int a = x[j] - x[i], b = x[k] - x[i], c = y[j] - y[i], d = y[k] - y[i];
		int area2 = abs(a*d - b*c);
		if (area2 == 0)continue;
		if (area2 & 1)continue;
		ans++;
	}
	cout << ans << endl;
	return 0;
}