#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	using T = tuple<int, int, int>;
	for (int n; cin >> n&&n;) {
		set<T> st;
		st.emplace(-INF, 0, -1);
		while (n--) {
			char com; cin >> com;
			if (com == 'W') {
				int l, s; cin >> l >> s;
				for (auto c = st.begin(); c != st.end(); c++) {
					int ca, cb, cc, na, nb, nc;
					tie(ca, cb, cc) = *c;
					if (next(c) == st.end()) {
						st.emplace(cb, cb + s, l);
						break;
					}
					tie(na, nb, nc) = *next(c);
					if (cb == na)
						continue;
					int d = min(s, na - cb);
					c = st.emplace(cb, cb + d, l).first;
					s -= d;
					if (s == 0)
						break;
				}
			}
			else if (com == 'D') {
				int l; cin >> l;
				for (auto it = st.begin(); it != st.end();) {
					if (get<2>(*it) == l)
						it = st.erase(it);
					else
						it++;
				}
			}
			else if (com == 'R') {
				int p; cin >> p;
				auto upper = st.upper_bound(T(p, INF, INF));
				int a, b, c;
				tie(a, b, c) = *prev(upper);
				if (b <= p)
					cout << -1 << endl;
				else
					cout << c << endl;
			}
		}
		cout << endl;
	}
	return 0;
}