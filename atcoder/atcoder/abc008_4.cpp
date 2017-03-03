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
vector<int> X, Y;
int dp[88][88][88][88];
map<int, int> zipx, zipy;

//ç¿ïWà≥èk(map)
//ñﬂÇËíl: zip[à≥èkëOÇÃç¿ïW]:à≥èkå„ÇÃç¿ïW (zip.size()<=10^5Ç»ÇÁçÇë¨Ç…ìÆçÏ)
template<typename T>
map<T, T> compress(vector<T> v) {
	map<T, T> zip;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
	return zip;
}

int dfs(int p, int q, int r, int s) {
	int zp = zipx[p], zq = zipy[q], zr = zipx[r], zs = zipy[s];
	if (dp[zp][zq][zr][zs] != INF)return dp[zp][zq][zr][zs];
	int ret = 0;
	rep(i, 0, N) {
		if (p <= X[i] && X[i] < r&&q <= Y[i] && Y[i] < s) {
			int res =
				dfs(p, q, X[i], Y[i])
				+ dfs(X[i] + 1, q, r, Y[i])
				+ dfs(p, Y[i] + 1, X[i], s)
				+ dfs(X[i] + 1, Y[i] + 1, r, s)
				+ (r - p) + (s - q) - 1;
			chmax(ret, res);
		}
	}
	dump(zp, zq, zr, zs, ret);
	return dp[zp][zq][zr][zs] = ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> W >> H;
	cin >> N;
	memset(dp, 0x3f, sizeof(dp));
	X.resize(N); Y.resize(N);
	rep(i, 0, N) { cin >> X[i] >> Y[i]; X[i]--, Y[i]--; }
	vector<int> XX = X, YY = Y;
	rep(i, 0, N) {
		XX.emplace_back(X[i] + 1);
		YY.emplace_back(Y[i] + 1);
	}
	XX.emplace_back(0);
	YY.emplace_back(0);
	XX.emplace_back(W);
	YY.emplace_back(H);

	zipx = compress(XX), zipy = compress(YY);
	dump(zipx);
	dump(zipy);
	cout << dfs(0, 0, W, H) << endl;
	return 0;
}