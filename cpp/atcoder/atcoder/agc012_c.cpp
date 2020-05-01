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
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//using Num = int;
//vector<vector<Num>> nCr;
//void compute_nCr(int n) {
//	vector<Num> a(1, 1), b(2, 1);
//	nCr = { a,b };
//	for (int i = 3; i <= n + 1; i++) {
//		swap(a, b);
//		b.resize(i);
//		b[0] = 1; b[i - 1] = 1;
//		for (int j = 1; j < i - 1; j++)
//			b[j] = a[j - 1] + a[j];
//		nCr.emplace_back(b);
//	}
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	const int M = 50;
//	compute_nCr(M + 1);
//	using P = tuple<int, int, int, int>;
//	vector<int> v(M);
//	rep(i, 1, M) {
//		for (int j = 2; j <= i + 1; j += 2) {
//			v[i] += nCr[i + 1][j];
//		}
//	}
//	vector<P> w;
//	rep(i, 0, M) {
//		rep(j, 0, 200 - i) {
//			rep(k, 0, 200 - i - j) {
//				if (INF / (j + 1) / (k + 1) < v[i])continue;
//				w.emplace_back((j + 1)*(k + 1)*v[i], j, k, i);
//			}
//		}
//	}
//	dump(v);
//	//dump(w);
//	sort(all(w));
//	int N; cin >> N;
//	vector<int> ans;
//	int b = 1;
//	while (N >= 3) {
//		P p(N, 0, 0, 0);
//		auto e = upper_bound(all(w), p) - 1;
//		int val, l, r, m;
//		tie(val, l, r, m) = *e;
//		dump(val, m);
//		rep(i, 0, l) {
//			ans.emplace_back(b);
//		}
//		rep(i, 0, m) {
//			ans.emplace_back(b);
//			ans.emplace_back(b + 1);
//		}
//		rep(i, 0, r) {
//			ans.emplace_back(b + 1);
//		}
//		N -= val;
//	}
//	dump(ans.size());
//	//dump(ans);
//
//	//vector<int> cnt(1);
//	//vector<int> ins(1);
//	//int b = 0;
//	//while (N) {
//	//	auto e = upper_bound(all(v), N) - 1;
//	//	int a = e - v.begin() + 1;
//	//	dump(*e, a);
//	//	rep(i, 0, a) {
//	//		cnt[b]++;
//	//	}
//	//	N -= *e;
//	//	if (b&&N) {
//	//		int A = cnt[b - 1], B = cnt[b];
//	//		dump(N, A, B);
//	//		rrep(c, 0, B) {
//	//			int sub = (A - c)*(B - c)*v[c + 1];
//	//			dump(sub);
//	//			if (N >= sub) {
//	//				N -= sub;
//	//				ins[b] = c;
//	//				break;
//	//			}
//	//		}
//	//	}
//	//	b++;
//	//	cnt.emplace_back();
//	//	ins.emplace_back();
//	//}
//	//dump(cnt);
//	//dump(ins);
//	//dump(accumulate(all(cnt), 0LL));
//
//	/*cout << ans.size() << endl;
//	cout << ans[0]; rep(i, 1, ans.size()) { cout << " " << ans[i]; } cout << endl;*/
//	return 0;
//}