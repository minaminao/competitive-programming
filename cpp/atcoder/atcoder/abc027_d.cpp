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
	string s; cin >> s;
	int n = s.size();
	int p, m; p = m = 0;
	vector<int> P, M;
	rrep(i, 0, n) {
		if (s[i] == '+')p++;
		else if (s[i] == '-')m++;
		else {
			P.emplace_back(p - m);
		}
	}
	sort(all(P));
	dump(P);
	int ans = 0;
	rep(i, 0, P.size() / 2) {
		ans -= P[i];
	}
	rep(i, P.size() / 2, P.size()) {
		ans += P[i];
	}
	cout << ans << endl;
	return 0;
}