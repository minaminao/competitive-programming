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
	int N, L; cin >> N >> L;
	vector<int> v(N);
	iota(all(v), 0);
	cin.ignore();
	rep(i, 0, L) {
		string s; getline(cin, s);
		rep(i, 0, N - 1) {
			if (s[i * 2 + 1] == '-') {
				swap(v[i], v[i + 1]);
			}
		}
		dump(s);
	}
	string s; getline(cin, s);
	rep(i, 0, N) {
		if (s[i * 2] == 'o') {
			cout << v[i] + 1 << endl;
		}
	}
	return 0;
}