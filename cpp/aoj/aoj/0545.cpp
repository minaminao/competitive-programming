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
	for (int N; cin >> N&&N;) {
		int M; cin >> M;
		unordered_set<int> s;
		vector<int> a(M), b(M); rep(i, 0, M) { cin >> a[i] >> b[i]; }
		rep(i, 0, M) {
			if (a[i] == 1)s.insert(b[i]);
			else if (b[i] == 1)s.insert(a[i]);
		}
		vector<int> v;
		rep(i, 0, M) {
			if (s.count(a[i]))v.emplace_back(b[i]);
			else if (s.count(b[i]))v.emplace_back(a[i]);
		}
		rep(i, 0, v.size()) {
			s.insert(v[i]);
		}
		cout << s.size() - s.count(1) << endl;
	}
	return 0;
}