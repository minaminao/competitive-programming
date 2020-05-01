#include "GraphTheory.cpp"

//二部グラフ O(f(N+M)) fは最大マッチングの数
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
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235595