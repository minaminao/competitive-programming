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
//	freopen("C-small-1-attempt0.in", "r", stdin);
//	freopen("C-small-1-attempt0.txt", "w", stdout);
//	//freopen("in.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	cout << fixed << setprecision(10);
//	for (int t = 0; t < T; t++) {
//		int N, K; cin >> N >> K;
//		double U; cin >> U;
//		vector<double> P(N); rep(i, 0, N) {
//			cin >> P[i];
//		}
//		sort(all(P));
//		rep(i, 1, N) {
//			double add = min((P[i] - P[i - 1])*i, U) / i;
//			rep(j, 0, i) {
//				P[j] += add;
//				U -= add;
//			}
//		}
//		dump(P, U);
//		if (U) {
//			rep(i, 0, N) {
//				P[i] += U / N;
//			}
//		}
//		dump(P);
//		double ans = 1;
//		rep(i, 0, N)
//			ans *= P[i];
//		cout << "Case #" << t + 1 << ": " << ans << endl;
//
//	}
//	return 0;
//}