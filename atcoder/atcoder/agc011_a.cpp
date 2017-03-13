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
//	int N, C, K; cin >> N >> C >> K;
//	vector<int> T(N); rep(i, 0, N) { cin >> T[i]; }
//	sort(all(T));
//	int t = T[0];
//	int ans = 1;
//	int c = 1;
//	rep(i, 1, N) {
//		if (T[i] <= t + K && c < C) {
//			c++;
//			continue;
//		}
//		ans++;
//		t = T[i];
//		c = 1;
//	}
//	cout << ans << endl;
//	return 0;
//}