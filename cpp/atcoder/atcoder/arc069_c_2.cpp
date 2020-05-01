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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
//	vector<int> B = A;
//	vector<int> maxi(N);
//	for (int i = 0; i < N; i++) {
//		maxi[i] = 0;
//		if (i > 0) maxi[i] = max(maxi[i - 1], A[i - 1]);
//	}
//	sort(all(B));
//	dump(A, B, maxi);
//	int b = 0;
//	for (int i = 0; i < N; i++) {
//		if (maxi[i] >= A[i]) cout << "0" << endl;
//		else {
//			int sum = 0;
//			while (b < N&&B[b] <= A[i]) {
//				sum += B[b] - maxi[i];
//				b++;
//				dump(sum);
//			}
//			dump(b, A[i], maxi[i]);
//			sum += (N - b)*(A[i] - maxi[i]);
//			cout << sum << endl;
//		}
//	}
//	return 0;
//}