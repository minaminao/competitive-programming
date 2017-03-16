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
	vector<vector<int>> x(5, vector<int>(5));
	vector<bool> f(26);
	rep(i, 0, 5)rep(j, 0, 5) {
		cin >> x[i][j];
		f[x[i][j]] = true;
	}
	vector<int> v;
	rep(i, 1, 26) {
		if (f[i])continue;
		v.emplace_back(i);
	}
	int ans = 0;
	do {
		int idx = 0;
		vector<vector<int>> y = x;
		rep(i, 0, 5)rep(j, 0, 5) {
			if (x[i][j] == 0)y[i][j] = v[idx++];
		}
		bool flag = false;
		rep(i, 0, 5)rep(j, 0, 3) {
			if (y[i][j] < y[i][j + 1] && y[i][j + 1] < y[i][j + 2])flag = true;
			if (y[i][j] > y[i][j + 1] && y[i][j + 1] > y[i][j + 2])flag = true;
		}
		rep(i, 0, 3)rep(j, 0, 5) {
			if (y[i][j] < y[i + 1][j] && y[i + 1][j] < y[i + 2][j])flag = true;
			if (y[i][j] > y[i + 1][j] && y[i + 1][j] > y[i + 2][j])flag = true;
		}
		if (flag)continue;
		ans++;
		ans %= MOD;
	} while (next_permutation(all(v)));
	cout << ans << endl;
	return 0;
}