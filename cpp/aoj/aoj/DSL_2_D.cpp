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

const int MAX_N = 1e5;
const int SQRT_N = 317;
const int BUCKET_SIZE = 1 + (MAX_N - 1) / SQRT_N;
int dat[MAX_N] = {};
int lazy_bucket[SQRT_N] = {};
bool lazy_flag[SQRT_N] = {};

void init(int n) {
	rep(i, 0, n) {
		dat[i] = INT_MAX;
	}
}

int get(int x) {
	int k = x / SQRT_N;
	return lazy_flag[k] ? lazy_bucket[k] : dat[x];
}

void update(int l, int r, int val) {
	for (int k = 0; k < BUCKET_SIZE; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			lazy_bucket[k] = val;
			lazy_flag[k] = true;
		}
		else {
			if (lazy_flag[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket[k];
				}
				lazy_flag[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] = val;
			}
		}
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	init(n);
	rep(i, 0, q) {
		int c; cin >> c;
		if (c == 0) {
			int s, t, x; cin >> s >> t >> x;
			update(s, t + 1, x);
		}
		else {
			int i; cin >> i;
			cout << get(i) << endl;
		}
	}
	return 0;
}