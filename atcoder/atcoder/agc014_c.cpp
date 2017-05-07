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
	int H, W, K; cin >> H >> W >> K;
	vector<vector<char>> v(H, vector<char>(W));
	int si, sj;
	rep(i, 0, H) rep(j, 0, W) {
		cin >> v[i][j];
		if (v[i][j] == 'S')si = i, sj = j;
	}

	vector<vector<int>> d(H, vector<int>(W, INF));
	d[si][sj] = 0;

	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
	static const int di[] = { 1,0,-1,0 };
	static const int dj[] = { 0,1,0,-1 };

	using P = pair<int, int>;
	queue<P> q;
	q.push(P(si, sj));
	for (int ci, cj; !q.empty();) {
		tie(ci, cj) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i], nj = cj + dj[i];
			if (!inrange(ni, nj))continue;
			if (v[ni][nj] == '#')continue;
			if (d[ni][nj] != INF)continue;
			d[ni][nj] = d[ci][cj] + 1;
			q.push(P(ni, nj));
		}
	}
	int ans = INF;
	rep(i, 0, H)rep(j, 0, W) {
		if (d[i][j] == INF)continue;
		if (d[i][j] > K)continue;
		if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {
			if (d[i][j] != K) {
				chmin(ans, 1);
			}
		}
		int h = min(i, H - i - 1), w = min(j, W - j - 1);
		int t = min(h, w);
		dump(i, j, t);
		chmin(ans, t / K + !!(t%K) + 1);
	}
	cout << ans << endl;
	return 0;
}