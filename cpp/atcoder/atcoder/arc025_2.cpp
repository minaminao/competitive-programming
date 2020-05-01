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
struct RectangleSum {
	int H, W;
	vector<vector<T>> sum;
	RectangleSum(vector<vector<T>> v)
		:H(v.size()), W(v.front().size()), sum(H + 1, vector<T>(W + 1)) {
		rep(i, 0, H + 1)rep(j, 0, W + 1) {
			sum[i][j] = (i == 0 || j == 0) ? 0 :
				sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i - 1][j - 1];
		}
		dump(sum);
		dump(v);
	}
	//[si, ti), [sj, tj)
	T get(int si, int sj, int ti, int tj) {
		return sum[ti][tj] - sum[si][tj] - sum[ti][sj] + sum[si][sj];
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W; cin >> H >> W;
	vector<vector<int>> C(H, vector<int>(W));
	rep(i, 0, H) rep(j, 0, W) {
		int c; cin >> c;
		if ((i + j) & 1)C[i][j] = -c;
		else C[i][j] = c;
	}
	RectangleSum<int> sum(C);
	int ans = 0;
	rep(i, 0, H)rep(j, 0, W)rep(k, i + 1, H + 1)rep(l, j + 1, W + 1) {
		dump(i, j, k, l, sum.get(i, j, k, l));
		if (sum.get(i, j, k, l) == 0)chmax(ans, (k - i)*(l - j));
	}
	cout << ans << endl;
	return 0;
}