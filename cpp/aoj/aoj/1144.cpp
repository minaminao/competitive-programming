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
	for (int w, h; cin >> w >> h&&w;) {
		static int a[21][21];
		int si, sj, gi, gj;
		memset(a, 0, sizeof(a));
		rep(i, 0, h)rep(j, 0, w) {
			cin >> a[i][j];
			if (a[i][j] == 2)
				si = i, sj = j;
			else if (a[i][j] == 3)
				gi = i, gj = j;
		}
		auto inrange = [&](int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; };
		function<int(int, int, int)> dfs = [&](int i, int j, int depth) {
			dump(i, j, depth);
			static const int di[] = { 1,0,-1,0 };
			static const int dj[] = { 0,1,0,-1 };
			int ret = INF;
			if (depth < 10) {
				rep(k, 0, 4) {
					int ci = i, cj = j;
					while (true) {
						int ni = ci + di[k], nj = cj + dj[k];
						if (!inrange(ni, nj))
							break;
						if (a[ni][nj] == 1) {
							if (!(i == ci && j == cj)) {
								a[ni][nj] = 0;
								chmin(ret, dfs(ci, cj, depth + 1));
								a[ni][nj] = 1;
							}
							break;
						}
						else if (a[ni][nj] == 3) {
							chmin(ret, depth);
							break;
						}
						else {
							ci += di[k], cj += dj[k];
							continue;
						}
					}
				}
			}
			return ret;
		};
		int res = dfs(si, sj, 0);
		if (res == INF) {
			cout << -1 << endl;
		}
		else {
			cout << res + 1 << endl;
		}
	}
	return 0;
}