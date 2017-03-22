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
//	int N, M; cin >> N >> M;
//	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
//	int ans = 0;
//	int i = 0;
//	while (true) {
//		int mini = INF, maxi = 0;
//		rep(j, 0, M) {
//			chmin(mini, A[i]);
//			chmax(maxi, A[i]);
//
//			i++;
//			i %= N;
//		}
//		ans += maxi - mini;
//		dump(ans);
//		if (i == 0)break;
//	}
//	cout << ans << endl;
//	return 0;
//}