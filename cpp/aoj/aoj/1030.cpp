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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int key(int a, int b, int c) {
	return a * 500 * 500 + b * 500 + c;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int n, h; cin >> n >> h&&n;) {
		unordered_set<int> st;
		rep(i, 0, h) {
			string c;
			int a, b;
			cin >> c >> a >> b; a--, b--;
			if (c == "xy") {
				rep(j, 0, n)st.insert(key(a, b, j));
			}
			else if (c == "xz") {
				rep(j, 0, n)st.insert(key(a, j, b));
			}
			else {
				rep(j, 0, n)st.insert(key(j, a, b));
			}
		}
		cout << n*n*n - st.size() << endl;
	}
	return 0;
}