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


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> v(N);
	rep(i, 0, N*(N - 1) / 2) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--, b--;
		if (c > d)v[a] += 3;
		else if (c < d)v[b] += 3;
		else if (c == d)v[a]++, v[b]++;
	}
	dump(v);
	vector<int> v2 = v;
	sort(all(v2));
	dump(v2);
	rep(i, 0, N) {
		cout << N - (upper_bound(v2.begin(), v2.end(), v[i]) - v2.begin()) + 1 << endl;
	}
	return 0;
}