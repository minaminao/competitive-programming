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
//	//0123456789
//	int v[] = { 1,0,0,0,1,0,1,0,2,1 };
//	string s; cin >> s;
//	int ans = 0;
//	rep(i, 0, s.size()) {
//		ans += v[s[i] - '0'] + 2;
//	}
//	ans += 1;
//
//	int ans2 = 0;
//	ans2++;
//	rep(i, 0, s.size()) {
//		ans2 += v[s[i] - '0'] * 2;
//	}
//	ans2 += s.size();
//	ans2++;
//	dump(ans, ans2);
//	cout << min(ans, ans2) << endl;
//
//	return 0;
//}