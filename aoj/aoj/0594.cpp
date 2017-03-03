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
	int W, H, N; cin >> W >> H >> N;
	vector<int> x(N), y(N); rep(i, 0, N) { cin >> x[i] >> y[i]; }
	int ans = 0;
	rep(i, 0, N - 1) {
		int dx = x[i + 1] - x[i], dy = y[i + 1] - y[i];
		if (dx*dy > 0) {
			dx = abs(dx), dy = abs(dy);
			ans += min(dx, dy) + abs(dx - dy);
		}
		else {
			ans += abs(dx) + abs(dy);
		}
	}
	cout << ans << endl;
	return 0;
}