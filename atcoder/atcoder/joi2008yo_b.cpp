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
	int J, I; J = I = 0;
	rep(i, 0, s.size() - 2) {
		if (s[i] == 'J') {
			if (s[i + 1] == 'O'&&s[i + 2] == 'I')J++;
		}
		else if (s[i] == 'I') {
			if (s[i + 1] == 'O'&&s[i + 2] == 'I')I++;
		}
	}
	cout << J << endl;
	cout << I << endl;
	return 0;
}