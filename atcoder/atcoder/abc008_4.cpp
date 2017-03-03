#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int W, H, N;
int X[33], Y[33];
int dp[88][88][88][88];
using pii = pair<int, int>;
vector<pii> v;
vector<int> res;

//座標圧縮（破壊的）
//index()と合わせて使う
template<typename T>
vector<int> compress(vector<T> &v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

//圧縮後の座標
//index(圧縮前の座標の配列(昇順), 圧縮前の座標)
template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }

int dfs(int p, int q, int r, int s) {
	if (dp[p][q][r][s] != INF)return dp[p][q][r][s];
	int ret = 0;
	rep(i, 0, N) {
		if (p <= X[i] && X[i] < r&&q <= Y[i] && Y[i] <= s) {
			int res =
				dfs(p, q, X[i], Y[i])
				+ dfs(X[i] + 1, q, r, Y[i])
				+ dfs(p, Y[i] + 1, X[i], s)
				+ dfs(X[i] + 1, Y[i] + 1, r, s)
				+ (r - p) + (s - q) - 1;
			chmax(ret, res);
		}
	}
	return dp[p][q][r][s] = ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> W >> H;
	cin >> N;
	memset(dp, 0x3f, sizeof(dp));

	rep(i, 0, N) {
		v.emplace_back(X[i], Y[i]);
	}
	res = compress(v);

	cout << dfs(0, 0, N, N) << endl;
	return 0;
}