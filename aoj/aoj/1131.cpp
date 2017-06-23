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

int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
int lcm(int x, int y) { return x*y / gcd(x, y); }

int p, q, a, n;
using T = tuple<int, int, int, int, int>;
int f(int x, int y, int z, int c, int a_) {
	if (c == n - 1 && x != 1)return 0;
	if (c == n)return 0;
	if (x*z > (n - c)*y)return 0;
	int ret = 0;
	rep(i, z, a + 1) {
		if (i*a_ > a)
			break;
		if (x*i > y) {
			int nx = x*i - y, ny = y*i;
			int g = gcd(nx, ny);
			nx /= g;
			ny /= g;
			ret += f(nx, ny, i, c + 1, i*a_);
		}
		else if (x*i == y) {
			ret += 1;
		}
	}
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (; cin >> p >> q >> a >> n&&p;) {
		cout << f(p, q, 1, 0, 1) << endl;
	}
	return 0;
}