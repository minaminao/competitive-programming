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
	int N; cin >> N;
	vector<int> s(N); rep(i, 0, N) { cin >> s[i]; }
	vector<int> sum(N + 1);
	rep(i, 0, N)sum[i + 1] = s[i];
	rep(i, 0, N) {
		sum[i + 1] ^= sum[i];
	}
	
	int ans = 0;
	dump(sum);
	rep(i, 0, N) {
		rep(j, i + 1, N + 1) {
			dump(i, j);
			int g = sum[i];
			dump(g);
			g ^= sum[N] ^ sum[j];
			dump(g);
			if (g == 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}