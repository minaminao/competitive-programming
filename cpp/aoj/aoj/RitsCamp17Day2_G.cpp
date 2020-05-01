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
//int N;
//vector<int> p;
//using P = pair<int, int>;
//
//vector<int> solve1() {
//	vector<int> cnt(N);
//	vector<P> v(N);
//	rep(i, 0, N) {
//		v[i] = P(cnt[p[i] - 1] * N - p[i], i);
//		cnt[p[i] - 1]++;
//	}
//	sort(all(v));
//	dump(v);
//	vector<int> q(N);
//	rep(i, 0, N) {
//		q[i] = v[i].second;
//	}
//
//	set<int> st;
//	rep(i, 0, N) {
//		st.insert(i + 1);
//	}
//
//	vector<int> ans(N);
//	rep(i, 0, N) {
//		int idx = q[i];
//		auto a = st.lower_bound(p[idx]);
//		auto b = st.lower_bound(1);
//		if (a != st.end()) {
//			int A = *a;
//			//dump(*a);
//			st.erase(a);
//			ans[A - 1] = idx + 1;
//		}
//		else if (b != st.end()) {
//			int B = *b;
//			//dump(*b);
//			st.erase(b);
//			ans[B - 1] = idx + 1;
//		}
//	}
//	return ans;
//}
//
//vector<int> solve3() {
//	vector<int> q = p;
//	vector<int> cnt(N);
//	rep(i, 0, N) {
//		q[i] += cnt[p[i] - 1];
//		q[i] = (q[i] - 1) % N + 1;
//		cnt[p[i] - 1]++;
//	}
//	dump(q);
//
//	set<int> st;
//	rep(i, 0, N) {
//		st.insert(i + 1);
//	}
//
//	vector<int> ans(N);
//	using T = tuple<int, int, int>;
//	priority_queue<T> pq; //コスト 値 インデックス
//	int fin = 0;
//	while (fin < N) {
//		int mi, na, mina;
//		tie(mi, na, mina) = pq.top(); pq.pop();
//		rep(i, 0, N) {
//			auto a = st.lower_bound(q[i]);
//			auto b = st.lower_bound(1);
//			if (a != st.end()) {
//				int A = *a;
//				//dump(*a);
//				st.erase(a);
//				ans[A - 1] = i + 1;
//			}
//			else if (b != st.end()) {
//				int B = *b;
//				//dump(*b);
//				st.erase(b);
//				ans[B - 1] = i + 1;
//			}
//		}
//	}
//	return ans;
//}
//
//vector<int> solve2() {
//	vector<int> a = p;
//	vector<int> ans(N);
//	rep(i, 0, N)a[i]--;
//	vector<bool> f(N);
//	vector<bool> f2(N);
//	for (int cnt = 0; cnt < N;) {
//		rep(i, 0, N) {
//			if (f2[i])continue;
//			if (f[a[i]]) {
//				a[i]++;
//				a[i] %= N;
//			}
//			else {
//				f[a[i]] = true;
//				cnt++;
//				ans[a[i]] = i + 1;
//				f2[i] = true;
//			}
//		}
//	}
//	return ans;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> N;
//	p.resize(N); rep(i, 0, N) { cin >> p[i]; }
//	for (int i = 0; i < 1000; i++) {
//		rep(i, 0, N) {
//			p[i] = rand() % N + 1;
//		}
//		vector<int> res1 = solve3(), res2 = solve2();
//		if (res1 == res2)continue;
//		dump(p, res1, res2);
//	}
//	return 0;
//}