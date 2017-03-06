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
	int cho, ei, don;
	cho = ei = don = 0;
	for (int a, b, c; cin >> a >> b >> c;) {
		vector<int> v{ a,b,c };
		sort(all(v));
		a = v[0], b = v[1], c = v[2];
		if (a + b <= c)break;
		if (a*a + b*b == c*c)cho++;
		else if (a*a + b*b > c*c)ei++;
		else don++;
	}
	cout << cho + ei + don << " " << cho << " " << ei << " " << don << endl;
	return 0;
}