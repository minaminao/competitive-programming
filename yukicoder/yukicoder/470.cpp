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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

void visit(const vector<vector<int>> &g, int v,
	vector<int> &scccolor, int &colors,
	vector<int> &S, vector<char> &inS,
	vector<int> &low, vector<int> &num, int &time) {
	low[v] = num[v] = ++time;
	S.push_back(v); inS[v] = true;
	for (auto &e : g[v]) {
		int w = e;
		if (num[w] == 0) {
			visit(g, w, scccolor, colors, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		while (1) {
			int w = S.back(); S.pop_back(); inS[w] = false;
			scccolor[w] = colors;
			if (v == w) break;
		}
		colors++;
	}
}
int strongly_connected_components(const vector<vector<int>> &g, vector<int> &scccolor) {
	const int n = g.size();
	vector<int> num(n), low(n);
	vector<int> S;
	vector<char> inS(n);
	scccolor.resize(n);
	int time = 0, colors = 0;
	rep(u, 0, n) if (num[u] == 0)
		visit(g, u, scccolor, colors, S, inS, low, num, time);
	return colors;
}

bool two_satisfiability(const vector<vector<int>> &g) {
	int n = g.size() / 2;
	vector<int> scccolor;
	strongly_connected_components(g, scccolor);
	rep(i, 0, n) if (scccolor[i] == scccolor[n + i]) return false;
	return true;
}

signed main() {
	auto f = [](string a, string b, int c, int d) {
		if (c == d)
			return a.substr(0, c) == b.substr(0, d) || a.substr(c, 3) == b.substr(d, 3);
		else
			return a.substr(0, c) == b.substr(d, 3) || a.substr(c, 3) == b.substr(0, d);
	};
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	while (cin >> N) {
		vector<string> v(N); rep(i, 0, N) { cin >> v[i]; }
		vector<vector<int>> g(N * 2);
		rep(i, 0, N) rep(j, 0, i) {
			string a = v[i], b = v[j];
			rep(x, 0, 2) {
				rep(y, 0, 2) {
					if (f(a, b, x, y)) { //êßñÒ
						g[(1 - x) * N + i].push_back(y * N + j);
						g[(1 - y) * N + j].push_back(x * N + i);
					}
				}
			}
		}
		cout << (two_satisfiability(g) ? "YES" : "NO") << endl;
	}
	return 0;
}