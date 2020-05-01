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

//ヒストグラムの最大長方形 O(N)
int largest_rectangle_in_a_histogram(const vector<int> &h) {
	int n = h.size();
	using P = pair<int, int>;
	stack<P> st;
	st.emplace(-1, -1);
	int area = 0;
	for (int i = 0; i < n; i++) {
		if (st.top().first == h[i])
			continue;
		int pos = i;
		while (st.top().first >= h[i]) {
			chmax(area, st.top().first*(i - st.top().second));
			pos = st.top().second;
			st.pop();
		}
		st.emplace(h[i], pos);
	}
	while (st.size()) {
		chmax(area, st.top().first*(n - st.top().second));
		st.pop();
	}
	return area;
}

//0-1二次元配列上の最大長方形 O(H*W)
//ヒストグラムの最大長方形を求めるのと同様
int largest_rectangle(vector<vector<int>> v) {
	int H = v.size(), W = v.front().size();
	rep(i, 0, H - 1)rep(j, 0, W) {
		if (v[i + 1][j] == 0)continue;
		v[i + 1][j] += v[i][j];
	}
	int area = 0;
	rep(i, 0, H)
		chmax(area, largest_rectangle_in_a_histogram(v[i]));
	return area;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int H, W; cin >> H >> W&&H;) {
		vector<vector<int>> v(H, vector<int>(W));
		rep(i, 0, H) rep(j, 0, W) {
			char c; cin >> c;
			v[i][j] = c == '.';
		}
		cout << largest_rectangle(v) << endl;
	}
	return 0;
}