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
	using P = pair<int, int>;
	for (int h, w, c; cin >> h >> w >> c&&h;) {
		int ans = 1;
		static int p[10][10];
		rep(i, 0, h)rep(j, 0, w) {
			cin >> p[i][j];
		}
		auto inrange = [&](int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; };
		static const int di[] = { 1,0,-1,0 };
		static const int dj[] = { 0,1,0,-1 };
		rep(i, 0, 6 * 6 * 6 * 6 * 6) {
			static bool f[10][10];
			memset(f, 0, sizeof(f));
			set<P> st;
			st.emplace(0, 0);
			f[0][0] = true;
			queue<P> q;
			q.emplace(0, 0);
			while (q.size()) {
				int ci, cj;
				tie(ci, cj) = q.front(); q.pop();
				int color = p[ci][cj];
				rep(k, 0, 4) {
					int ni = ci + di[k], nj = cj + dj[k];
					if (!inrange(ni, nj))continue;
					if (p[ni][nj] != p[ci][cj])continue;
					if (f[ni][nj])continue;
					q.emplace(ni, nj);
					st.emplace(ni, nj);
					f[ni][nj] = true;
				}
			}
			if (i == 0) {
				dump(st);
			}
			int ti = i;
			rep(j, 0, 5) {
				int color = ti % 6 + 1;
				if (j == 4)if (color != c) {
					st.clear();
					break;
				}
				ti /= 6;

				queue<P> q;
				for (auto &e : st)
					q.emplace(e);
				while (q.size()) {
					int ci, cj;
					tie(ci, cj) = q.front(); q.pop();
					rep(k, 0, 4) {
						int ni = ci + di[k], nj = cj + dj[k];
						if (!inrange(ni, nj))continue;
						if (p[ni][nj] != color)continue;
						if (f[ni][nj])continue;
						st.emplace(ni, nj);
						q.emplace(ni, nj);
						f[ni][nj] = true;
					}
				}
			}
			chmax(ans, (int)st.size());
		}
		cout << ans << endl;
	}
	return 0;
}