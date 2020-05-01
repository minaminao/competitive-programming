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
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<int> H(N), S(N); rep(i, 0, N) { cin >> H[i] >> S[i]; }

	auto f = [&](int x) {
		vector<int> a(N);
		rep(i, 0, N) {
			if (x < H[i])
				return false;
			int idx = (x - H[i]) / S[i];
			dump(idx);
			dump(x, H[i], S[i]);
			chmin(idx, N - 1);
			a[idx]++;
		}
		dump(a);
		rep(i, 0, N - 1)
			a[i + 1] += a[i];
		dump(a);
		rep(i, 0, N) {
			if (a[i] <= i + 1)continue;
			return false;
		}
		return true;
	};
	auto binary_search = [&](int l, int r) {
		if (f(l))return l; //exception f(l):true
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (f(m))
				r = m;
			else
				l = m;
		}
		//f(l):false, f(r):true
		return r;
	};

	cout << binary_search(0, INF) << endl;

	return 0;
}