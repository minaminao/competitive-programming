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

const int SQRT_N = 317;
const int MAX_N = SQRT_N*SQRT_N;
int dat[MAX_N] = {};
int bucket_min[SQRT_N] = {};
int lazy_bucket_update[SQRT_N] = {};
bool lazy_flag_update[SQRT_N] = {};

void init() {
	rep(i, 0, MAX_N)
		dat[i] = INT_MAX;
	rep(k, 0, SQRT_N)
		bucket_min[k] = INT_MAX;
}

void update(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			lazy_bucket_update[k] = val;
			lazy_flag_update[k] = true;
			bucket_min[k] = val;
		}
		else {
			if (lazy_flag_update[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket_update[k];
				}
				lazy_flag_update[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] = val;
			}
			int mini = dat[bl];
			for (int i = bl; i < br; i++)
				chmin(mini, dat[i]);
			bucket_min[k] = mini;
		}
	}
}

int find(int l, int r) {
	int mini = INT_MAX;
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			chmin(mini, bucket_min[k]);
		}
		else {
			if (lazy_flag_update[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket_update[k];
				}
				lazy_flag_update[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				chmin(mini, dat[i]);
			}
		}
	}
	return mini;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	init();
	rep(i, 0, q) {
		int c; cin >> c;
		if (c == 0) {
			int s, t, x; cin >> s >> t >> x;
			update(s, t + 1, x);
		}
		else {
			int s, t; cin >> s >> t;
			cout << find(s, t + 1) << endl;
		}
	}
	return 0;
}