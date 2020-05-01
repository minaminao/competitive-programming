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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int N, M;

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += MOD;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
template <int M>
ostream &operator << (ostream &os, const ModInt<M> &m) { return os << m.x; }
template <int M>
istream &operator >> (istream &is, ModInt<M> &m) { signed long long s; is >> s; m = ModInt<M>(s); return is; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

using mint = ModInt<1000000007>;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<int> f(N), g(M + 1, -1), h(N);
	rep(i, 0, N) { cin >> f[i]; }
	int l = 0; g[f[0]] = 0; h[0] = 1;
	rep(i, 1, N) {
		if (l <= g[f[i]])l = g[f[i]] + 1;
		g[f[i]] = i;
		h[i] = i - l + 1;
		dump(l, g, h);
	}
	dump(g, h);
	vector<mint> dp(N + 1), sum(N + 1);
	dp[0] = sum[0] = 1;
	rep(i, 1, N + 1) {
		dp[i] = sum[i - 1] - (i - 1 - h[i - 1] < 0 ? 0 : sum[i - 1 - h[i - 1]]);
		sum[i] = sum[i - 1] + dp[i];
	}
	dump(dp, sum);
	cout << dp[N] << endl;
	return 0;
}