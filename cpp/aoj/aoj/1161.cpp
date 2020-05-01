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
	for (int n; cin >> n&&n;) {
		vector<string> v(n);
		vector<char> c;
		rep(i, 0, n) {
			cin >> v[i];
			reverse(all(v[i]));
		}

		bool exist[128];
		memset(exist, 0, sizeof(exist));
		rep(j, 0, 20) {
			rep(i, 0, n) {
				if (v[i].size() <= j)continue;
				if (v[i][j] >= '0'&&v[i][j] <= '9')continue;
				if (exist[v[i][j]])continue;
				exist[v[i][j]] = true;
				c.push_back(v[i][j]);
			}
		}

		int mp[128];
		memset(mp, -1, sizeof(mp));
		rep(i, 0, 10)
			mp[i + '0'] = i;

		bool head[128];
		memset(head, 0, sizeof(head));
		rep(i, 0, n) {
			if (v[i].size() > 1) {
				head[v[i].back()] = true;
			}
		}

		char used[10];
		memset(used, 0, sizeof(used));
		function<int(int, int)> dfs = [&](int idx, int num) {
			int add = 0;
			rep(i, 0, 10) {
				int digit = add;
				add = 0;
				bool flag = false;
				rep(j, 0, n - 1) {
					if (v[j].size() <= i)continue;
					if (mp[v[j][i]] == -1) {
						flag = true;
						break;
					}
					digit += mp[v[j][i]];
				}
				if (flag)
					break;
				add += digit / 10;
				digit %= 10;
				if (v[n - 1].size() > i) {
					if (mp[v[n - 1][i]] == -1)
						break;
					if (digit != mp[v[n - 1][i]])
						return 0;
				}
				else {
					if (digit > 0 || add > 0)
						return 0;
					else
						break;
				}
			}
			if (c.size() > idx + 1) {
				int ret = 0;
				rep(i, 0, 10) {
					if (used[i])continue;
					if (i == 0 && head[c[idx + 1]])continue;
					used[i] = c[idx + 1];
					mp[c[idx + 1]] = i;
					ret += dfs(idx + 1, i);
					mp[c[idx + 1]] = -1;
					used[i] = 0;
				}
				return ret;
			}
			else {
				return 1;
			}
		};
		int ans = 0;
		rep(i, 0, 10) {
			if (used[i])continue;
			if (i == 0 && head[c[0]])continue;
			used[i] = c[0];
			mp[c[0]] = i;
			ans += dfs(0, i);
			mp[c[0]] = -1;
			used[i] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}