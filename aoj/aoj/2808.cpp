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
	string format(long long x, int n, int len = 1) {
		if (!x)return string(len, s[0]);
		string ret;
		for (; x || len > 0; x /= n, len--)
			ret += s[x%n];
		reverse(ret.begin(), ret.end());
		return ret;
	}
	using It = string::iterator;
	//m進(string) -> n進(string)
	string format(It l, It r, int m, int n, int len = 1) {
		return format(format(l, r, m), n, len);
	}
	//m進(string) -> 10進(long long)
	long long format(It l, It r, int m) {
		long long x = a[*l];
		for (l++; l != r; l++)
			x = x * m + a[*l];
		return x;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<string> S(N); rep(i, 0, N) { cin >> S[i]; }
	Radix r(" abcdefghijklmnopqrstuvwxyz");
	unordered_set<long long> st;
	rep(i, 0, N) {
		int n = S[i].size();
		rep(h, 1, 5) {
			rep(j, 0, n - h + 1) {
				st.emplace(r.format(S[i].begin() + j, S[i].begin() + j + h, 27));
			}
		}
	}
	rep(i, 0, pow(27, 4)) {
		if (st.count(i))continue;
		string s = r.format(i, 27);
		if (s.find(' ') != string::npos)continue;
		cout << s << endl;
		return 0;
	}
	return 0;
}