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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	int N; cin >> N;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	int ans = -INF;
	rep(i, 0, N) {
		int aokimax = -INF;
		int tmp = -INF;
		rep(j, 0, N) {
			if (i == j)continue;
			int aoki = 0, taka = 0;
			if (i < j) {
				rep(k, i, j + 1) {
					if ((k - i) & 1)aoki += a[k];
					else taka += a[k];
				}
			}
			else {
				rep(k, j, i + 1) {
					if ((k - j) & 1)aoki += a[k];
					else taka += a[k];
				}
			}
			if (chmax(aokimax, aoki))tmp = taka;
			dump(i, j, taka, aoki);
		}
		dump(ans, tmp, aokimax);
		chmax(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}