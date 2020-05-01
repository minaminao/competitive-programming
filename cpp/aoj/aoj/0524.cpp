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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int m; cin >> m&&m;) {
		set<pair<int, int>> st;
		vector<int> tx(m), ty(m); rep(i, 0, m) { cin >> tx[i] >> ty[i]; }
		int n; cin >> n;
		vector<int> sx(n), sy(n); rep(i, 0, n) {
			cin >> sx[i] >> sy[i];
			st.emplace(sx[i], sy[i]);
		}

		rep(i, 0, n) {
			bool flag = true;
			int dx = sx[i] - tx[0], dy = sy[i] - ty[0];
			rep(j, 0, m) {
				if (!st.count(pair<int, int>(tx[j] + dx, ty[j] + dy))) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << dx << " " << dy << endl;
				break;
			}
		}
	}
	return 0;
}