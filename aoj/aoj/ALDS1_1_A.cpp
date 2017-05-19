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
//template<typename T>
//void insertionSort(vector<T> v) {
//	int n = v.size();
//	for (int i = 1; i < n; i++) {
//		int x = v[i];
//		int j = i - 1;
//		for (; j >= 0 && v[j] > x; j--)
//			v[j + 1] = v[j];
//		v[j + 1] = x;
//		cout << v[0]; rep(i, 1, v.size()) { cout << " " << v[i]; } cout << endl;
//	}
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> A(N); rep(i, 0, N) {
//		cin >> A[i];
//	}
//	cout << A[0]; rep(i, 1, A.size()) { cout << " " << A[i]; } cout << endl;
//	insertionSort(A);
//	return 0;
//}