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
	int A, B; cin >> A >> B;
	bool a[20][100] = {};
	memset(a, false, sizeof(a));
	a[0][A] = true;
	int b[3] = { 1,5,10 };
	rep(i, 0, 10) {
		rep(j, 0, 100) {
			rep(k, 0, 3) {
				if (!a[i][j])continue;
				if (j + b[k] < 100)a[i + 1][j + b[k]] = true;
				if (j - b[k] >= 0)a[i + 1][j - b[k]] = true;
			}
		}
	}
	rep(i, 0, 20) {
		if (a[i][B]) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}