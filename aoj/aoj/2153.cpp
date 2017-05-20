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

const int N = 52;
char l[N][N], r[N][N];
int dp[N][N][N][N];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int W, H; cin >> W >> H&&H;) {
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(dp, 0x3f, sizeof(dp));
		int sli, slj, sri, srj;
		int gli, glj, gri, grj;
		rep(i, 0, H) {
			rrep(j, 0, W) {
				cin >> l[i][j];
				if (l[i][j] == 'L') {
					sli = i, slj = j;
				}
				if (l[i][j] == '%') {
					gli = i, glj = j;
				}
			}
			rep(j, 0, W) {
				cin >> r[i][j];
				if (r[i][j] == 'R') {
					sri = i, srj = j;
				}
				if (r[i][j] == '%') {
					gri = i, grj = j;
				}
			}
		}
		using T = tuple<int, int, int, int, int>;
		queue<T> q;
		q.emplace(sli, slj, sri, srj, 0);
		auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
		while (q.size()) {
			int li, lj, ri, rj, c;
			tie(li, lj, ri, rj, c) = q.front(); q.pop();
			if (dp[li][lj][ri][rj] != INF)continue;
			if (li == gli && lj == glj && ri == gri && rj == grj) {
				cout << "Yes" << endl;
				dp[li][lj][ri][rj] = c;
				break;
			}
			else if (li == gli&&lj == glj) {
				continue;
			}
			else if (ri == gri&&rj == grj) {
				continue;
			}
			dp[li][lj][ri][rj] = c;
			static const int di[] = { 1,0,-1,0 };
			static const int dj[] = { 0,1,0,-1 };
			rep(k, 0, 4) {
				int nli = li + di[k],
					nlj = lj + dj[k],
					nri = ri + di[k],
					nrj = rj + dj[k];
				if (!inrange(nli, nlj) || l[nli][nlj] == '#')nli -= di[k], nlj -= dj[k];
				if (!inrange(nri, nrj) || r[nri][nrj] == '#')nri -= di[k], nrj -= dj[k];
				if (dp[nli][nlj][nri][nrj] != INF)continue;
				q.emplace(nli, nlj, nri, nrj, c + 1);
			}
		}
		//rep(li, 0, H)rep(lj, 0, W)rep(ri, 0, H)rep(rj, 0, W) {
		//	if (dp[li][lj][ri][rj] == INF)continue;
		//	dump(li, lj, ri, rj, dp[li][lj][ri][rj]);
		//}
		if (dp[gli][glj][gri][grj] == INF) {
			cout << "No" << endl;
		}
	}
	return 0;
}