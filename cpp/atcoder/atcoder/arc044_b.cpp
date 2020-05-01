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


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
	if (A[0] != 0) {
		cout << 0 << endl;
		return 0;
	}
	unordered_map<int, int> cnt;
	rep(i, 0, N)cnt[A[i]]++;
	if (cnt[0] > 1) {
		cout << 0 << endl;
		return 0;
	}
	int c = 0;
	int last = N;
	rep(i, 0, N) {
		if (cnt[i] == 0) {
			if (c != N) {
				cout << 0 << endl;
				return 0;
			}
			last = i;
			break;
		}
		c += cnt[i];
	}
	mint ans = 1;
	dump(cnt);
	rep(i, 1, last) {
		ans *= pow(pow(mint(2), cnt[i - 1]) - 1, cnt[i]);
		dump(ans);
		ans *= pow(mint(2), cnt[i] * (cnt[i] - 1) / 2);
		dump(ans);
	}
	cout << ans << endl;
	return 0;
}