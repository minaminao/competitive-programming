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
		vector<int> taro(N); rep(i, 0, N) { cin >> taro[i]; }
		vector<int> hana;
		rep(i, 1, 2 * N + 1) {
			if (count(all(taro), i))continue;
			hana.emplace_back(i);
		}
		sort(all(taro));
		sort(all(hana));
		int prev = 1;
		while (taro.size() && hana.size()) {
			dump(taro);
			dump(hana);
			int cur = 0;
			bool flag = true;
			if (prev == 0) {
				auto h = upper_bound(all(hana), cur);
				if (h != hana.end()) {
					cur = *h;
					hana.erase(h);
					flag = true;
					prev = 1;
				}
			}
			while (flag) {
				flag = false;
				auto t = upper_bound(all(taro), cur);
				if (t == taro.end()) {
					prev = 0;
					break;
				}
				else {
					cur = *t;
					taro.erase(t);
					flag = true;
				}
				auto h = upper_bound(all(hana), cur);
				if (h == hana.end()) {
					prev = 1;
					break;
				}
				else {
					cur = *h;
					hana.erase(h);
					flag = true;
				}
			}
		}
		cout << hana.size() << endl;
		cout << taro.size() << endl;
	}
	return 0;
}