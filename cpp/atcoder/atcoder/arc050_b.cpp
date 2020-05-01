#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Int = mp::cpp_int;
#define int Int
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int R, B; cin >> R >> B;
	int x, y; cin >> x >> y;
	auto f = [&](int k) {
		if (R < k)return false;
		int a = (R - k) / (x - 1);
		int R_ = R, B_ = B;
		R_ -= a*x + (k - a);
		B_ -= a + (k - a)*y;
		dump(k, a, R_, B_);
		return R_ >= 0 && B_ >= 0;
	};
	auto binary_search = [&](int l, int r) {
		if (!f(l))return l; //exception f(l):true
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (!f(m))
				r = m;
			else
				l = m;
		}
		//f(l):false, f(r):true
		return r;
	};
	cout << binary_search(0, min(R, B) + 1) - 1 << endl;
	return 0;
}