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

class AverageVarianceSubtree {
public:
	vector<double> sum, sum2;
	int n;
	vector<int> p, w;
	double average(vector<int> p_, vector<int> w_) {
		p = p_, w = w_;
		n = w.size();
		sum.assign(n, 0);
		sum2.assign(n, 0);
		rep(u, 0, n) {
			sum[u] = w[u];
			sum2[u] = w[u] * w[u];
		}
		calc_sum();
		dump(sum, sum2);
		double ans = 0;
		rep(u, 0, n) {
			ans += sum2[u] / n - (sum[u] / n)*(sum[u] / n);
		}
		ans /= n;
		return ans;
	}
	void calc_sum() {
		rrep(i, 0, n - 1) {
			int u = i + 1;
			sum[p[i]] += sum[u];
			sum2[p[i]] += sum2[u];
		}
	}
};

class LR {
public:
	string construct(vector<int> s, vector<int> t) {
		int n = s.size();
		rep(h, 0, 101) {
			rep(l, 0, h + 1) {
				int r = h - l;
				vector<int> A = s;
				vector<int> tmp;
				rep(i, 0, l) {
					tmp = A;
					rep(j, 0, n) {
						tmp[(j + 1) % n] += A[j];
					}
					A = tmp;
				}
				rep(i, 0, r) {
					tmp = A;
					rep(j, 0, n) {
						tmp[j] += A[(j + 1) % n];
					}
					A = tmp;
				}
				if (A == t) {
					return string(l, 'L') + string(r, 'R');
				}
			}
		}
		return "No solution";
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	LR lr;
	//int n = rand() % 50 + 1;
	//vector<int> s(n);
	//rep(i, 0, n) {
	//	s[i] = rand();
	//}
	//int L = rand() % 10, R = rand() % 10;
	//vector<int> tmp, A;
	//A = s;
	//rep(i, 0, L / 2) {
	//	tmp = A;
	//	rep(j, 0, n) {
	//		tmp[(j + 1) % n] += A[j];
	//	}
	//	A = tmp;
	//}
	//rep(i, 0, R / 2) {
	//	tmp = A;
	//	rep(j, 0, n) {
	//		tmp[j] += A[(j + 1) % n];
	//	}
	//	A = tmp;
	//}
	//rep(i, L / 2, L) {
	//	tmp = A;
	//	rep(j, 0, n) {
	//		tmp[(j + 1) % n] += A[j];
	//	}
	//	A = tmp;
	//}
	//rep(i, R / 2, R) {
	//	tmp = A;
	//	rep(j, 0, n) {
	//		tmp[j] += A[(j + 1) % n];
	//	}
	//	A = tmp;
	//}
	//vector<int> t = A;
	vector<int> s = { 1LL << 32,1LL << 32 }, t = { 0,0 };
	dump(s, t);
	dump(lr.construct(s, t));
	//AverageVarianceSubtree C;
	//vector<int> p = { 0,1 }, w = { 10,20,30 };
	//dump(C.average(p, w));
	return 0;
}