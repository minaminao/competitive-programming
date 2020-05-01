#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<(o)<<" ";}
#define dumpl(o) if(DBG){cerr<<#o<<" "<<(o)<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
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

//nCrで用いる
vector<mint> fact, factinv;
//nCrで用いる 予め計算しておく
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

//population count
//後ろから立っているbitを降ろす
int popcount(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}
//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

void solve() {
	int ans = 0;
	int n, m; cin >> n >> m;
	vector<int> a(m); rep(i, 0, m) { cin >> a[i]; }
	for (int i = 1; i < (1 << m); i++) {
		int lcm = 1;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				lcm = lcm / gcd(lcm, a[j])*a[j];
				if (lcm > n)break; //lcm>n => n/lcm == 0 よりオーバーフローする前にbreak;
			}
		}
		if (popcount(i) & 1)ans += n / lcm;
		else ans -= n / lcm;
	}
	cout << ans << endl;
}

void solve2() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int R, C; cin >> R >> C;
	int X, Y; cin >> X >> Y;
	int D, L; cin >> D >> L;
	nCr_compute_factinv(X*Y);
	mint ans = 0;
	//4つの条件をすべて満たすもの
	//包除原理
	rep(mask, 0, 1 << 4) {
		int x = X, y = Y;
		if (mask >> 0 & 1)x--;
		if (mask >> 1 & 1)x--;
		if (mask >> 2 & 1)y--;
		if (mask >> 3 & 1)y--;
		if (x <= 0 || y <= 0)continue;
		mint a = nCr(x*y, D)*nCr(x*y - D, L);
		dump(a);
		if (popcount(mask) & 1)ans -= a;
		else ans += a;
	}
	dump(ans);
	ans *= (R - X + 1)*(C - Y + 1);
	cout << ans << endl;
}