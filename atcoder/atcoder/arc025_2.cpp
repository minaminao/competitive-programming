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
	int H, W; cin >> H >> W;
	vector<vector<int>> b(H, vector<int>(W)), w(H, vector<int>(W));
	rep(i, 0, H) rep(j, 0, W) {
		int c; cin >> c;
		if ((i + j) & 1)b[i][j] = c;
		else w[i][j] = c;
	}
	rep(i, 0, H)rep(j, 0, W - 1) {
		b[i][j + 1] += b[i][j];
		w[i][j + 1] += w[i][j];
	}
	rep(i, 0, H - 1)rep(j, 0, W) {
		b[i + 1][j] += b[i][j];
		w[i + 1][j] += w[i][j];
	}
	int ans = 0;
	rep(i, -1, H)rep(j, -1, W)rep(k, 0, H)rep(l, 0, W) {
		int p, q, r, s;
		int b_, w_;
		p = b[k][l], q = j == -1 ? 0 : b[k][j], r = i == -1 ? 0 : b[i][l], s = i == -1 || j == -1 ? 0 : b[i][j];
		b_ = p - q - r + s;
		p = w[k][l], q = j == -1 ? 0 : w[k][j], r = i == -1 ? 0 : w[i][l], s = i == -1 || j == -1 ? 0 : w[i][j];
		w_ = p - q - r + s;
		if (w_ == b_) {
			chmax(ans, (k - i)*(l - j));
		}
	}
	cout << ans << endl;
	return 0;
}