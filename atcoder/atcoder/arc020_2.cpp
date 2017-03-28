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
	int n, c; cin >> n >> c;
	vector<int> a(n); rep(i, 0, n) {
		cin >> a[i];
		a[i]--;
	}
	int ans = INF;
	rep(i, 0, 10)rep(j, 0, 10) {
		if (i == j)continue;
		int tmp = 0;
		rep(k, 0, n) {
			if (k & 1) {
				if (a[k] == i)continue;
				tmp += c;
			}
			else {
				if (a[k] == j)continue;
				tmp += c;
			}
		}
		chmin(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}