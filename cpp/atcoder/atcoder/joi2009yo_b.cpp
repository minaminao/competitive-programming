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
	vector<int> v(10); rep(i, 0, 10) { cin >> v[i]; }
	vector<int> w(10); rep(i, 0, 10) { cin >> w[i]; }
	sort(all(v)); sort(all(w));
	cout << accumulate(v.begin() + 7, v.end(), 0) << " " << accumulate(w.begin() + 7, w.end(), 0) << endl;
	return 0;
}