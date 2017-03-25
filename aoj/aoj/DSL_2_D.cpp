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
//struct SqrtDecomposition {
//	int n, sqrt_n, bucket_size;
//	vector<int> data;
//	vector<int> bucket;
//	SqrtDecomposition(int n, int val = 0) :n(n), sqrt_n(sqrt(n)) {
//		assert(n);
//		bucket_size = 1 + (n - 1) / sqrt_n;
//		data.assign(bucket_size * sqrt_n, val);
//		bucket.assign(bucket_size, val);
//	}
//	void update(int l, int r, int val) {
//		int k = x / sqrt_n;
//		data[x] = val;
//		int mini = val;
//		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
//			chmin(mini, data[i]);
//		}
//		bucket[k] = mini;
//	}
//	int query(int l, int r) {
//		int ret;
//		for (int k = 0; k < bucket_size; k++) {
//			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
//			if (r <= bl || br <= l)
//				continue;
//			if (l <= bl && br <= r) {
//				bucket[k];
//			}
//			else {
//				for (int i = max(l, bl); i < min(r, br); i++) {
//					data[i];
//				}
//			}
//		}
//		return ret;
//	}
//};
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//	return 0;
//}