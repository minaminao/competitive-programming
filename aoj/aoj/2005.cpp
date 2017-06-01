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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int n, m, s, g1, g2; cin >> n >> m >> s >> g1 >> g2&&n;) {
		s--, g1--, g2--;
		static const int N = 101;
		static int wf[N][N];
		rep(i, 0, n)rep(j, 0, n)wf[i][j] = INF;
		rep(i, 0, n)wf[i][i] = 0;
		rep(i, 0, m) {
			int s, d, w; cin >> s >> d >> w;
			s--, d--;
			wf[s][d] = min(wf[s][d], w);
		}

		rep(k, 0, n)rep(i, 0, n)rep(j, 0, n) {
			if (wf[i][k] != INF&&wf[k][j] != INF)
				wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
		}

		int ans = INF;
		rep(k, 0, n) {
			if (wf[s][k] != INF&&wf[k][g1] != INF&&wf[k][g2] != INF)
				chmin(ans, wf[s][k] + wf[k][g1] + wf[k][g2]);
		}
		cout << ans << endl;

	}
	return 0;
}