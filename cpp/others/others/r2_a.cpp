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
//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);
//	//freopen("in.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	cout << fixed << setprecision(10);
//	for (int t = 0; t < T; t++) {
//		int N, P; cin >> N >> P;
//		vector<int> G(N); rep(i, 0, N) {
//			cin >> G[i];
//		}
//		int m[4] = {};
//		int ans = 0;
//		rep(i, 0, N)
//			m[G[i] % P]++;
//		dump(m);
//		if (P == 2) {
//			ans = m[1] / 2;
//		}
//		else if (P == 3) {
//			int a = m[1], b = m[2];
//			if (a > b)swap(a, b);
//			int d = b - a;
//			ans += a;
//			if (d != 0)
//				ans += (d + 2) % 3 + ((d - 1) / 3) * 2;
//		}
//		else if (P == 4) {
//			ans = m[2] / 2;
//			int a = m[1], b = m[3];
//			if (a > b)swap(a, b);
//			int d = b - a;
//			ans += a;
//			if (m[2] % 2) {
//				d += 2;
//				ans--;
//			}
//			if (d != 0)
//				ans += (d + 3) % 4 + ((d - 1) / 4) * 3;
//		}
//		dump(ans);
//		ans = N - ans;
//		cout << "Case #" << t + 1 << ": " << ans << endl;
//	}
//	return 0;
//}