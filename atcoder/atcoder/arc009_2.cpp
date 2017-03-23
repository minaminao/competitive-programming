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

struct Radix {
	string s;
	int a[128];
	Radix(string s = "0123456789ABCDEF") :s(s) {
		for (int i = 0; i < s.size(); i++)
			a[s[i]] = i;
	}
	//10進(long long) -> n進(string)
	string format(long long x, int n) {
		if (!x) return "0";
		string ret;
		for (; x; x /= n)
			ret += s[x%n];
		reverse(ret.begin(), ret.end());
		return ret;
	}
	//m進(string) -> n進(string)
	string format(const string &t, int m, int n) {
		return format(format(t, m), n);
	}
	//m進(string) -> 10進(long long)
	long long format(const string &t, int m) {
		long long x = a[t[0]];
		for (int i = 1; i < t.size(); i++)
			x = x * m + a[t[i]];
		return x;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<char> b(10); rep(i, 0, 10) { cin >> b[i]; }
	string s;
	rep(i, 0, 10) {
		s += b[i];
	}
	dump(s);
	Radix r(s);
	using P = pair<int, string>;
	int N; cin >> N;
	vector<P> v;
	rep(i, 0, N) {
		string a; cin >> a;
		v.emplace_back(r.format(a, 10), a);
	}
	sort(all(v));
	rep(i, 0, N) {
		cout << v[i].second << endl;
	}
	return 0;
}