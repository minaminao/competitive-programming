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
//	vector<int> c(N); rep(i, 0, N) { cin >> c[i]; }
//	c.insert(c.end(), c.begin(), c.end());
//	if (count(c.begin(), c.end(), 0) % N == 0) {
//		cout << -1 << endl;
//		return 0;
//	}
//	int cnt = 0, tmp = 1;
//	rep(i, 0, c.size() - 1) {
//		if (c[i] == c[i + 1])tmp++;
//		else {
//			chmax(cnt, tmp);
//			tmp = 1;
//		}
//	}
//	cout << cnt / 2 + !!(cnt % 2) << endl;
//	return 0;
//}