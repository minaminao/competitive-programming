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
//	string s; cin >> s;
//	int ans = INF;
//	rep(i, 0, 26) {
//		char c = 'a' + i;
//		string t = s;
//		bool exist = false;
//		rep(j, 0, s.size())
//			if (s[j] == c)
//				exist = true;
//		if (!exist)continue;
//		while (true) {
//			bool flag = true;
//			rep(j, 0, t.size()) {
//				if (t[j] != c)
//					flag = false;
//			}
//			if (flag)break;
//			string u = t;
//			u.pop_back();
//			rep(j, 1, u.size()) {
//				if (u[j] == c)
//					u[j - 1] = c;
//			}
//			t = u;
//		}
//		chmin(ans, (int)s.size() - (int)t.size());
//	}
//	cout << ans << endl;
//	return 0;
//}