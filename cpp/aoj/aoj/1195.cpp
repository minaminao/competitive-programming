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

	for (string s; cin >> s&&s != "#";) {
		int n = s.size();
		string a, b;
		vector<string> v;
		for (int mask = 0; mask < (1 << n); mask++) {
			a = s;
			bool flag = false;
			rep(i, 0, n) {
				if (mask >> i & 1) {
					if (a[i] == 'z') {
						flag = true;
						break;
					}
					a[i] += 1;
				}
			}
			if (flag)
				continue;
			b = a;
			static bool f[128];
			memset(f, 0, sizeof(f));
			rep(i, 0, n) {
				if (b[i] == 'a')continue;
				if (f[b[i]])continue;
				f[b[i]] = true;
				b[i] -= 1;
			}
			if (b == s) {
				v.emplace_back(a);
			}
		}
		cout << v.size() << endl;
		sort(all(v));
		if (v.size() > 10) {
			rep(i, 0, 5)
				cout << v[i] << endl;
			rep(i, v.size() - 5, v.size())
				cout << v[i] << endl;
		}
		else {
			rep(i, 0, v.size()) {
				cout << v[i] << endl;
			}
		}
	}
	return 0;
}