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
	int c[256] = {};
	string a = "zrbcdwtjfqlvsxpmhkng";
	rep(i, 0, a.size() / 2) {
		c[a[2 * i]] = i;
		c[a[2 * i + 1]] = i;
		c[toupper(a[2 * i])] = i;
		c[toupper(a[2 * i + 1])] = i;
	}
	a += "ZRBCDWTJFQLVSXPMHKNG";
	int N; cin >> N;
	vector<string> ans;
	rep(i, 0, N) {
		string w; cin >> w;
		string s;
		rep(j, 0, w.size()) {
			if (a.find(w[j]) == string::npos)continue;
			s += to_string(c[w[j]]);
		}
		if(s.size())
			ans.emplace_back(s);
	}
	rep(i, 0, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}