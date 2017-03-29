//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int H, W; cin >> H >> W;
//	int N; cin >> N;
//	vector<vector<int>> r(H, vector<int>(W)), c(H, vector<int>(W));
//	rep(i, 0, H)rep(j, 0, W) {
//		cin >> r[i][j] >> c[i][j];
//	}
//	vector<int> R(N), C(N); rep(i, 0, N) { cin >> R[i] >> C[i]; }
//	using P = pair<vector<vector<int>>, vector<vector<int>>>;
//	auto mul = [&](vector<vector<int>> r1, vector<vector<int>> c1, vector<vector<int>> r2, vector<vector<int>> c2) {
//		rep(i, 0, H)rep(j, 0, W) {
//			int nr = r1[i][j], nc = c1[i][j];
//			r1[i][j] = r2[nr][nc];
//			c1[i][j] = c2[nr][nc];
//		}
//		return P(r1, c1);
//	};
//	const int D = 30;
//	vector<P> p(D);
//	p[0] = P(r, c);
//	rep(i, 0, D - 1) {
//		p[i + 1] = mul(p[i].first, p[i].second, p[i].first, p[i].second);
//	}
//	auto collision = [&](int x) {
//		using T = pair<int, int>;
//		set<T> st;
//		bool flag = false;
//		rep(i, 0, N) {
//			T a = T(p[x].first[R[i]][C[i]], p[x].second[R[i]][C[i]]);
//			if (st.count(a)) {
//				flag = true;
//			}
//			st.emplace(a);
//		}
//		return flag;
//	};
//	if (!collision(D - 1)) {
//		cout << -1 << endl;
//		return 0;
//	}
//	if (collision(0)) {
//		cout << 1 << endl;
//		return 0;
//	}
//	auto binary_search = [&](int l, int r) {
//		if (collision(l))return l; //exception f(l):true
//		while (l + 1 < r) {
//			int m = (l + r) / 2;
//			if (collision(m))
//				r = m;
//			else
//				l = m;
//		}
//		//f(l):false, f(r):true
//		return r;
//	};
//	auto collision2 = [&](P x) {
//		using T = pair<int, int>;
//		set<T> st;
//		bool flag = false;
//		rep(i, 0, N) {
//			T a = T(x.first[R[i]][C[i]], x.second[R[i]][C[i]]);
//			if (st.count(a)) {
//				flag = true;
//			}
//			st.emplace(a);
//		}
//		return flag;
//	};
//	int b = binary_search(0, D - 1);
//	int a = b - 1;
//	P x = p[a];
//	int ans = 1 << a;
//	rrep(i, 0, a) {
//		P y = mul(x.first, x.second, p[i].first, p[i].second);
//		if (!collision2(y)) {
//			x = y;
//			ans += 1 << i;
//		}
//	}
//	cout << ans + 2 << endl;
//	dump(a, b);
//	return 0;
//}