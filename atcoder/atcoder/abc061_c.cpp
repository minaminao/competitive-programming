//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//int cnt[100010];
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	int K; cin >> K;
//	memset(cnt, 0, sizeof(cnt));
//	rep(i, 0, N) {
//		int a, b; cin >> a >> b;
//		cnt[a] += b;
//	}
//	int s = 0;
//	rep(i, 0, 100010) {
//		s += cnt[i];
//		if (s >= K) {
//			cout << i << endl;
//			break;
//		}
//	}
//	return 0;
//}