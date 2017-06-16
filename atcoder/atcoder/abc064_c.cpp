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
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> a(N); rep(i, 0, N) {
//		cin >> a[i];
//	}
//	int b[8] = { 400,800,1200,1600,2000,2400,2800,3200 };
//	bool f[8] = {};
//	int ans = 0, r = 0;
//	rep(i, 0, N) {
//		rep(j, 0, 8) {
//			if (a[i] < b[j]) {
//				f[j] = true;
//				break;
//			}
//		}
//		if (a[i] >= 3200) {
//			r++;
//		}
//	}
//	rep(j, 0, 8)
//		if (f[j])
//			ans++;
//	if (ans == 0 && r) {
//		cout << 1 << " " << r << endl;
//	}
//	else
//		cout << ans << " " << ans + r << endl;
//	return 0;
//}