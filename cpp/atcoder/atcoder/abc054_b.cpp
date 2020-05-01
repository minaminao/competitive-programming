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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int N, M;
vector<string> A, B;
int f(int i, int j) {
	rep(k, 0, M)rep(l, 0, M) {
		if (A[i + k][j + l] != B[k][l]) return 0;
	}
	return 1;
}

signed main() {
	cin >> N >> M;
	A.resize(N); rep(i, 0, N) { cin >> A[i]; }
	B.resize(M); rep(i, 0, M) { cin >> B[i]; }
	rep(i, 0, N - M + 1)rep(j, 0, N - M + 1) {
		if (f(i, j)) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}