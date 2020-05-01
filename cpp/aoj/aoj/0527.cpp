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
		vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
		stack<int> zero, one;
		zero.push(-1);
		one.push(-1);
		rep(i, 0, N) {
			if (i & 1) {
				if (v[i]) {
					while (zero.top() > one.top())zero.pop();
					one.push(i);
				}
				else {
					while (zero.top() < one.top())one.pop();
					zero.push(i);
				}
			}
			else {
				if (v[i])one.push(i);
				else zero.push(i);
			}
		}
		vector<pair<int, int>> tmp;
		while (zero.size() > 1) {
			tmp.emplace_back(zero.top(), 0);
			zero.pop();
		}
		while (one.size() > 1) {
			tmp.emplace_back(one.top(), 1);
			one.pop();
		}
		sort(all(tmp));
		dump(tmp);
		int ans = 0;
		if (tmp.front().second == 0)ans += tmp.front().first + 1;
		rep(i, 1, tmp.size()) {
			if (tmp[i].second == 0)ans += tmp[i].first - tmp[i - 1].first;
		}
		cout << ans << endl;
	}
	return 0;
}