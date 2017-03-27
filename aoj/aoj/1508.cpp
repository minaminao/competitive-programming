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
//
//const int SQRT_N = 317;
//const int MAX_N = SQRT_N*SQRT_N;
//int bucket_min[SQRT_N] = {};
//int bucket_min_pos[SQRT_N] = {};
//vector<int> bucket[SQRT_N];
//
//void init(const vector<int> &v) {
//	memset(bucket_min, 0x3f, sizeof(bucket_min));
//	for (int i = 0; i < v.size(); i++) {
//		int k = i / SQRT_N;
//		bucket[k].emplace_back(v[i]);
//		if (chmin(bucket_min[k], v[i])) {
//			bucket_min_pos[k] = i;
//		}
//	}
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n, q; cin >> n >> q;
//	vector<int> v(n); rep(i, 0, n) { cin >> v[i]; }
//	init(v);
//	rep(i, 0, q) {
//		int x, y, z; cin >> x >> y >> z;
//		if (x == 0) {
//			circular_shift(y, z + 1);
//		}
//		else if (x == 1) {
//			cout << get_min(y, z + 1) << endl;
//		}
//		else {
//			update(y, z);
//		}
//	}
//	return 0;
//}