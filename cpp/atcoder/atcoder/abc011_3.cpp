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
	vector<int> v(3); rep(i, 0, 3) { cin >> v[i]; }
	sort(all(v));
	if (count(all(v), N)) {
		cout << "NO" << endl;
		return 0;
	}
	int cnt = 0;
	while (N > 0) {
		if (cnt == 100) {
			cout << "NO" << endl;
			return 0;
		}
		cnt++;
		if (!count(all(v), N - 3)) {
			N -= 3;
		}
		else if (!count(all(v), N - 2)) {
			N -= 2;
		}
		else if (!count(all(v), N - 1)) {
			N -= 1;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}