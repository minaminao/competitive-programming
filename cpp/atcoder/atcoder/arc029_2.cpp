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

//#define double long double
const double EPS = 1e-8;
const double PI = acos(-1);
#define equals(a,b) (fabs((a)-(b)) < EPS)

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A, B; cin >> A >> B;
	if (A > B)swap(A, B);
	int N; cin >> N;
	int C, D;
	auto f = [&](double x) {
		return A*sin(x) + B*cos(x) <= D;
	};
	auto binary_search = [&](double l, double r) {
		if (f(l))return l; //exception f(l):true
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2;
			if (f(m))
				r = m;
			else
				l = m;
		}
		return r; //f(l):false, f(r):true
	};
	rep(i, 0, N) {
		cin >> C >> D;
		if (C > D)swap(C, D);
		double res = binary_search(0, PI / 2);
		dump(res);
		dump(A*cos(res) + B*sin(res));
		if (C + EPS > A*cos(res) + B*sin(res)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}