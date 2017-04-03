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

	const int MAX_LEN = 10;
	char S[50001];
	while (cin >> S) {
		int N = strlen(S);
		unordered_map<string, int> counts;
		rep(len, 1, MAX_LEN + 1)
			rep(i, 0, N - len + 1)
			counts[string(S + i, S + i + len)]++;
		int M; cin >> M;
		int ans = 0;
		rep(i, 0, M) {
			char C[11];
			cin >> C;
			ans += counts[C];
		}
		cout << ans << endl;
	}
	return 0;
}