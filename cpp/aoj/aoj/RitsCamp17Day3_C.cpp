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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	cout << "? 1 2" << endl;
	int d; cin >> d;
	using P = pair<int, int>;
	vector<P> v;
	v.emplace_back(0, 1);
	v.emplace_back(d, 2);
	rep(i, 3, N + 1) {
		int d1, d2;
		cout << "? 1 " << i << endl;
		cin >> d1;
		cout << "? 2 " << i << endl;
		cin >> d2;
		// 1 i 2
		if (d1 + d2 == d) {
			v.emplace_back(d1, i);
		}
		// i 1 2
		else if (d1 + d == d2) {
			v.emplace_back(-d1, i);
		}
		// 1 2 i
		else if (d2 + d == d1) {
			v.emplace_back(d1, i);
		}
	}
	sort(all(v));
	cout << "!";
	rep(i, 0, N) {
		cout << " " << v[i].second;
	}
	cout << endl;
	return 0;
}