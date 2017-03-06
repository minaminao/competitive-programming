#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
//#define double long double
const double EPS = 1e-9; //–â‘è‚²‚Æ‚É•ÏX
const double PI = acos(-1);

int N;
using pii = pair<int, int>;
int x[2010], y[2010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	rep(i, N) cin >> x[i] >> y[i];

	int cho = 0, don = 0;
	rep(i, N) {
		static double ts[4010];
		int l = 0;
		rep(j, N) {
			if (i == j)continue;
			int dy = y[j] - y[i];
			int dx = x[j] - x[i];
			double t = atan2(dy, dx);
			if (t < 0) t += PI * 2;
			ts[l++] = t;
		}
		sort(ts, ts + l);
		rep(j, N - 1) {
			ts[l++] = ts[j] + 2 * PI;
		}
		rep(j, N - 1) {
			auto x = upper_bound(ts, ts + l, ts[j] + PI / 2 - EPS);
			auto y = upper_bound(x, ts + l, ts[j] + PI / 2 + EPS);
			auto z = upper_bound(y, ts + l, ts[j] + PI - EPS);
			cho += y - x;
			don += z - y;
		}
	}
	int ei = (long long)N*(N - 1)*(N - 2) / 6 - cho - don;
	cout << ei << ' ' << cho << ' ' << don << endl;
	return 0;
}