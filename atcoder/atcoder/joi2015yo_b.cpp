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
	int N; cin >> N;
	int M; cin >> M;
	vector<int> A(M); rep(i, 0, M) { cin >> A[i]; A[i]--; }
	vector<int> ans(N);
	rep(i, 0, M) {
		rep(j, 0, N) {
			int b; cin >> b; b--;
			if (b == A[i])ans[j]++;
			else ans[A[i]]++;
		 }
	}
	rep(i, 0, N) {
		cout << ans[i] << endl;
	}
	return 0;
}