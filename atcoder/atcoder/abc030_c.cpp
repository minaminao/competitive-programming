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
	int N, M; cin >> N >> M;
	int X, Y; cin >> X >> Y;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	vector<int> b(M); rep(i, 0, M) { cin >> b[i]; }
	int i = 0, j = 0;
	int ans = 0, t = 0;
	while (true) {
		while (t > a[i]) {
			i++;
			if (i == N)break;
		}
		if (i == N)break;
		t = a[i] + X;
		while (t > b[j]) {
			j++;
			if (j == M)break;
		}
		if (j == M)break;
		t = b[j] + Y;
		ans++;
	}
	cout << ans << endl;
	return 0;
}