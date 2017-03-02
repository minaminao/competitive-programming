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

int N, W;
int v[210] = {}, w[210] = {};
#define MAX 200010
int dp[MAX + 200010] = {};

void solve1() {
	vector<pair<int, int>> a, b;
	a.emplace_back(0, 0);
	b.emplace_back(0, 0);
	rep(i, 0, N / 2) {
		int n = a.size();
		rep(j, 0, n) {
			a.emplace_back(a[j].first - w[i], a[j].second - v[i]);
		}
	}
	rep(i, N / 2, N) {
		int n = b.size();
		rep(j, 0, n) {
			b.emplace_back(b[j].first - w[i], b[j].second - v[i]);
		}
	}
	sort(all(a));
	sort(all(b));

	rrep(i, 1, b.size()) {
		chmin(b[i - 1].second, b[i].second);
	}

	int ans = 0;
	for (auto &e : a) {
		pair<int, int> p(-W - e.first, -INF);
		auto res = lower_bound(all(b), p);
		if (res == b.end())continue;
		if (-e.first - (*res).first > W)continue;
		//dump(e, *res, p);
		chmax(ans, -e.second - (*res).second);
	}
	cout << ans << endl;
}

void solve2() {
	rep(i, 0, N) {
		rrep(j, 0, W + 1) {
			if (w[i] + j > W)continue;
			chmax(dp[w[i] + j], dp[j] + v[i]);
		}
	}
	int ans = 0;
	rep(i, 0, W + 1) {
		chmax(ans, dp[i]);
	}
	cout << ans << endl;
}

void solve3() {
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	rep(i, 0, N) {
		rrep(j, 0, MAX) {
			if (dp[j] == INF)continue;
			chmin(dp[v[i] + j], dp[j] + w[i]);
		}
	}
	int ans = 0;
	rep(i, 0, MAX + 1) {
		if (dp[i] > W)continue;
		chmax(ans, i);
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> W;
	rep(i, 0, N) { cin >> v[i] >> w[i]; }
	if (*min_element(v, v + N) <= 1000)solve3();
	else if (*min_element(w, w + N) <= 1000)solve2();
	else solve1();
	return 0;
}