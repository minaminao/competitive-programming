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

using mint = ModInt<1000000007>;

vector<mint> fact, factinv;
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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<int> A(n); rep(i, 0, n) {
		cin >> A[i];
	}
	mint ans = pow(mint(2), n - 1);
	if (k <= n) {
		int l = 0, r = 0;
		unordered_map<int, int> cnt;
		set<int> st;
		using P = pair<int, int>;
		set<P> interval;
		rep(i, 0, k + 1) {
			st.insert(i);
		}
		while (l < n) {
			dump(l, r, st, interval);
			//‹æŠÔ‚ð‹·‚ß‚é
			if (st.empty()) {
				if (A[l] > k) {
					l++;
					continue;
				}
				interval.emplace(l, r);
				if (A[l] <= k) {
					if (cnt[A[l]] == 1)
						st.insert(A[l]);
					cnt[A[l]]--;
				}
				l++;
			}
			//‹æŠÔ‚ðL‚°‚é
			else {
				if (r == n) {
					break;
				}
				if (A[r] <= k) {
					if (cnt[A[r]] == 0)
						st.erase(A[r]);
					cnt[A[r]]++;
				}
				r++;
			}
		}
		dump(l, r, st, interval);
		for (auto &e : interval) {
			if (e.first >= (*interval.begin()).second)
				break;
			int x = n - 1;
			x -= e.second - e.first - 1;
			for (P p(e.second - 1, 0);;) {
				auto _l = interval.lower_bound(p);
				if (_l == interval.end())
					break;
				auto l = *_l;
				x -= l.second - l.first - 1;
				p = P(l.second - 1, 0);
			}
			dump(ans);
			ans -= pow(mint(2), x);
		}
	}
	cout << ans << endl;
	return 0;
}