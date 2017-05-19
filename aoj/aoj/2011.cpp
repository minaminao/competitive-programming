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

const int N = 55;
bool a[N][33];
bool dp[33][N][N];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int n; cin >> n&&n;) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		rep(i, 0, n) {
			int f; cin >> f;
			rep(j, 0, f) {
				int d; cin >> d;
				a[i][d] = true;
			}
			rep(j, 0, n) {
				dp[0][i][j] = false;
			}
			dp[0][i][i] = true;
		}
		int ans = -1;
		rep(i, 1, 31) {
			rep(j, 0, n)rep(k, 0, n)dp[i][j][k] = dp[i - 1][j][k];
			rep(j, 0, n) {
				if (!a[j][i])continue;
				rep(k, j + 1, n) {
					if (!a[k][i])continue;
					rep(l, 0, n) {
						dp[i][j][l] |= dp[i - 1][k][l];
						dp[i][k][l] |= dp[i - 1][j][l];
					}
				}
			}
			rep(j, 0, n) {
				bool complete = true;
				rep(k, 0, n) {
					if (!dp[i][j][k])complete = false;
				}
				if (complete) {
					ans = i;
					i = INF, j = INF;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}