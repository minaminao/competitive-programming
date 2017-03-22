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
//int dp[5010] = {};
//unordered_set<int> flag[5010] = {};
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, K; cin >> N >> K;
//	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
//	sort(all(a));
//	dump(a);
//	int ans = N;
//	dp[0] = 1;
//	rep(i, 1, 5010)flag[i] = ~flag[i];
//	rep(i, 0, N) {
//		if (a[i] >= K)break;
//		rrep(j, 0, K - a[i]) {
//			if (dp[j]) {
//				dp[j + a[i]] = dp[j];
//				flag[j + a[i]].insert(flag[j].begin(), flag[j].end());
//				flag[j+a[i]].
//			}
//		}
//	}
//	rep(i, 0, N) {
//		if (a[i] >= K) {
//			ans--;
//			continue;
//		}
//		rep(j, K - a[i], K) {
//			if (dp[j]) {
//				dump(flag[j]);
//				if (flag[j][i])continue;
//				dump(i, a[i], j);
//				ans--;
//				break;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}