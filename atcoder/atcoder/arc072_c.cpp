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
//	int N, D; cin >> N >> D;
//	vector<int> d(N); rep(i, 0, N) {
//		cin >> d[i];
//	}
//	int Q; cin >> Q;
//	vector<int> q(Q); rep(i, 0, Q) {
//		cin >> q[i]; q[i]--;
//	}
//	vector<int> a(N + 1);
//	int b = D;
//	a[0] = b;
//	rep(i, 0, N) {
//		if (d[i] < b * 2) {
//			b = abs(b - d[i]);
//		}
//		a[i + 1] = b;
//	}
//	dump(a);
//
//	vector<int> maxi(N + 1);
//	bool flag = true;
//	rrep(i, 0, N) {
//		if (flag) {
//			if (d[i] == 1) {
//				flag = false;
//				maxi[i] = 1;
//			}
//		}
//		else {
//			if (maxi[i + 1] + 1 < d[i]) {
//				maxi[i] = maxi[i + 1];
//			}
//			else {
//				maxi[i] = maxi[i + 1] + d[i];
//			}
//		}
//	}
//	dump(maxi);
//
//	rep(i, 0, Q) {
//		if (a[q[i]] == 0) {
//			cout << "NO" << endl;
//		}
//		else if (q[i] == N - 1) {
//			cout << "YES" << endl;
//		}
//		else {
//			if (a[q[i]] <= maxi[q[i] + 1]) {
//				cout << "NO" << endl;
//			}
//			else {
//				cout << "YES" << endl;
//			}
//		}
//	}
//	return 0;
//}