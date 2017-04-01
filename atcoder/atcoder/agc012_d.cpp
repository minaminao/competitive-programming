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

struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
};

template<class T, class ...Tail>
void tied_sort(vector<T> &a, vector<Tail>&... tail) {
	int n = a.size();
	using S = tuple<T, Tail...>;
	vector<S> s(n);
	for (int i = 0; i < n; i++)
		s[i] = make_tuple(a[i], tail[i]...);
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		tie(a[i], tail[i]...) = s[i];
}

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

mint number_of_arrangement(vector<int> v) {
	int n = v.size();
	assert(fact.size() >= n);
	mint ret = fact[n];
	unordered_map<int, int> cnt;
	for (auto &e : v)cnt[e]++;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &e : v)ret /= fact[cnt[e]];
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, X, Y; cin >> N >> X >> Y;
	nCr_compute_factinv(N);
	vector<int> c(N), w(N); rep(i, 0, N) { cin >> c[i] >> w[i]; c[i]--; }
	int maxc = *max_element(all(c));
	dump(maxc);
	if (maxc == 0) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> c_ = c, w_ = w;
	vector<int> idx(N); iota(all(idx), 0);
	tied_sort(c_, w_, idx);
	dump(c_, w_, idx);
	vector<int> cminwidx(N);
	rep(i, 0, N) {
		cminwidx[i] = idx[lower_bound(all(c_), i) - c_.begin()];
	}
	dump(cminwidx);
	UnionFind uf(N);
	int minwidx = min_element(all(w)) - w.begin();
	rep(i, 0, N) {
		if (w[cminwidx[c[i]]] + w[i] <= X)uf.unite(cminwidx[c[i]], i);
	}
	dump(uf.parent);
	rep(i, 0, N) {
		if (w[minwidx] + w[i] <= Y)uf.unite(minwidx, i);
	}
	dump(uf.parent);
	vector<int> ridx(N);
	rep(i, 0, N) {
		ridx[i] = uf.root(i);
	}
	c_ = c;
	tied_sort(ridx, c_);
	vector<int> tmp;
	int prev = ridx.front();
	mint ans = 1;
	rep(i, 0, N) {
		if (prev == ridx[i]) {
			tmp.emplace_back(c_[i]);
		}
		else {
			ans *= number_of_arrangement(tmp);
			prev = ridx[i];
			tmp = { c_[i] };
		}
		dump(i, tmp, ans);
	}
	if (tmp.size()) {
		ans *= number_of_arrangement(tmp);
	}
	cout << ans << endl;
	return 0;
}