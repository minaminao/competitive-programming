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
	vector<int> a(N), b(N); rep(i, 0, N) { cin >> a[i] >> b[i]; }
	vector<int> c(M), d(M); rep(i, 0, M) { cin >> c[i] >> d[i]; }
	rep(i, 0, N) {
		int ans = -1, e = INF;
		rep(j, 0, M) {
			int D = abs(c[j] - a[i]) + abs(d[j] - b[i]);
			if (chmin(e, D)) {
				ans = j;
			}
		}
		cout << ans + 1 << endl;
	}
	return 0;
}