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
	int N, M; cin >> N >> M;
	vector<string> v(N); rep(i, 0, N)cin >> v[i];
	vector<int> W(N), B(N), R(N);
	rep(i, 0, N) {
		W[i] = count(all(v[i]), 'W');
		B[i] = count(all(v[i]), 'B');
		R[i] = count(all(v[i]), 'R');
	}
	rep(i, 0, N - 1) {
		W[i + 1] += W[i];
		B[i + 1] += B[i];
		R[i + 1] += R[i];
	}
	int ans = INF;
	rep(b, 1, N - 1)rep(r, b + 1, N) {
		int tmp = 0;
		tmp += B[b - 1] + R[b - 1];
		tmp += W[r - 1] - W[b - 1] + R[r - 1] - R[b - 1];
		tmp += W[N - 1] - W[r - 1] + B[N - 1] - B[r - 1];
		chmin(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}