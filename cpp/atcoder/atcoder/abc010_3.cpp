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
	double txa, tya, txb, tyb; cin >> txa >> tya >> txb >> tyb;
	double T, V; cin >> T >> V;
	int n; cin >> n;
	rep(i, 0, n) {
		double x, y; cin >> x >> y;
		double d = sqrt((x - txa)*(x - txa) + (y - tya)*(y - tya)) + sqrt((txb - x)*(txb - x) + (tyb - y)*(tyb - y));
		if (d / V <= T + 1e-8) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}