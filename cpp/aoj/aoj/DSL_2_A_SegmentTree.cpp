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
//struct SegmentTree {
//	int n;
//	vector<int> d;
//	SegmentTree(int m, int v = 0) {
//		for (n = 1; n < m; n *= 2);
//		d.assign(n * 2, v);
//	}
//	void update(int i, int x) {
//		d[n + i] = x;
//		for (int j = (n + i) / 2; j > 0; j >>= 1)
//			d[j] = min(d[j * 2], d[j * 2 + 1]);
//	}
//	// [l, r)
//	int query(int l, int r) {
//		assert(l < r);
//		int mini = get(l);
//		for (; l && l + (l&-l) <= r; l += l&-l)
//			mini = min(mini, d[(n + l) / (l&-l)]);
//		for (; l < r; r -= r&-r)
//			mini = min(mini, d[(n + r) / (r&-r) - 1]);
//		return mini;
//	}
//	int get(int i) { return d[n + i]; }
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n, q; cin >> n >> q;
//	SegmentTree st(n, INT_MAX);
//	rep(i, 0, q) {
//		int com, x, y; cin >> com >> x >> y;
//		dump(com, x, y);
//		if (com == 0) {
//			st.update(x, y);
//		}
//		else {
//			cout << st.query(x, y + 1) << endl;
//		}
//	}
//	return 0;
//}