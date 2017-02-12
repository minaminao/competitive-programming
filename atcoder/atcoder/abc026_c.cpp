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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

struct p {
	int mini = INF, maxi = -INF;
	void update(p p) {
		chmin(mini, p.getc());
		chmax(maxi, p.getc());
	}
	int getc() {
		if (mini == INF)return 1;
		return maxi + mini + 1;
	}
};

signed main() {
	int N; cin >> N;
	vector<int> B(N); rep(i, 1, N) { cin >> B[i]; B[i]--; }
	vector<p> v(N);
	rrep(i, 1, N)
		v[B[i]].update(v[i]);
	cout << v[0].getc() << endl;
	return 0;
}