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
	int a, b, c; cin >> a >> b >> c;
	using T = tuple<int, int, int>;
	set<T> st;
	int ans = 0;
	int na, nb, nc;
	while (true) {
		if (a % 2 || b % 2 || c % 2)break;
		if (st.count(T(a, b, c))) {
			ans = -1;
			break;
		}
		st.emplace(a, b, c);
		ans++;
		na = b / 2 + c / 2;
		nb = c / 2 + a / 2;
		nc = a / 2 + b / 2;
		a = na;
		b = nb;
		c = nc;
	}
	cout << ans << endl;
	return 0;
}