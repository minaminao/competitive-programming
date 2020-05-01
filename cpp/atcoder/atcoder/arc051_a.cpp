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
	int x1, y1, r; cin >> x1 >> y1 >> r;
	int x2, y2, x3, y3; cin >> x2 >> y2 >> x3 >> y3;
	bool ans1 = false, ans2 = false;
	rep(x, -300, 300)rep(y, -300, 300) {
		bool R = (x - x1)*(x - x1) + (y - y1)*(y - y1) <= r*r;
		bool B = x2 <= x&&x <= x3&&y2 <= y&&y <= y3;
		if (R&&B) {
			continue;
		}
		else if (R) {
			ans1 = true;
		}
		else if (B) {
			ans2 = true;
		}
	}
	cout << (ans1 ? "YES" : "NO") << endl;
	cout << (ans2 ? "YES" : "NO") << endl;
	return 0;
}