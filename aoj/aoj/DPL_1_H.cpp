#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
	int N, W; cin >> N >> W;
	vector<int> v(N), w(N); rep(i, 0, N) { cin >> v[i] >> w[i]; }
	using P = pair<int, int>;
	vector<P> a, b;
	a.emplace_back(0, 0);
	b.emplace_back(0, 0);
	rep(i, 0, N / 2) {
		int n = a.size();
		rep(j, 0, n) {
			a.emplace_back(a[j].first + w[i], a[j].second + v[i]);
		}
	}
	rep(i, N / 2, N) {
		int n = b.size();
		rep(j, 0, n) {
			b.emplace_back(b[j].first + w[i], b[j].second + v[i]);
		}
	}
	sort(all(a));
	sort(all(b));
	rep(i, 0, b.size() - 1) {
		chmax(b[i + 1].second, b[i].second);
	}
	dump(a, b);
	int ans = 0;
	for (auto &e : a) {
		if (W - e.first <= 0)continue;
		P p{ W - e.first,INF };
		auto l = lower_bound(all(b), p);
		chmax(ans, e.second + (*(l - 1)).second);
	}
	cout << ans << endl;
	return 0;
}