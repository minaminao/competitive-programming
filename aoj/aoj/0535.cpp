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
	for (int M; cin >> M&&M;) {
		int N; cin >> N;
		vector<vector<int>> v(N, vector<int>(M));
		rep(i, 0, N) rep(j, 0, M) { cin >> v[i][j]; }
		vector<vector<bool>> f(N, vector<bool>(M));
		static const int di[] = { 1,0,-1,0 };
		static const int dj[] = { 0,1,0,-1 };
		auto inrange = [&](int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; };
		function<int(int, int)> dfs = [&](int i, int j) {
			int ret = 0;
			f[i][j] = true;
			rep(k, 0, 4) {
				int ni = di[k] + i, nj = dj[k] + j;
				if (!inrange(ni, nj))continue;
				if (f[ni][nj])continue;
				if (v[ni][nj] == 0)continue;
				chmax(ret, dfs(ni, nj));
			}
			f[i][j] = false;
			return ret + 1;
		};
		int ans = 0;
		rep(i, 0, N)rep(j, 0, M) {
			if (v[i][j] == 0)continue;
			chmax(ans, dfs(i, j));
		}
		cout << ans << endl;
	}
	return 0;
}