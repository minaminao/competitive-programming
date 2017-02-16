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
	int N, K; cin >> N >> K;
	vector<bool> dp(256); dp[0] = true;
	rep(i, 0, N) {
		vector<bool> tmp(256);
		vector<int> T(K); rep(j, 0, K) { cin >> T[j]; }
		rep(j, 0, K) {
			rep(k, 0, 256) {
				if (!dp[k])continue;
				tmp[k^T[j]] = true;
			}
		}
		swap(tmp, dp);
		dump(dp);
	}
	if (dp[0])cout << "Found" << endl;
	else cout << "Nothing" << endl;
	return 0;
}