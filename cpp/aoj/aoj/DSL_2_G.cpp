#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int MAX_N = 1e5;
const int SQRT_N = 317;
int dat[MAX_N] = {};
int bucket_add[SQRT_N] = {};
int bucket_sum[SQRT_N] = {};

void add(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			bucket_add[k] += val;
			bucket_sum[k] += val*SQRT_N;
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] += val;
				bucket_sum[k] += val;
			}
		}
	}
}

int get_sum(int l, int r) {
	int ret = 0;
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			ret += bucket_sum[k];
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				ret += dat[i] + bucket_add[k];
			}
		}
	}
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	rep(i, 0, q) {
		int c; cin >> c;
		if (c == 0) {
			int s, t, x; cin >> s >> t >> x;
			add(s - 1, t, x);
		}
		else {
			int s, t; cin >> s >> t;
			cout << get_sum(s - 1, t) << endl;
		}
	}
	return 0;
}