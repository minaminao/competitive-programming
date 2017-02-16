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
#define MAX 1000010
int A[MAX] = {};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, 0, n) {
		int a, b; cin >> a >> b;
		A[a]++; A[b + 1]--;
	}
	rep(i, 0, MAX - 1)A[i + 1] += A[i];
	cout << *max_element(all(A)) << endl;
	return 0;
}