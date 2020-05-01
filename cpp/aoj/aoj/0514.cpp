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
	for (int a, b, c; cin >> a >> b >> c&&a;) {
		int N; cin >> N;
		vector<int> f(a + b + c, 2);
		vector<int> p(N), q(N), r(N), s(N);
		rep(i, 0, N) {
			cin >> p[i] >> q[i] >> r[i] >> s[i]; p[i]--, q[i]--, r[i]--;
			if (s[i])f[p[i]] = f[q[i]] = f[r[i]] = 1;
		}
		rep(i, 0, N) {
			int cnt = 0;
			if (f[p[i]] == 1)cnt++;
			if (f[q[i]] == 1)cnt++;
			if (f[r[i]] == 1)cnt++;
			if (cnt == 3)continue;
			if (cnt == 2) {
				if (f[p[i]] != 1)f[p[i]] = 0;
				if (f[q[i]] != 1)f[q[i]] = 0;
				if (f[r[i]] != 1)f[r[i]] = 0;
			}
		}
		rep(i, 0, a + b + c) {
			cout << f[i] << endl;
		}
	}
	return 0;
}