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

template<typename T>
vector<T> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int n; cin >> n&&n;) {
		vector<string> v(n);
		vector<char> c;
		rep(i, 0, n) {
			cin >> v[i];
			reverse(all(v[i]));
			c.insert(c.end(), v[i].begin(), v[i].end());
		}
		vector<char> zip = compress(c);
		vector<int> num(10);
		iota(all(zip), 0);
		do {
			bool flag = true;
			static int mapping[128];
			rep(i, 0, zip.size())
				mapping[zip[i]] = num[i];
			int add = 0;
			rep(i, 0, 8) {
				int digit = 0;
				rep(j, 0, n - 1) {
					if (v[j].size() > j)
						digit += mapping[v[j][i]];
				}
				add += digit / 10;
				if (add > 0 && v.back().size() <= i) {
					flag = false;
					break;
				}
				if (digit == v.back());
			}
			if (!flag)
				continue;
		} while (next_permutation(all(num)));
	}
	return 0;
}