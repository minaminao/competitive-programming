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

#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int N; cin >> N;) {
		vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
		map<int, pair<int, int>> mp;
		rep(i, 0, N) {
			//mp[v[i]].emplace_back(i + 1);
			if (mp[v[i]].first == 0)mp[v[i]].second = i + 1;
			mp[v[i]].first++;
		}
		dump(mp);
		vector<int> k = v;
		sort(all(k));
		UNIQUE(k);
		dump(k);
		vector<int> ans(N);
		rrep(i, 1, k.size()) {
			mp[k[i - 1]].first += mp[k[i]].first;
			ans[mp[k[i]].second - 1] += (k[i] - k[i - 1])*mp[k[i]].first;
			chmin(mp[k[i - 1]].second, mp[k[i]].second);
		}
		dump(mp);
		ans[0] += k[0] * mp[k[0]].first;
		rep(i, 0, ans.size()) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}