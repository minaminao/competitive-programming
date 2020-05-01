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

//nCr‚Å—p‚¢‚é
vector<mint> fact, factinv;
//nCr‚Å—p‚¢‚é —\‚ßŒvŽZ‚µ‚Ä‚¨‚­
void nCr_compute_factinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1); factinv.resize(N + 1);
	fact[0] = 1;
	rep(i, 1, N + 1) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i--) factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if (n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) * nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

int g(int mask, int ci, int cj) {
	int k = ci * 5 + cj;
	return mask >> k & 1;
}

int f(int mask, int k) {
	int ci = k / 5, cj = k % 5;
	if (ci >= 1 && ci <= 3) {
		if (g(mask, ci - 1, cj) != g(mask, ci + 1, cj))return 0;
	}
	if (cj >= 1 && cj <= 3) {
		if (g(mask, ci, cj - 1) != g(mask, ci, cj + 1))return 0;
	}
	return 1;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> x(25);
	int base = 0;
	vector<int> idx(26, -1);
	rep(i, 0, 25) {
		cin >> x[i];
		if (x[i] != 0)
			base += 1 << i;
		idx[x[i]] = i;
	}

	vector<int> dp(1 << 25, -1);
	function<mint(int, int)> dfs = [&](int mask, int n) {
		if (dp[mask] != -1)return mint(dp[mask]);
		if (mask == 0)return mint(1);
		mint ret = 0;
		//dump(idx[n]);
		if (idx[n] >= 0) {
			//dump(mask - (1 << idx[n]), n - 1);
			ret = dfs(mask - (1 << idx[n]), n - 1)*f(mask - (1 << idx[n]), idx[n]);
		}
		else {
			rep(i, 0, 25) {
				if (base >> i & 1)continue;
				if (mask >> i & 1) {
					ret += dfs(mask - (1 << i), n - 1)*f(mask - (1 << i), i);
				}
			}
		}
		//dump(bitset<25>(mask), n, ret);
		return mint(dp[mask] = ret.get());
	};
	//dump(dfs(0, 0));
	//dump(dfs(1, 1), f(0, 1));
	cout << dfs((1 << 25) - 1, 25) << endl;
	return 0;
}

void solve1() {
	vector<vector<int>> x(5, vector<int>(5));
	vector<bool> f(26);
	rep(i, 0, 5)rep(j, 0, 5) {
		cin >> x[i][j];
		f[x[i][j]] = true;
	}
	vector<int> v;
	rep(i, 1, 26) {
		if (f[i])continue;
		v.emplace_back(i);
	}
	int ans = 0;
	do {
		int idx = 0;
		vector<vector<int>> y = x;
		rep(i, 0, 5)rep(j, 0, 5) {
			if (x[i][j] == 0)y[i][j] = v[idx++];
		}
		bool flag = false;
		rep(i, 0, 5)rep(j, 0, 3) {
			if (y[i][j] < y[i][j + 1] && y[i][j + 1] < y[i][j + 2])flag = true;
			if (y[i][j] > y[i][j + 1] && y[i][j + 1] > y[i][j + 2])flag = true;
		}
		rep(i, 0, 3)rep(j, 0, 5) {
			if (y[i][j] < y[i + 1][j] && y[i + 1][j] < y[i + 2][j])flag = true;
			if (y[i][j] > y[i + 1][j] && y[i + 1][j] > y[i + 2][j])flag = true;
		}
		if (flag)continue;
		ans++;
		ans %= MOD;
	} while (next_permutation(all(v)));
	cout << ans << endl;
}