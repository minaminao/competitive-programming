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
	int n; cin >> n;
	string x; cin >> x;
	int q; cin >> q;
	using P = pair<int, int>;
	enum { LEFT, RIGHT };
	//連続区間の端点の集合
	set<P> st; //位置, 左端 右端
	/*

	a < l <= b <= r < c

	x: 1
	b はすべて削除
	a が右端なら左端 (l, LEFT) を挿入
	c が左端なら右端 (r, RIGHT) を挿入

	x: 0
	b はすべて削除
	a が左端なら右端 (l, RIGHT) を挿入
	c が右端なら左端 (r, LEFT) を挿入

	*/
	if (x.front() == '1')st.emplace(0, LEFT);
	rep(i, 1, n) {
		if (x[i - 1] == x[i])continue;
		st.emplace(i, x[i] == '0');
	}
	if (x.back() == '1')st.emplace(n, RIGHT);
	dump(st);
	rep(i, 0, q) {
		int l, r, b; cin >> l >> r >> b; l--;
		P pl(l, LEFT), pr(r, RIGHT);
		while (true) {
			auto p = st.lower_bound(pl);
			if (p == st.end())
				break;
			if (*p <= pr)
				st.erase(p);
			else
				break;
		}
		if (b == 1) {
			auto a = st.lower_bound(pl);
			if (a != st.begin()) {
				a--;
				if ((*a).second == RIGHT)
					st.emplace(l, LEFT);
			}
			else {
				st.emplace(l, LEFT);
			}
			auto b = st.upper_bound(pr);
			if (b != st.end()) {
				if ((*b).second == LEFT)
					st.emplace(r, RIGHT);
			}
			else {
				st.emplace(r, RIGHT);
			}
		}
		else {
			auto a = st.lower_bound(pl);
			if (a != st.begin()) {
				a--;
				if ((*a).second == LEFT)
					st.emplace(l, RIGHT);
			}
			auto b = st.upper_bound(pr);
			if (b != st.end()) {
				if ((*b).second == RIGHT)
					st.emplace(r, LEFT);
			}
		}
		dump(st);
		cout << st.size() / 2 << endl;
	}
	return 0;
}