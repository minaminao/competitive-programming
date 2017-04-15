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
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//struct RangeSumQuery {
//	int n;
//	vector<int> d;
//	RangeSumQuery(int m) {
//		for (n = 1; n < m; n *= 2);
//		d.assign(n * 2, 0);
//	}
//	void add(int i, int x) {
//		d[n + i] += x;
//		for (int j = (n + i) / 2; j > 0; j >>= 1)
//			d[j] = d[j * 2] + d[j * 2 + 1];
//	}
//	//[l, r)
//	int query(int l, int r) {
//		int sum = 0;
//		for (; l && l + (l&-l) <= r; l += l&-l)
//			sum += d[(n + l) / (l&-l)];
//		for (; l < r; r -= r&-r)
//			sum += d[(n + r) / (r&-r) - 1];
//		return sum;
//	}
//	int get(int i) { return d[n + i]; }
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	string A, B;
//	cin >> A >> B;
//	RangeSumQuery C(A.size()), D(B.size());
//	rep(i, 0, A.size()) {
//		if (A[i] == 'A')C.add(i, 1);
//		else C.add(i, 2);
//	}
//	rep(i, 0, B.size()) {
//		if (B[i] == 'A')D.add(i, 1);
//		else D.add(i, 2);
//	}
//	int q; cin >> q;
//	rep(i, 0, q) {
//		int a, b, c, d; cin >> a >> b >> c >> d;
//		a--, c--;
//		if (C.query(a, b) % 3 == D.query(c, d) % 3) {
//			cout << "YES" << endl;
//		}
//		else {
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}