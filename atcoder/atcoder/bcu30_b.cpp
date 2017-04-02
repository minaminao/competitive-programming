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
//	const int N = 9;
//	char s[N][N];
//	rep(i, 0, N)rep(j, 0, N)cin >> s[i][j];
//	bool flag = true;
//	rep(i, 0, N) {
//		char cnt[128] = {};
//		rep(j, 0, N) {
//			cnt[s[i][j]]++;
//			if (cnt[s[i][j]] >= 2) {
//				flag = false;
//			}
//		}
//	}
//	rep(j, 0, N) {
//		char cnt[128] = {};
//		rep(i, 0, N) {
//			cnt[s[i][j]]++;
//			if (cnt[s[i][j]] >= 2) {
//				flag = false;
//			}
//		}
//	}
//	static const int
//		di[8] = { -2,-2,-1,-1,1,1,2,2 },
//		dj[8] = { -1,1,-2,2,-2,2,-1,1 };
//	auto inrange = [&](int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; };
//	rep(i, 0, N)rep(j, 0, N) {
//		rep(k, 0, 8) {
//			int ni = di[k] + i, nj = dj[k] + j;
//			if (!inrange(ni, nj))continue;
//			if (s[i][j] == s[ni][nj]) {
//				flag = false;
//			}
//		}
//	}
//	cout << (flag ? "Yes" : "No") << endl;
//	return 0;
//}