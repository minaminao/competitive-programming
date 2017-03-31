//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//template<int MOD>
//struct ModInt {
//	static const int Mod = MOD;
//	unsigned x;
//	ModInt() : x(0) {}
//	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
//	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
//	int get() const { return (int)x; }
//
//	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
//	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
//	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
//	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
//
//	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
//	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
//	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
//	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
//
//	ModInt inverse() const {
//		signed a = x, b = MOD, u = 1, v = 0;
//		while (b) {
//			signed t = a / b;
//			a -= t * b; std::swap(a, b);
//			u -= t * v; std::swap(u, v);
//		}
//		if (u < 0) u += MOD;
//		ModInt res; res.x = (unsigned)u;
//		return res;
//	}
//};
//template <int M>
//ostream &operator << (ostream &os, const ModInt<M> &m) { return os << m.x; }
//template <int M>
//istream &operator >> (istream &is, ModInt<M> &m) { signed long long s; is >> s; m = ModInt<M>(s); return is; };
//template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
//	ModInt<MOD> r = 1;
//	while (k) {
//		if (k & 1) r *= a;
//		a *= a;
//		k >>= 1;
//	}
//	return r;
//}
//
//using mint = ModInt<1000000007>;
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> D(N); rep(i, 0, N) { cin >> D[i]; }
//	sort(all(D));
//	vector<vector<bool>> flag(N, vector<bool>(4));
//	vector<vector<mint>> dp(N, vector<mint>(4));
//	function<mint(int, int)> dfs = [&](int idx, int cnt) {
//		if (flag[idx][cnt])return dp[idx][cnt];
//		if (cnt == 3) {
//			return mint(1);
//		}
//		int e = lower_bound(all(D), D[idx] * 2) - D.begin();
//		if (e == N)return mint(0);
//		mint ret = 0;
//		rep(i, e, N)ret += dfs(i, cnt + 1);
//		flag[idx][cnt] = true;
//		return dp[idx][cnt] = ret;
//	};
//	mint ans = 0;
//	rep(i, 0, N)ans += dfs(i, 0);
//	cout << ans << endl;
//	return 0;
//}