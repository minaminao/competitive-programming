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
//	vector<int> A;
//	vector<int> data_add;
//	vector<int> bucket_add;
//	int m;
//	vector<vector<int>> modM;
//	SqrtDecomposition(int n, int m, const vector<int> &A) :n(n), m(m), A(A), sqrt_n(sqrt(n)) {
//		assert(n);
//		bucket_size = 1 + (n - 1) / sqrt_n;
//		data_add.assign(bucket_size * sqrt_n, 0);
//		bucket_add.assign(bucket_size, 0);
//		//A.resize(bucket_size * sqrt_n, 0);
//		modM.assign(m, vector<int>(bucket_size, 0));
//		rep(i, 0, n) {
//			modM[A[i] % m][i / sqrt_n]++;
//		}
//	}
//	void add(int l, int r, int val) {
//		int k = x / sqrt_n;
//		data_add[x] = val;
//		int mini = val;
//		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
//			chmin(mini, data_add[i]);
//		}
//		bucket_add[k] = mini;
//	}
//	int query(int l, int r) {
//		int ret;
//		for (int k = 0; k < bucket_size; k++) {
//			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
//			if (r <= bl || br <= l)
//				continue;
//			if (l <= bl && br <= r) {
//				bucket_add[k];
//			}
//			else {
//				for (int i = max(l, bl); i < min(r, br); i++) {
//					data_add[i];
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
//	int N, M, Q; cin >> N >> M >> Q;
//	SqrtDecomposition sd(N);
//	rep(i, 0, N) {
//		int a; cin >> a;
//		sd.update(i, a);
//	}
//
//	return 0;
//}