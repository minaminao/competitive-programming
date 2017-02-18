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
	cout << fixed << setprecision(8);
	int N; cin >> N;
	vector<int> C(N); rep(i, 0, N) { cin >> C[i]; }
	double ans = 0;
	rep(i, 0, N) {
		int cnt = 0;
		rep(j, 0, N) {
			if (i == j)continue;
			if (!(C[i] % C[j]))cnt++;
		}
		dump(cnt);
		if (cnt % 2)ans += 1.0 / 2;
		else ans += (cnt + 2.0) / 2 / (cnt + 1);
	}
	cout << ans << endl;
	return 0;
}