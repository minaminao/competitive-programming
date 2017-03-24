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
//	vector<int> r(N); rep(i, 0, N) { cin >> r[i]; }
//	vector<int> s(N), p(N), c(N); rep(i, 0, N) { cin >> s[i] >> p[i] >> c[i]; }
//	using P = pair<int, int>;
//
//	vector<P> s_(N), p_(N), c_(N);
//	rep(i, 0, N) {
//		s_[i] = P(s[i], -i);
//		p_[i] = P(p[i], -i);
//		c_[i] = P(c[i], -i);
//	}
//	sort(all(s_));
//	sort(all(p_));
//	sort(all(c_));
//	reverse(all(s_));
//	reverse(all(p_));
//	reverse(all(c_));
//	int sr, pr, cr;
//	sr = lower_bound(all(s_), P(s[0], 0)) - s_.begin();
//	pr = lower_bound(all(p_), P(p[0], 0)) - p_.begin();
//	cr = lower_bound(all(c_), P(c[0], 0)) - c_.begin();
//
//	dump(sr, pr, cr);
//	return 0;
//	rep(i, 0, 100) {
//		vector<P> s_(N);
//		s_[0] = P(s[i] + i, 0);
//		rep(j, 1, N) {
//			s_[j] = P(s[i], -i);
//		}
//		sort(all(s_));
//		reverse(all(s_));
//		rep(j, 0, N) {
//			if (s_[j].second == 0) {
//
//			}
//		}
//	}
//	return 0;
//}