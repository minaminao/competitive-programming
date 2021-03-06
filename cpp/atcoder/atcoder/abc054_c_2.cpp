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


bool f[10][10] = {};
int N, M;

signed main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		f[a][b] = f[b][a] = true;
	}
	vector<int> v(N);
	iota(all(v), 0);
	int ans = 0;
	do {
		bool flag = true;
		rep(i, 1, N) {
			if (!f[v[i]][v[i - 1]]) {
				flag = false;
				break;
			}
		}
		if (flag)ans++;
	} while (next_permutation(v.begin() + 1, v.end()));
	cout << ans << endl;
	return 0;
}