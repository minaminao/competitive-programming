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
//	freopen("B-large.in", "r", stdin);
//	freopen("B-large.txt", "w", stdout);
//	//freopen("in.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	for (int t = 0; t < T; t++) {
//		int Ac, Aj; cin >> Ac >> Aj;
//		using T = tuple<int, int, int>;
//		vector<T> st;
//		int tot[2] = {};
//		vector<int> C(Ac), D(Ac); rep(i, 0, Ac) {
//			cin >> C[i] >> D[i];
//			st.emplace_back(C[i], D[i], 0);
//			tot[0] += D[i] - C[i];
//		}
//		vector<int> J(Aj), K(Aj); rep(i, 0, Aj) {
//			cin >> J[i] >> K[i];
//			st.emplace_back(J[i], K[i], 1);
//			tot[1] += K[i] - J[i];
//		}
//		sort(all(st));
//		//dump(st);
//		for (bool flag = true; flag;) {
//			flag = false;
//			int n = st.size();
//			int min_interval = INF, min_idx = -1;
//			rep(i, 0, n) {
//				int l, r, c; tie(l, r, c) = st[i];
//				int nl, nr, nc;	tie(nl, nr, nc) = st[(i + 1) % n];
//				if (c != nc)continue;
//				int add = (nl - r + 24 * 60) % (24 * 60);
//				//dump(add);
//				if (tot[c] + add <= 12 * 60) {
//					if (chmin(min_interval, add)) {
//						min_idx = i;
//					}
//				}
//			}
//			//dump(min_idx, min_interval);
//			if (min_idx != -1) {
//				int l, r, c; tie(l, r, c) = st[min_idx];
//				int nl, nr, nc;	tie(nl, nr, nc) = st[(min_idx + 1) % n];
//				tot[c] += min_interval;
//				st[(min_idx + 1) % n] = T(l, nr, nc);
//				st.erase(st.begin() + min_idx);
//				flag = true;
//			}
//		}
//		//dump(st);
//		int ans = st.size();
//		int n = st.size();
//		rep(i, 0, n) {
//			int l, r, c; tie(l, r, c) = st[i];
//			int nl, nr, nc;	tie(nl, nr, nc) = st[(i + 1) % n];
//			if (c == nc) {
//				ans++;
//			}
//		}
//		cout << "Case #" << t + 1 << ": " << ans << endl;
//
//	}
//	return 0;
//}