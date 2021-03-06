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
	int N; cin >> N;
	vector<vector<int>> v(3, vector<int>(N));
	rep(i, 0, N) {
		rep(j, 0, 3) {
			cin >> v[j][i];
		}
	}
	vector<int> ans(N);
	rep(i, 0, 3) {
		unordered_map<int, int> mp;
		rep(j, 0, N)mp[v[i][j]]++;
		rep(j, 0, N) {
			if (mp[v[i][j]] >= 2)continue;
			ans[j] += v[i][j];
		}
	}
	rep(i, 0, N) {
		cout << ans[i] << endl;
	}
	return 0;
}