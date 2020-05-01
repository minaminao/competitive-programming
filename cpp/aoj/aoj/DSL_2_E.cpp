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

struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> data;
	vector<int> bucket;
	SqrtDecomposition(int n) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		data.assign(bucket_size * sqrt_n, 0);
		bucket.assign(bucket_size, 0);
	}
	int get(int x) {
		return data[x] + bucket[x / sqrt_n];
	}
	void add(int l, int r, int val) {
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				bucket[k] += val;
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					data[i] += val;
				}
			}
		}
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	SqrtDecomposition sd(n);
	rep(i, 0, q) {
		int com; cin >> com;
		if (com == 0) {
			int s, t, x; cin >> s >> t >> x;
			sd.add(s - 1, t, x);
		}
		else {
			int i; cin >> i;
			cout << sd.get(i - 1) << endl;
		}
	}
	return 0;
}