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
	int N, M; cin >> N >> M;
	vector<vector<int>> b(N, vector<int>(M));
	rep(i, 0, N) rep(j, 0, M) { char c; cin >> c; b[i][j] = c - '0'; }
	vector<vector<int>> a(N, vector<int>(M));
	rep(i, 0, N - 2)rep(j, 0, M) {
		if (b[i][j] == 0)continue;
		int e = b[i][j];
		b[i + 1][j + 1] -= e;
		b[i + 1][j - 1] -= e;
		b[i + 2][j] -= e;
		b[i][j] = 0;
		a[i + 1][j] += e;
		dump(b);
		dump(a);
	}
	rep(i, 0, N) {
		rep(j, 0, M) {
			cout << (char)(a[i][j] + '0');
		}
		cout << endl;
	}
	return 0;
}