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
	int a, b, c, d, e, f;
	a = b = c = d = e = f = 0;
	int N; cin >> N;
	rep(i, 0, N) {
		double x, y; cin >> x >> y;
		if (x >= 35) {
			a++;
		}
		else if (x >= 30) {
			b++;
		}
		else if (x >= 25) {
			c++;
		}
		if (y >= 25) {
			d++;
		}
		if (x >= 0 && y < 0) {
			e++;
		}
		if (x < 0) {
			f++;
		}
	}
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
	return 0;
}