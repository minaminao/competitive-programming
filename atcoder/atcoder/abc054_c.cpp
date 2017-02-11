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
int dfs(int mask, int cur, int cnt) {
	if (cnt == N&&mask == pow(2, N) - 1)return 1;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (mask&(1 << i))continue;
		if (!f[cur][i])continue;
		int d = dfs(mask | (1 << i), i, cnt + 1);
		if (d == 0)continue;
		ret += d;
	}
	return ret;
}

signed main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		f[a][b] = f[b][a] = true;
	}
	cout << dfs(1, 0, 1) << endl;
	return 0;
}