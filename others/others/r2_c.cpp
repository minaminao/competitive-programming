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
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	cout << fixed << setprecision(10);
	for (int test = 0; test < T; test++) {
		int R, C; cin >> R >> C;
		vector<vector<char>> v(R, vector<char>(C));
		rep(i, 0, R) rep(j, 0, C) { cin >> v[i][j]; }

		vector<vector<bool>> hor(R, vector<bool>(C));
		vector<vector<bool>> ver(R, vector<bool>(C));

		rep(i, 0, R)rep(j, 0, C) {
			if (v[i][j] == '|' || v[i][j] == '-') {
				rep(k, 0, R) {
					if (k == i)continue;
					if (v[k][j] == '|' || v[k][j] == '-') {
						hor[k][j] = true;
					}
				}
				rep(k, 0, C) {
					if (k == j)continue;
					if (v[i][k] == '|' || v[i][k] == '-') {
						ver[i][k] = true;
					}
				}
			}
		}


		using Pos = tuple<int, int, int>;
		vector<vector<vector<Pos>>> p(R, vector<vector<Pos>>(C));

		rep(i, 0, R)rep(j, 0, C) {
			if (v[i][j] == '|' || v[i][j] == '-') {
				if (!hor[i][j]) {
					rrep(k, 0, i) {
						if (v[k][j] != '.')break;
						p[k][j].emplace_back(i, j, 0);
					}
					rep(k, i + 1, R) {
						if (v[k][j] != '.')break;
						p[k][j].emplace_back(i, j, 0);
					}
				}
				if (!ver[i][j]) {
					rrep(k, 0, j) {
						if (v[i][k] != '.')break;
						p[i][k].emplace_back(i, j, 1);
					}
					rep(k, j + 1, C) {
						if (v[i][k] != '.')break;
						p[i][k].emplace_back(i, j, 1);
					}
				}
			}
		}

		auto f = [&]() {
			p.assign(R, vector<vector<Pos>>(C));
			rep(i, 0, R)rep(j, 0, C) {
				if (v[i][j] == '|' || v[i][j] == '-') {
					if (!hor[i][j]) {
						rrep(k, 0, i) {
							if (v[k][j] != '.')break;
							p[k][j].emplace_back(i, j, 0);
						}
						rep(k, i + 1, R) {
							if (v[k][j] != '.')break;
							p[k][j].emplace_back(i, j, 0);
						}
					}
					if (!ver[i][j]) {
						rrep(k, 0, j) {
							if (v[i][k] != '.')break;
							p[i][k].emplace_back(i, j, 1);
						}
						rep(k, j + 1, C) {
							if (v[i][k] != '.')break;
							p[i][k].emplace_back(i, j, 1);
						}
					}
				}
			}
			rep(i, 0, R)rep(j, 0, C) {
				if (v[i][j] == '.') {
					if (p[i][j].size() == 1) {
						int a, b, c; tie(a, b, c) = p[i][j].front();
						if (c == 0) {
							if (ver[a][b])
								continue;
							ver[a][b] = true;
						}
						else {
							if (hor[a][b])
								continue;
							hor[a][b] = true;
						}
						return true;
					}
				}
			}
			return false;
		};

		while (f());

		bool possible = true;
		rep(i, 0, R)rep(j, 0, C) {
			if (v[i][j] == '.') {
				if (p[i][j].size() == 0) {
					possible = false;
				}
			}
		}

		rep(i, 0, R)rep(j, 0, C) {
			if (v[i][j] == '|' || v[i][j] == '-') {
				if (hor[i][j] && ver[i][j]) {
					possible = false;
				}
				else if (hor[i][j]) {
					v[i][j] = '-';
				}
				else if (ver[i][j]) {
					v[i][j] = '|';
				}
			}
		}

		if (!possible) {
			cout << "Case #" << test + 1 << ": IMPOSSIBLE" << endl;
		}
		else {
			cout << "Case #" << test + 1 << ": POSSIBLE" << endl;
			rep(i, 0, v.size()) {
				cout << v[i][0];
				rep(j, 1, v[i].size()) { cout << v[i][j]; }
				cout << endl;
			}
		}


	}
	return 0;
}