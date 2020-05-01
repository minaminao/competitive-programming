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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K, L, R; cin >> N >> K >> L >> R;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	vector<int> A[41], B[41];
	A[0].emplace_back(0);
	B[0].emplace_back(0);
	rep(i, 0, N / 2) {
		rrep(k, 0, K) {
			rep(j, 0, A[k].size()) {
				A[k + 1].emplace_back(A[k][j] + a[i]);
			}
		}
	}
	rep(i, N / 2, N) {
		rrep(k, 0, K) {
			rep(j, 0, B[k].size()) {
				B[k + 1].emplace_back(B[k][j] + a[i]);
			}
		}
	}
	int ans = 0;
	rep(k, 0, K + 1) {
		sort(all(A[k]));
		sort(all(B[K - k]));
		rep(i, 0, A[k].size()) {
			ans += upper_bound(all(B[K - k]), R - A[k][i]) - lower_bound(all(B[K - k]), L - A[k][i]);
		}
	}
	cout << ans << endl;
	return 0;
}