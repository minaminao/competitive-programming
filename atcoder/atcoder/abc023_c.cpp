//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int R, C, K; cin >> R >> C >> K;
//	int N; cin >> N;
//	vector<int> cr(R), cc(C);
//	vector<int> r(N), c(N); rep(i, 0, N) {
//		cin >> r[i] >> c[i];
//		r[i]--, c[i]--;
//		cr[r[i]]++, cc[c[i]]++;
//	}
//	dump(cr, cc);
//	int a[100010] = {}, b[100010] = {};
//	rep(i, 0, R) {
//		a[cr[i]]++;
//	}
//	rep(i, 0, C) {
//		b[cc[i]]++;
//	}
//	int ans = 0;
//	rep(i, 0, K + 1) {
//		ans += a[i] * b[K - i];
//	}
//	rep(i, 0, N) {
//		if (cr[r[i]] + cc[c[i]] == K)ans--;
//		if (cr[r[i]] + cc[c[i]] == K + 1)ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}