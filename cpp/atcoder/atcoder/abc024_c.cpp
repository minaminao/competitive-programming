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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	int N, D, K; cin >> N >> D >> K;
	vector<int> L(D), R(D); rep(i, 0, D) { cin >> L[i] >> R[i]; L[i]--, R[i]--; }
	vector<int> S(K), T(K); rep(i, 0, K) { cin >> S[i] >> T[i]; S[i]--, T[i]--; }
	vector<int> ans(K);
	rep(i, 0, D) {
		rep(j, 0, K) {
			if (S[j] == T[j])continue;
			if (L[i] <= S[j] && S[j] <= R[i]) {
				if (R[i] < T[j]) {
					S[j] = R[i];
				}
				else if (T[j] < L[i]) {
					S[j] = L[i];
				}
				else {
					S[j] = T[j];
					ans[j] = i + 1;
				}
			}
		}
	}
	rep(i, 0, K)cout << ans[i] << endl;
	return 0;
}