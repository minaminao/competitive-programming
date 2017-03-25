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
const int MAX_M = 1e5;
const int SQRT_N = 317;
const int BUCKET_SIZE = 1 + (MAX_N - 1) / SQRT_N;
int dat[MAX_N] = {};
int bucket_add[SQRT_N] = {};
int modm[MAX_M][SQRT_N] = {};
int N, M, Q;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M >> Q;
	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
	rep(i, 0, N) {
		dat[i] = A[i] % M;
	}
	rep(i, 0, N) {
		modm[dat[i]][i / SQRT_N]++;
	}
	rep(i, 0, Q) {
		int l, r, d; cin >> l >> r >> d;
		l--;
		d %= M;
		int ans = 0;
		for (int k = 0; k < BUCKET_SIZE; k++) {
			int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				(bucket_add[k] += d) %= M;
				int x = (M - bucket_add[k]) % M;
				ans += modm[x][k];
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					int k = i / SQRT_N;
					modm[dat[i]][k]--;
					(dat[i] += d) %= M;
					if ((dat[i] + bucket_add[k]) % M == 0)ans++;
					modm[dat[i]][k]++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}