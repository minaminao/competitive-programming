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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> a(N); rep(i, 0, N) {
//		cin >> a[i];
//	}
//	vector<int> s = a;
//	int ans1 = 0, ans2 = 0;
//	rep(i, 0, N) {
//		dump(s);
//		if (i & 1) {
//			if (s[i] <= 0) {
//				int c = abs(s[i]) + 1;
//				ans1 += c;
//				s[i] += c;
//			}
//		}
//		else {
//			if (s[i] >= 0) {
//				int c = abs(s[i]) + 1;
//				ans1 += c;
//				s[i] -= c;
//			}
//		}
//		if (i < N - 1)s[i + 1] += s[i];
//	}
//	if (s.back() == 0)ans1++;
//	dump(s);
//	dump(ans1);
//	s = a;
//	rep(i, 0, N) {
//		dump(s);
//		if (i & 1) {
//			if (s[i] >= 0) {
//				int c = abs(s[i]) + 1;
//				ans2 += c;
//				s[i] -= c;
//			}
//		}
//		else {
//			if (s[i] <= 0) {
//				int c = abs(s[i]) + 1;
//				ans2 += c;
//				s[i] += c;
//			}
//		}
//		if (i < N - 1)s[i + 1] += s[i];
//	}
//	if (s.back() == 0)ans2++;
//	dump(s);
//	dump(ans2);
//	cout << min(ans1, ans2) << endl;
//	return 0;
//}