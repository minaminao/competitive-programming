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
	int N, K; cin >> N >> K;
	vector<int> s(N); rep(i, 0, N) { cin >> s[i]; }
	if (*min_element(all(s)) == 0) {
		cout << N << endl;
		return 0;
	}
	int a = 1;
	int l = 0, r = 0;
	int ans = 0;
	while (true) {
		dump(l, r);
		if (r == N) {
			if (a <= K)chmax(ans, r - l);
			break;
		}
		if (a <= K) {
			a *= s[r];
			chmax(ans, r - l);
			r++;
		}
		else {
			a /= s[l];
			l++;
			if (l > r) {
				a = 1;
				r = l;
			}
		}
	}
	cout << ans << endl;
	return 0;
}