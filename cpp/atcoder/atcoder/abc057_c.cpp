#include "bits/stdc++.h"
using namespace std;
#ifdef _debug
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int inf = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fll : 0x3f3f3f3f;
const int mod = (int)(1e9) + 7;
template<class t> bool chmax(t &a, const t &b) { if (a < b) { a = b; return true; } return false; }
template<class t> bool chmin(t &a, const t &b) { if (b < a) { a = b; return true; } return false; }

vector<int> divisor(int x) {
	vector<int> ret;
	int i;
	for (i = 1; i*i < x; i++) {
		if (x%i)continue;
		ret.emplace_back(i);
		ret.emplace_back(x / i);
	}
	if (i*i == x)ret.emplace_back(i);
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> d = divisor(n);
	cout << (int)log10(d.back()) + 1 << endl;
	return 0;
}