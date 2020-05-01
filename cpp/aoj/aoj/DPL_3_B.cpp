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

//最大長方形 O(H*W)
//ヒストグラムの最大長方形を求めるのと同様
void largest_rectangle() {
	int H, W; cin >> H >> W;
	vector<vector<int>> v(H, vector<int>(W));
	rep(i, 0, H) rep(j, 0, W) {
		int x; cin >> x;
		v[i][j] = !x;
	}
	rep(i, 0, H - 1)rep(j, 0, W) {
		if (v[i + 1][j] == 0)continue;
		v[i + 1][j] += v[i][j];
	}
	using P = pair<int, int>;
	int ans = 0;
	rep(i, 0, H) {
		stack<P> st;
		st.emplace(-1, -1);
		rep(j, 0, W) {
			if (st.top().first == v[i][j])
				continue;
			int pos = j;
			while (st.top().first >= v[i][j]) {
				chmax(ans, st.top().first*(j - st.top().second));
				pos = st.top().second;
				st.pop();
			}
			st.emplace(v[i][j], pos);
		}
		while (st.size()) {
			chmax(ans, st.top().first*(W - st.top().second));
			st.pop();
		}
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	largest_rectangle();
	return 0;
}