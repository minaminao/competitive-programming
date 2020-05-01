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
	vector<int> E(6); rep(i, 0, 6) { cin >> E[i]; }
	int B; cin >> B;
	vector<int> L(6); rep(i, 0, 6) { cin >> L[i]; }
	int c = 0;
	bool f = false;
	rep(i, 0, 6)rep(j, 0, 6) {
		if (E[i] == L[j])c++;
	}
	rep(i, 0, 6)if (L[i] == B)f = true;
	if (c == 6)cout << 1 << endl;
	else if (c == 5 && f)cout << 2 << endl;
	else if (c == 5)cout << 3 << endl;
	else if (c == 4)cout << 4 << endl;
	else if (c == 3)cout << 5 << endl;
	else cout << 0 << endl;
	return 0;
}