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

int dp[10010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, W; cin >> N >> W;
	vector<int> v(N), w(N), m(N); rep(i, 0, N) { cin >> v[i] >> w[i] >> m[i]; }
	memset(dp, 0, sizeof(dp));
	rep(i, 0, N) {
		int m_ = m[i];
		for (int a = 1; m_ > 0; m_ -= a, a <<= 1) {
			int a_ = min(a, m_);
			rrep(j, 0, W + 1) {
				if (j + w[i] * a_ > W)continue;
				chmax(dp[j + w[i] * a_], dp[j] + v[i] * a_);
			}
		}
	}
	cout << dp[W] << endl;
	return 0;
}