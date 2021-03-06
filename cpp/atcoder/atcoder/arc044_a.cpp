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

bool is_prime(int x) {
	if (x <= 1)return false;
	else if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return false;
	return true;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	if (N == 1) {
		cout << "Not Prime" << endl;
	}
	else if (is_prime(N)) {
		cout << "Prime" << endl;
	}
	else {
		int a = N % 10, b = 0;
		while (N) {
			b += N % 10;
			N /= 10;
		}
		if (a % 2 && a != 5 && b % 3) {
			cout << "Prime" << endl;
		}
		else {
			cout << "Not Prime" << endl;
		}
	}
	return 0;
}