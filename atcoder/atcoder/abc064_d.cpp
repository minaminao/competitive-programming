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
//bool valid(string s) {
//	int a = 0;
//	rep(i, 0, s.size()) {
//		if (s[i] == '(')a++;
//		else if (s[i] == ')')a--;
//		if (a < 0)return false;
//	}
//	return true;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N;
//	string s;
//	cin >> N >> s;
//
//	string ans = s;
//	bool flag = true;
//	while (flag) {
//		dump(ans);
//		flag = false;
//		int a = 0;
//		rep(i, 0, ans.size()) {
//			if (ans[i] == '(')a++;
//			else if (ans[i] == ')')a--;
//			if (a < 0) {
//				ans = "(" + ans;
//				flag = true;
//				break;
//			}
//		}
//	}
//
//	flag = true;
//	while (flag) {
//		dump(ans);
//		flag = false;
//		int a = 0;
//		rrep(i, 0, ans.size()) {
//			if (ans[i] == '(')a++;
//			else if (ans[i] == ')')a--;
//			if (a > 0) {
//				ans = ans + ")";
//				flag = true;
//				break;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}