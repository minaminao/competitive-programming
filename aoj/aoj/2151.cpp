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
	using T = tuple<int, int>;
	for (int N, M, L; cin >> N >> M >> L&&N;) {
		static int dp[110][110];
		memset(dp, 0x3f, sizeof(dp));
		static int D[110][110], E[110][110];
		memset(D, 0x3f, sizeof(D));
		memset(E, 0x3f, sizeof(E));
		rep(i, 0, M) {
			int a, b, d, e; cin >> a >> b >> d >> e;
			a--, b--;
			D[a][b] = D[b][a] = d;
			E[a][b] = E[b][a] = e;
		}
		queue<T> q;
		q.emplace(0, L);
		dp[0][L] = 0;
		while (q.size()) {
			int u, l; tie(u, l) = q.front(); q.pop();
			rep(v, 0, N) {
				if (D[u][v] == INF)continue;
				if (D[u][v] <= l)
					if (chmin(dp[v][l - D[u][v]], dp[u][l])) 
						q.emplace(v, l - D[u][v]);
				if (chmin(dp[v][l], dp[u][l] + E[u][v]))
					q.emplace(v, l);
			}
		}
		int ans = INF;
		rep(i, 0, L + 1) {
			chmin(ans, dp[N - 1][i]);
		}
		cout << ans << endl;
	}
	return 0;
}