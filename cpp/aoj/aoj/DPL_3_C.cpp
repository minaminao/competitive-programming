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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

//ヒストグラムの最大長方形 O(N)
void largest_rectangle_in_a_histogram() {
	int N; cin >> N;
	vector<int> h(N); rep(i, 0, N) { cin >> h[i]; }
	using P = pair<int, int>;
	stack<P> st;
	st.emplace(-1, -1);
	int ans = 0;
	rep(i, 0, N) {
		if (st.top().first == h[i])
			continue;
		int pos = i;
		while (st.top().first >= h[i]) {
			chmax(ans, st.top().first*(i - st.top().second));
			pos = st.top().second;
			st.pop();
		}
		st.emplace(h[i], pos);
	}
	while (st.size()) {
		chmax(ans, st.top().first*(N - st.top().second));
		st.pop();
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	largest_rectangle_in_a_histogram();
	return 0;
}