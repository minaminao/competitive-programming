//20160723
//http://arc058.contest.atcoder.jp/submissions/815261

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
template<int MOD>
ostream &operator << (ostream &os, const ModInt<MOD> &m) { return os << m.x; }
template<int MOD>
istream &operator >> (istream &is, ModInt<MOD> &m) { signed long long s; is >> s; m = ModInt<MOD>(s); return is; };
//pow(mint(2), 1000) のように
template<int MOD>
ModInt<MOD> pow(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

//#define int long long を使っても大丈夫
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

mint nHr(int n, int r) { return r == 0 ? 1 : nCr(n + r - 1, r); }






//# !Div2By1.cppを使えば乗算が速くなるかも？
//新ver. 詳しくは検証されていない！特にinverse,割り算はMODが大きいとたぶんオーバーフローする！！
//MOD * 2 <= 2^32
template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
	ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
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
		long long a = x, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return ModInt(u);
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};

//演算子の優先順位が原因でバグを生むので使わない
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

//旧ver.
//MOD * 2 <= 2^31
template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	int x;
	ModInt() : x(0) { }
	ModInt(signed sig) { if ((x = sig % MOD + MOD) >= MOD) x -= MOD; }
	ModInt(signed long long sig) { if ((x = sig % MOD + MOD) >= MOD) x -= MOD; }
	int get() const { return x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		long long a = x, b = MOD, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return ModInt(u);
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};

