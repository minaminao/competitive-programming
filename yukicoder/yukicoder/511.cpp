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

const int SQRT_N = 317;
const int MAX_N = SQRT_N*SQRT_N;
int dat[MAX_N] = {};
int bucket_max[SQRT_N] = {};
int bucket_add[SQRT_N] = {};
int lazy_bucket_update[SQRT_N] = {};
bool lazy_flag_update[SQRT_N] = {};

int n, w, h;

void add(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			bucket_add[k] += val;
			bucket_max[k] += val;
		}
		else {
			int maxi = 0;
			for (int i = bl; i < br; i++) {
				if (l <= i&&i < r)
					dat[i] += val;
				if (dat[i] + bucket_add[k] < h)
					chmax(maxi, dat[i] + bucket_add[k]);
			}
			chmax(bucket_max[k], maxi);
		}
	}
}

int query(int a, int b, int x) {
	int l = x - 1, r = x - 1 + a;
	int ret = 0;
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			if (bucket_max[k] + b >= h) {
				rep(i, bl, br) {
					if (dat[i] + bucket_add[k] < h && dat[i] + bucket_add[k] + b >= h)
						ret++;
				}
			}
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				if (dat[i] + bucket_add[k] < h &&dat[i] + bucket_add[k] + b >= h)
					ret++;
			}
		}
	}
	add(l, r, b);
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> w >> h;
	int p[2] = {};
	rep(i, 0, n) {
		int a, b, x; cin >> a >> b >> x;
		p[i & 1] += query(a, b, x);
	}
	dump(p);
	if (p[0] > p[1])
		cout << "A" << endl;
	else if (p[0] < p[1])
		cout << "B" << endl;
	else
		cout << "DRAW" << endl;
	return 0;
}