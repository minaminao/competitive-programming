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
	int N; cin >> N;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	int M; cin >> M;
	vector<int> b(M); rep(i, 0, M) { cin >> b[i]; }
	vector<int> c(M); rep(i, 0, M) { cin >> c[i]; }

	static int A[1000010] = {};
	rep(i, 0, N)A[a[i]] += a[i];
	rep(i, 1, 1000010)A[i] += A[i - 1];

	rep(i, 0, M) {
		int p = A[b[i]];
		if (p >= c[i])cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}