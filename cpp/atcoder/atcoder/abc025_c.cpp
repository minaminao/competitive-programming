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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	int b[2][3], c[3][2];
	int sum = 0;
	rep(i, 0, 2)rep(j, 0, 3) {
		cin >> b[i][j];
		sum += b[i][j];
	}
	rep(i, 0, 3)rep(j, 0, 2) {
		cin >> c[i][j];
		sum += c[i][j];
	}
	map<vector<vector<int>>, int> mp;
	function<int(int, vector<vector<int>>)> dfs = [&](int cnt, vector<vector<int>> v) {
		if (mp.count(v)) {
			return mp[v];
		}
		if (cnt == 9) {
			int ret = 0;
			rep(i, 0, 2)rep(j, 0, 3) {
				if (v[i][j] == v[i + 1][j])ret += b[i][j];
			}
			rep(i, 0, 3)rep(j, 0, 2) {
				if (v[i][j] == v[i][j + 1])ret += c[i][j];
			}
			return mp[v] = ret;
		}
		else {
			if (cnt & 1) {
				int ret = INF;
				rep(i, 0, 3)rep(j, 0, 3) {
					if (v[i][j] != 0)continue;
					v[i][j] = 2;
					chmin(ret, dfs(cnt + 1, v));
					v[i][j] = 0;
				}
				return mp[v] = ret;
			}
			else {
				//chokudai
				int ret = 0;
				rep(i, 0, 3)rep(j, 0, 3) {
					if (v[i][j] != 0)continue;
					v[i][j] = 1;
					chmax(ret, dfs(cnt + 1, v));
					v[i][j] = 0;
				}
				return mp[v] = ret;
			}
		}
	};
	int ans = dfs(0, vector<vector<int>>(3, vector<int>(3)));
	cout << ans << endl << sum - ans << endl;
	return 0;
}