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
//	int N, Q; cin >> N >> Q;
//	vector<int> x(N); rep(i, 0, N) { cin >> x[i]; }
//	vector<int> t(Q); rep(i, 0, Q) { cin >> t[i]; }
//	vector<int> L(N), R(N);
//	rep(i, 0, N) {
//		L[i] = abs(x[i] - x.back());
//		R[i] = abs(x[i] - x.front());
//	}
//	rep(i, 0, N - 1)R[i + 1] += R[i];
//	rrep(i, 1, N)L[i - 1] += L[i];
//	dump(L, R);
//	rep(i, 0, Q) {
//		auto r = lower_bound(all(x), t[i]) - x.begin();
//		auto l = r - 1;
//		dump(l, r);
//		int dl = l == -1 ? 0 : t[i] - x[l];
//		int dr = r == N ? 0 : x[r] - t[i];
//		int cr = N - r;
//		int cl = l + 1;
//		int ans = 0;
//		if (l != -1) {
//			ans += L[0] - L[l] - (cl - 1)*(x.back() - x[l]);
//			dump(L[0], L[l], cl*(x.back() - x[l]));
//		}
//		if (r != N) {
//			ans += R[N - 1] - R[r] - (cr - 1)*(x[r] - x.front());
//			dump(R[N - 1], R[r], cr*(x[r] - x.front()));
//		}
//		ans += dl*cl + dr*cr;
//		dump(dl, cl, dr, cr);
//		cout << ans << endl;
//	}
//	return 0;
//}