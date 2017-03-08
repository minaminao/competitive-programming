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
	int N, M; cin >> N >> M;
	vector<int> a(M), b(M); rep(i, 0, M) { cin >> a[i] >> b[i]; a[i]--, b[i]--; if (a[i] > b[i])swap(a[i], b[i]); }
	vector<bool> v(N);
	rep(i, 0, M) {
		if (a[i] == 0)v[b[i]] = true;
	}
	vector<int> w;
	rep(i, 0, M) {
		if (v[a[i]])w.emplace_back(b[i]);
		if (v[b[i]])w.emplace_back(a[i]);
	}
	rep(i, 0, w.size()) {
		v[w[i]] = true;
	}
	cout << count(v.begin() + 1, v.end(), true) << endl;
	return 0;
}