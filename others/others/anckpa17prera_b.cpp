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
	int T; cin >> T;
	rep(t, 0, T) {
		int n; cin >> n;
		vector<vector<bool>> v(2, vector<bool>(n));
		int cnt = 0;
		rep(i, 0, 2) rep(j, 0, n) {
			char c; cin >> c;
			if (c == '#') {
				v[i][j] = true;
				cnt++;
			}
		}
		static const int di[] = { 1,-1 ,0 };
		static const int dj[] = { 0,0,1 };
		using State = tuple<int, int, int>;
		vector<vector<int>> d(2, vector<int>(n, INF));
		auto inrange = [&](int i, int j) { return i >= 0 && i < 2 && j >= 0 && j < n; };
		auto bfs = [&](int si, int sj) {
			queue<State> q;
			d.assign(2, vector<int>(n, INF));
			q.emplace(0, si, sj);
			while (q.size()) {
				int cd, ci, cj; tie(cd, ci, cj) = q.front(); q.pop();
				d[ci][cj] = cd;
				rep(i, 0, 3) {
					int ni = ci + di[i], nj = cj + dj[i];
					if (!inrange(ni, nj))continue;
					if (!v[ni][nj])continue;
					if (d[ni][nj]!=INF)continue;
					q.emplace(cd + 1, ni, nj);
					break;
				}
			}
		};

		bool yes = false;
		int tmp = 2;
		rep(j, 0, n)rep(i, 0, 2) {
			if (!v[i][j])continue;
			if (tmp--) {
				bfs(i, j);
				rep(i, 0, 2)rep(j, 0, n) {
					if (d[i][j] == cnt - 1) {
						yes = true;
					}
				}
			}
		}

		cout << (yes ? "yes" : "no") << endl;
	}
	return 0;
}