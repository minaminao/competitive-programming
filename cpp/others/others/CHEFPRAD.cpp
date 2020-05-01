//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//class BipartiteMatching {
//public:
//	int n;
//	vector<vector<int>> g;
//	vector<int> match;
//	BipartiteMatching(int n) : n(n), g(n), match(n), used(n) {}
//	void add_edge(int u, int v) {
//		g[u].emplace_back(v);
//		g[v].emplace_back(u);
//	}
//	//最大マッチング
//	int maximum_matching() {
//		int ret = 0;
//		fill(match.begin(), match.end(), -1);
//		for (int v = 0; v < n; v++) {
//			if (match[v] == -1) {
//				fill(used.begin(), used.end(), false);
//				if (dfs(v)) ret++;
//			}
//		}
//		return ret;
//	}
//private:
//	vector<int> used;
//	bool dfs(int v) {
//		used[v] = true;
//		for (int u : g[v]) {
//			int w = match[u];
//			if (w == -1 || (!used[w] && dfs(w))) {
//				match[v] = u;
//				match[u] = v;
//				return true;
//			}
//		}
//		return false;
//	}
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int T; cin >> T;
//	rep(t, 0, T) {
//		int N, M, e; cin >> N >> M >> e;
//		vector<int> C(N); rep(i, 0, N) {
//			cin >> C[i];
//		}
//		vector<int> D(M); rep(i, 0, M) {
//			cin >> D[i];
//		}
//		vector<int> F(N);
//		rep(x, -100, 100) {
//			rep(i, 0, N)
//				F[i] = C[i] + x;
//			BipartiteMatching bm(N + M);
//			rep(i, 0, N)rep(j, 0, M) {
//				if (abs(F[i] - D[j]) <= e) {
//					bm.add_edge(i, j + N);
//				}
//			}
//			cout << bm.maximum_matching() << endl;
//		}
//	}
//	return 0;
//}