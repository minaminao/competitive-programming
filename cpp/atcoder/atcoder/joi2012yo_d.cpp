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
int a[110] = {};
int dp[110][3][3] = {};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	memset(a, -1, sizeof(a));
	rep(i, 0, K) {
		int x, y; cin >> x >> y;
		a[x - 1] = y - 1;
	}
	dp[0][0][0] = 1;
	rep(i, 0, N) {
		if (a[i] == -1) {
			rep(j, 0, 3) {
				rep(k, 0, 3) {
					rep(l, 0, 3) {
						if (j == 2 && k == l)continue;
						(dp[i + 1][k == l ? j + 1 : 1][k] += dp[i][j][l]) %= 10000;
					}
				}
			}
		}
		else {
			rep(j, 0, 3) {
				rep(l, 0, 3) {
					if (j == 2 && a[i] == l)continue;
					(dp[i + 1][a[i] == l ? j + 1 : 1][a[i]] += dp[i][j][l]) %= 10000;
				}
			}
		}
		dump(dp[i + 1]);
	}
	int ans = 0;
	rep(j, 0, 3)rep(k, 0, 3) {
		ans += dp[N][j][k];
	}
	ans %= 10000;
	cout << ans << endl;
	return 0;
}