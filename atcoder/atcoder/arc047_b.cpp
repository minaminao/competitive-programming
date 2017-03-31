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
	vector<int> x(N), y(N); rep(i, 0, N) { cin >> x[i] >> y[i]; }
	int bx = 0, by = 0;
	while (true) {
		int D = abs(x[0] - bx) + abs(y[0] - by);
		int mind = D, maxd = D;
		dump(bx, by);
		rep(i, 0, N) {
			int d = abs(x[i] - bx) + abs(y[i] - by);
			chmin(mind, d);
			chmax(maxd, d);
			dump(d);
		}
		int bd = maxd - mind;
		if (bd == 0)
			break;
		int r = rand() % (maxd - mind);
		int cx = bx, cy = by;
		rep(dx, -1, 2) {
			rep(dy, -1, 2) {
				int ax = bx + dx*r, ay = by + dy*r;
				int D = abs(x[0] - ax) + abs(y[0] - ay);
				int mind = D, maxd = D;
				rep(i, 0, N) {
					int d = abs(x[i] - ax) + abs(y[i] - ay);
					chmin(mind, d);
					chmax(maxd, d);
				}
				if (chmin(bd, maxd - mind)) {
					cx = ax, cy = ay;
				}
			}
		}
		bx = cx, by = cy;
	}
	cout << bx << " " << by << endl;
	return 0;
}