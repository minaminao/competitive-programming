//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//struct UnionFind {
//	vector<int> parent;
//	int size;
//	UnionFind(int n) :parent(n, -1), size(n) {}
//	bool unite(int x, int y) {
//		x = root(x); y = root(y);
//		if (x == y)return false;
//		if (size_of(x) < size_of(y))swap(x, y);
//		parent[x] += parent[y]; parent[y] = x; size--;
//		return true;
//	}
//	bool same(int x, int y) { return root(x) == root(y); }
//	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
//	int size_of(int x) { return -parent[root(x)]; }
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	for (int N, Q; cin >> N >> Q&&N;) {
//		vector<int> p(N); p[0] = -1; rep(i, 1, N) { cin >> p[i]; p[i]--; }
//		vector<bool> m(N); m[0] = true;
//		vector<char> q1(Q);
//		vector<int> q2(Q);
//		rep(i, 0, Q) {
//			cin >> q1[i] >> q2[i];
//			q2[i]--;
//			if (q1[i] == 'M')m[q2[i]] = true;
//		}
//		UnionFind UF(N);
//		int ans = 0;
//		rrep(i, 0, Q) {
//			if (q1[i] == 'Q') {
//				int root = UF.root(q2[i]);
//				while (!m[root]) {
//					UF.unite(root, p[root]);
//					root = p[root];
//					if (m[root]) {
//						ans += (root + 1);
//						break;
//					}
//				}
//			}
//			else {
//				if (q2[i] == 0)continue;
//				m[q2[i]] = false;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}