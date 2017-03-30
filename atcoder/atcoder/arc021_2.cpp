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
	int L; cin >> L;
	vector<int> B(L); rep(i, 0, L) { cin >> B[i]; }
	int b = 0;
	rep(i, 0, L)b ^= B[i];
	if (b != 0) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> A(L);
	rep(i, 0, L - 1) {
		A[i + 1] = B[i] ^ A[i];
	}
	rep(i, 0, L) {
		cout << A[i] << endl;
	}
	return 0;
}