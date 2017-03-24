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
//struct RangeAddQuery {
//	int n;
//	vector<int> d;
//	int time;
//	RangeAddQuery(int m) {
//		for (n = 1; n < m; n *= 2);
//		d.assign(n * 2, 0);
//	}
//	//[l, r)
//	void add(int l, int r, int x) {
//		if (x == 1) {
//			for (; l && l + (l&-l) <= r; l += l&-l)
//				d[(n + l) / (l&-l)] += x;
//			for (; l < r; r -= r&-r)
//				d[(n + r) / (r&-r) - 1] += x;
//		}
//		else {
//
//		}
//	}
//	int get(int i) {
//		int ret = d[n + i];
//		for (int j = (n + i) / 2; j > 0; j >>= 1)
//			ret += d[j];
//		return ret;
//	}
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n; cin >> n;
//	RangeAddQuery ruq(n);
//	//rep(i, 0, n) {
//	//	char c; cin >> c;
//	//	ruq.add(i, i + 1, c - '0');
//	//}
//	dump(ruq.d);
//	int q; cin >> q;
//	rep(i, 0, q) {
//		int l, r, b; cin >> l >> r >> b;
//		ruq.update(l, r + 1, b);
//	}
//	dump(ruq.d);
//	vector<int> v(n);
//	rep(i, 0, n) {
//		v[i] = ruq.get(i);
//	}
//
//	dump(v);
//	int f = 0, g = 0;
//	rep(i, 0, n) {
//		f += v[i];
//	}
//	rep(i, 0, n - 1) {
//		g += v[i] * v[i + 1];
//	}
//	cout << f - g << endl;
//
//	return 0;
//}