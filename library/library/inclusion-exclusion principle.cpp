#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<(o)<<" ";}
#define dumpl(o) if(DBG){cerr<<#o<<" "<<(o)<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

//population count
//後ろから立っているbitを降ろす
int popcount(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}
//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

signed main() {
	int ans = 0;
	int n, m; cin >> n >> m;
	vector<int> a(m); rep(i, 0, m) { cin >> a[i]; }
	for (int i = 1; i < (1 << m); i++) {
		int lcm = 1;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				lcm = lcm / gcd(lcm, a[j])*a[j];
				if (lcm > n)break; //lcm>n => n/lcm == 0 よりオーバーフローする前にbreak;
			}
		}
		if (popcount(i) & 1)ans += n / lcm;
		else ans -= n / lcm;
	}
	cout << ans << endl;
	return 0;
}