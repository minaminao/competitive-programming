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

//最小コストソート
//コスト v[i]+v[j] の交換を用いてソートする場合の最小コスト
//オーバーフローに注意 v[i]!=v[j]
template<class T>
T minimum_cost_sort(const vector<T> &v) {
	int n = v.size();
	T total_cost = 0;
	vector<pair<T, int>> sorted(n);
	for (int i = 0; i < n; i++)sorted[i] = make_pair(v[i], i);
	sort(sorted.begin(), sorted.end());
	T mini = sorted[0].first;
	vector<bool> is_sorted(n);
	for (int i = 0; i < n; i++) {
		if (is_sorted[sorted[i].second])continue;
		T loop_cost = 0;
		T loop_sum = 0;
		T loop_mini = sorted[i].first;
		T loop_n = 0;
		for (int j = i;;) {
			T cost = sorted[j].first;
			int dst = sorted[j].second;
			is_sorted[j] = true;
			chmin(loop_mini, cost);
			loop_sum += cost;
			loop_n++;
			j = dst;
			if (is_sorted[dst])break;
		}
		total_cost += min(
			loop_sum + (loop_n - 2)*loop_mini,
			loop_sum + loop_mini + (loop_n + 1)*mini
		);
	}
	return total_cost;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> w(n); rep(i, 0, n) { cin >> w[i]; }
	cout << minimum_cost_sort(w) << endl;
	return 0;
}