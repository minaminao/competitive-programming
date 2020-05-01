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
	string s; cin >> s;
	int n = s.size();
	int cnt = 0;
	rep(i, 0, n / 2) {
		if (s[i] != s[n - i - 1]) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		cout << n * 25 << endl;
	}
	else if (cnt == 1) {
		cout << (n - 2) * 25 + 24 * 2 << endl;
	}
	else {
		if (n & 1)cout << (n - 1) * 25 << endl;
		else cout << n * 25 << endl;
	}
	return 0;
}