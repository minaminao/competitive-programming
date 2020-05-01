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
	int N; cin >> N;
	vector<int> x(N), y(N), c(N); rep(i, 0, N) { cin >> x[i] >> y[i] >> c[i]; }
	cout << fixed << setprecision(10);
	//t•b‚ÅW‚Ü‚ê‚é‚©‚Ç‚¤‚©
	auto f = [&](double t) {
		double sx, sy, tx, ty;
		sx = -INF, sy = INF;
		tx = INF, ty = -INF;
		rep(i, 0, N) {
			double d = t / c[i];
			chmax(sx, x[i] - d);
			chmin(sy, y[i] + d);
			chmin(tx, x[i] + d);
			chmax(ty, y[i] - d);
		}
		if (sx <= tx&&sy >= ty) {
			return true;
		}
		else {
			return false;
		}
	};
	auto binary_search = [&](double l, double r) {
		if (f(l))return l; //exception f(l):true
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2;
			if (f(m))
				r = m;
			else
				l = m;
		}
		return r; //f(l):false, f(r):true
	};
	cout << binary_search(0, INF) << endl;
	return 0;
}