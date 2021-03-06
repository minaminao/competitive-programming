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

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//最小公倍数
int lcm(int x, int y) { return x*y / gcd(x, y); }

void solve1() {
	int N, K; cin >> N >> K;
	assert(K <= 100);
	mint ans = 0;
	if (N > K) {
		rep(i, 1, K + 1) {
			mint n = (N - i) / K;
			mint m = n*(n + 1)*K / 2 + (n + 1)*i;
			dump(n, m);
			ans += m*K / gcd(i, K);
		}
	}
	else {
		rep(i, 1, N + 1)ans += lcm(i, K);
	}
	cout << ans << endl;
}

//約数を求める 未ソート
vector<int> divisor(int x) {
	vector<int> ret;
	int i;
	for (i = 1; i*i < x; i++) {
		if (x%i)continue;
		ret.emplace_back(i);
		ret.emplace_back(x / i);
	}
	if (i*i == x)ret.emplace_back(i);
	return ret;
}

//エラトステネスの篩
vector<char> eratos(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++)
		if (is_prime[i]) {
			int j = i + i;
			while (j <= n) {
				is_prime[j] = false;
				j += i;
			}
		}
	return is_prime;
}
//戻り値: n以下の素数
vector<int> get_primes(int n) {
	vector<char> is_prime = eratos(n);
	vector<int> primes;
	for (int i = 0; i < n + 1; i++)
		if (is_prime[i])
			primes.emplace_back(i);
	return primes;
}
//素因数分解 昇順
vector<int> prime_factorization(int x) {
	vector<int> primes = get_primes(sqrt(x)); //√x以下の素数について調べれば良い
	vector<int> factors;
	for (auto &p : primes) {
		while (x%p == 0) {
			x /= p;
			factors.emplace_back(p);
		}
	}
	if (x != 1)factors.emplace_back(x);
	return factors;
}

//population count
//立っているbitの数を数える
int popcount(int x) {
	int ret = 0;
	//後ろから立っているbitを降ろす
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}

mint arithsum(int x) {
	return (mint)x*(x + 1) / 2;
}

//gcd(a, K) = 1, a <= N を満たす a の総和
mint solve(int N, int K) {
	vector<int> factors = prime_factorization(K);
	factors.erase(unique(factors.begin(), factors.end()), factors.end());
	int n = factors.size();
	mint ret = arithsum(N);
	rep(mask, 1, 1 << n) {
		int x = 1;
		rep(i, 0, n)
			if (mask >> i & 1)
				x *= factors[i];
		if (popcount(mask) & 1)
			ret -= arithsum(N / x)*x;
		else
			ret += arithsum(N / x)*x;
	}
	return ret;
}

//gcd(a, K) = g, a <= N を満たす a の総和
mint solve(int N, int K, int g) {
	if (K%g)return 0;
	return solve(N / g, K / g)*g;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<int> d = divisor(K);
	mint ans = 0;
	/*
		lcm(x1, K) + lcm(x2, K) + ...
		= x1 * K / gcd(x1, K) + x2 * K / gcd(x2, K) + ...
		
		gcd(a1, K) = gcd(a2, K) = ... = g とする 
		(a1 + a2 + ... ) * K / gcd(a, K)
		= (Σa) * K / g

		gcd(a, K) のとりうる値は K の約数全てである

		約数の個数を d、素因数の個数を p とする
		O( d(K) * 2^p(K) * p(K) )
		
		K<=10^9 のとき d(K) <= 1344, p(K) <= 9
	*/
	rep(i, 0, d.size()) {
		ans += solve(N, K, d[i])*K / d[i];
	}
	cout << ans << endl;
	return 0;
}