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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
//	auto f = [&](int N, vector<int> A) {
//		vector<int> d(N);
//		rep(i, 0, N) {
//			d[i] = A[(i + 1) % N] - A[i];
//		}
//		dump(d);
//		int asum = N*(N + 1) / 2;
//		int sum = accumulate(all(A), 0LL);
//		if (sum%asum) {
//			return false;
//		}
//		int cnt = sum / asum;
//		rep(i, 0, N) {
//			d[i] -= cnt;
//		}
//		dump(d, A);
//		rep(i, 0, N) {
//			d[i] = -d[i];
//			if (d[i] % N != 0) {
//				return false;
//			}
//		}
//		return true;
//	};
//	auto g = [&](int N, vector<int> A) {
//		int sumA = accumulate(all(A), 0LL);
//		int M = N*(N + 1) / 2;
//		int cnt = sumA / M;
//		dump(cnt);
//		vector<int> d(N);
//		rep(i, 0, N) {
//			d[i] = A[(i + 1) % N] - A[i];
//		}
//		dump(d);
//		if (accumulate(all(d), 0) != 0 || sumA % M != 0) {
//			return false;
//		}
//		int c = 0;
//		rep(i, 0, 100) {
//			auto mini = min_element(all(d)),
//				maxi = max_element(all(d));
//			int diff = *maxi - *mini;
//			int s = diff / N;
//			if (s == 0)break;
//			*mini += N * s;
//			c += s;
//			rep(i, 0, N) {
//				d[i] -= s;
//			}
//			dump(d, c);
//			if (c > cnt) {
//				return false;
//			}
//		}
//		if ((cnt - c) % N != 0) {
//			return false;
//		}
//		if (count(all(d), 0) == N) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	};
//	random_device rd;
//	if (1) {
//		cout << (f(N, A) ? "YES" : "NO") << endl;
//	}
//	else {
//		cout << (g(N, A) ? "YES" : "NO") << endl;
//	}
//	return 0;
//}
//
