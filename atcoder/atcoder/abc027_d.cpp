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
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	string s; cin >> s;
//	int N = s.size();
//	string t = s;
//	int p = 0;
//	int r, l, m;
//	r = l = m = 0;
//	rrep(i, 0, N) {
//		if (s[i] == 'M') {
//			if (p > 0) {
//				t[i] = '>';
//				r++;
//			}
//			else if (p < 0) {
//				t[i] = '<';
//				l++;
//			}
//			else {
//				t[i] = '?';
//				m++;
//			}
//		}
//		else if (s[i] == '+') {
//			p++;
//		}
//		else {
//			p--;
//		}
//	}
//	dump(t);
//	int M = r + l + m;
//	for (int i = N - 1; M / 2 < r; i--) {
//		if (t[i] != '>')continue;
//		t[i] = '<';
//		r--;
//	}
//	for (int i = N - 1; M / 2 < l; i--) {
//		if (t[i] != '<')continue;
//		t[i] = '>';
//		l--;
//	}
//	rep(i, 0, N) {
//		if (t[i] == '?') {
//			if (r <= l) {
//				t[i] = '>';
//			}
//			else {
//				t[i] = '<';
//			}
//		}
//	}
//	dump(t);
//	int x = 0, ans = 0;
//	rep(i, 0, N) {
//		if (t[i] == '<')x--;
//		else if (t[i] == '>')x++;
//		else if (t[i] == '+')ans += x;
//		else if (t[i] == '-')ans -= x;
//	}
//	cout << ans << endl;
//	return 0;
//}