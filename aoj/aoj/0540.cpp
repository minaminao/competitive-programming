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
	for (int n, m, h, k; cin >> n >> m >> h >> k&&n;) {
		dump(n, m, h, k);
		vector<int> v(n); rep(i, 0, n) { cin >> v[i]; }
		vector<pair<int, int>> w(m);
		rep(i, 0, m) {
			cin >> w[i].second >> w[i].first;
		}
		sort(all(w));
		vector<int> tmp = v;
		set<pair<int, int>> st;
		rrep(i, 0, m) {
			int &a = tmp[w[i].second - 1];
			int &b = tmp[w[i].second];
			swap(a, b);
			st.emplace(a, b);
			st.emplace(b, a);
		}
		//dump(v, tmp);
		int base = accumulate(tmp.begin(), tmp.begin() + k, 0);
		int ans = base;
		dump(base);
		rep(i, 0, k)rep(j, k, n) {
			if (st.count(pair<int, int>(tmp[i], tmp[j]))) {
				chmin(ans, base - (tmp[i] - tmp[j]));
				dump(i, j, tmp[i], tmp[j], base - (tmp[i] - tmp[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}