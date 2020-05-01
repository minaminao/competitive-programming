//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
////À•Wˆ³k(map)
////–ß‚è’l: zip[ˆ³k‘O‚ÌÀ•W]:ˆ³kŒã‚ÌÀ•W (zip.size()<=10^5‚È‚ç‚‘¬‚É“®ì)
//template<typename T>
//map<T, T> compress(vector<T> &v) {
//	map<T, T> zip;
//	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
//	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
//	return zip;
//}
//
//struct RangeAddQuery {
//	int n;
//	vector<int> d;
//	int time;
//	RangeAddQuery(int m) {
//		for (n = 1; n < m; n *= 2);
//		d.assign(n * 2, 0);
//	}
//	//[l, r)
//	void add(int l, int r, int x) {
//		for (; l && l + (l&-l) <= r; l += l&-l)
//			d[(n + l) / (l&-l)] += x;
//		for (; l < r; r -= r&-r)
//			d[(n + r) / (r&-r) - 1] += x;
//	}
//	int get(int i) {
//		int ret = d[n + i];
//		for (int j = (n + i) / 2; j > 0; j >>= 1)
//			ret += d[j];
//		return ret;
//	}
//};
//
//void generate_case() {
//	int Q = 6, K = 3;
//	cout << Q << " " << K << endl;
//	rep(i, 0, Q) {
//		if (i & 1) {
//			cout << 2 << " " << 100 << endl;
//		}
//		else {
//			cout << 1 << " " << rand() % 10 + 1 << " " << rand() % 10 + 1 << endl;
//		}
//	}
//}
//int Q, K;
//vector<int> v{ 0 };
//set<int> st;
//vector<int> C(Q), D(Q), A(Q);
//void solve2() {
//	st.insert(0);
//	auto zip = compress(v);
//
//	const int MAX = v.size();
//	dump(MAX);
//	RangeAddQuery R(MAX);
//	vector<int> total(MAX);
//
//	rep(i, 0, Q) {
//		if (C[i] == 1) {
//			auto e = st.upper_bound(D[i]); e--;
//			int tmp = min(R.get(zip[*e]), (*e)*K);
//			R.add(zip[D[i]], MAX, tmp - R.get(zip[D[i]]));
//			int d = D[i] * K - R.get(zip[*e]);
//			dump(d);
//			if (d > 0) {
//				R.add(zip[D[i]], MAX, min(D[i] * K, min(d, A[i])));
//			}
//			st.insert(D[i]);
//		}
//		else {
//			auto e = st.upper_bound(D[i]); e--;
//			if (_DEBUG) {
//				rep(i, 0, MAX) {
//					int ans = min(R.get(zip[v[i]]), (v[i])*K);
//					dump(v[i], ans, R.get(zip[v[i]]));
//				}
//			}
//			dump(st);
//			dump(*e);
//			int ans = min(R.get(zip[*e]), (*e)*K);
//			cout << ans << endl;
//		}
//	}
//}
//
////void solve1() {
////	vector<int> a(10);
////	rep(i, 0, 10) {
////		a[i] = i * 2;
////	}
////	vector<int> b(10);
////	rep(i, 0, Q) {
////		if (C[i] == 1) {
////			b[]
////		}
////	}
////}
//
////‹ğ’¼‰ğ‚Æ‚Ì”äŠr
//template<class F>
//void diff(F f1, F f2) {
//	static const int N = 1;
//	//f1, f2 ‚Ìˆø”‚Æ‚µ‚Äl‚¦‚ç‚ê‚é‚à‚Ì‚ğ‘S‚Äiˆê•”j”äŠr
//	for (int mask = 0; mask < (1 << N*N); mask++) {
//		//ˆø”¶¬
//		vector<vector<int>> v(N, vector<int>(N, 0));
//		rep(i, 0, N*N)v[i / N][i % N] = ((mask >> i) & 1) ? 1 : 0;
//
//		auto res1 = f1(v), res2 = f2(v);
//		dump(res1, res2);
//		assert(res1 == res2);
//	}
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//	cin >> Q >> K;
//
//	C.resize(Q); D.resize(Q); A.resize(Q);
//	rep(i, 0, Q) {
//		cin >> C[i];
//		if (C[i] == 1) {
//			cin >> D[i] >> A[i];
//		}
//		else cin >> D[i];
//		v.emplace_back(D[i]);
//	}
//	solve2();
//	return 0;
//}