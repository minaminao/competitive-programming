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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

const double PI = acos(-1);

double a, b, c;
double f(double t) {
	return a*t + b*sin(c*t*PI);
}

bool f2(double t) {
	return f(t) >= 100;
}

template<class F>
double binary_search_(double l, double r, F f) {
	if (f(l))return l; //exception f(l):true
	for (int i = 0; i < 60; i++) { //ƒ‹[ƒv‚Ì‰ñ”‚Í“K“–
		double m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	return r; //f(l):false, f(r):true
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	cout << fixed << setprecision(15);
	double t = binary_search_(0, 200, f2);
	cout << t << endl;
	dump(f(t));
	return 0;
}