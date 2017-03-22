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

//input‚ÉŠÜ‚Ü‚ê‚ésearch‚ð‘S‚Äformat‚É’u‚«Š·‚¦ ”j‰ó“I
void replace_all(string& input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; getline(cin, s);
	replace_all(s, "Left", "<");
	replace_all(s, "Right", ">");
	replace_all(s, "AtCoder", "A");
	cout << s << endl;
	return 0;
}