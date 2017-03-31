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

int c(int a, int b) {
	int counter = 0;
	function<int(int, int)> gcd = [&](int a, int b) {
		if (b == 0) return a;
		counter++;
		return gcd(b, a%b);
	};
	gcd(a, b);
	return counter;
}

vector<int> fibonacci(int n) {
	vector<int> v(n);
	v[0] = v[1] = 1;
	rep(i, 0, n - 2)
		v[i + 2] += v[i + 1] + v[i];
	return v;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<int> fib = fibonacci(44);
	dump(fib);
	int K; cin >> K;
	cout << fib[K - 1] << " " << fib[K] << endl;
	return 0;
}