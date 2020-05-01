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

class BipartiteMatching {
public:
	int n;
	vector<vector<int>> g;
	vector<int> match;
	BipartiteMatching(int n) : n(n), g(n), match(n), used(n) {}
	void add_edge(int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	//最大マッチング
	int maximum_matching() {
		int ret = 0;
		fill(match.begin(), match.end(), -1);
		for (int v = 0; v < n; v++) {
			if (match[v] == -1) {
				fill(used.begin(), used.end(), false);
				if (dfs(v)) ret++;
			}
		}
		return ret;
	}
private:
	vector<int> used;
	bool dfs(int v) {
		used[v] = true;
		for (int u : g[v]) {
			int w = match[u];
			if (w == -1 || (!used[w] && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int X, Y, E; cin >> X >> Y >> E;
	BipartiteMatching bm(X + Y);
	rep(i, 0, E) {
		int x, y; cin >> x >> y;
		bm.add_edge(x, X + y);
	}
	cout << bm.maximum_matching() << endl;
	return 0;
}