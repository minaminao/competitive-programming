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
	for (int N; cin >> N;) {
		int depth = log2(N) + 1;
		dump(depth);
		int x = 1;
		int turn = 1;
		if (depth & 1) {
			while (x <= N) {
				if (turn & 1)x = 2 * x + 1;
				else x = 2 * x;
				turn++;
				dump(x);
			}
		}
		else {
			while (x <= N) {
				if (turn & 1)x = 2 * x;
				else x = 2 * x + 1;
				turn++;
				dump(x);
			}
		}
		dump(turn);
		if (turn & 1)cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}
	return 0;
}