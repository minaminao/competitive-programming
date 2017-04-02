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

struct DistanceSum {
	int n;
	vector<int> p;
	vector<int> sum; //[0, i)
	DistanceSum(const vector<int> p_) :n(p_.size()), p(p_), sum(n + 1) {
		sort(p.begin(), p.end());
		for (int i = 0; i < n; i++)
			sum[i + 1] = sum[i] + p[i];
	}
	int get(int x) {
		int r = lower_bound(p.begin(), p.end(), x) - p.begin();
		int d = 0;
		d += r*x - sum[r];
		d += sum[n] - sum[r] - x*(n - r);
		return d;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q; cin >> N >> Q;
	vector<int> x(N); rep(i, 0, N) { cin >> x[i]; }
	vector<int> t(Q); rep(i, 0, Q) { cin >> t[i]; }
	DistanceSum ds(x);
	rep(i, 0, Q) {
		cout << ds.get(t[i]) << endl;
	}
	return 0;
}