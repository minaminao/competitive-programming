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
//const int MOD = (int)(1e9 + 7);
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
////v[i] <= x <= v[j] ‚É‚·‚é (i<=j) O(N) [l,r]
////STL ‚É‚ ‚éBpartition(v.begin(), v.end(), [x](int i) {return i <= x; }); ‚Ì‚æ‚¤‚ÉŽg‚¤B
//template<typename T>
//int partition(vector<T> &v, int l, int r, T x) {
//	int i = l - 1;
//	for (int j = l; j < r; j++) {
//		if (v[j] <= x) {
//			i++;
//			swap(v[i], v[j]);
//		}
//	}
//	swap(v[i + 1], v[r]);
//	return i + 1;
//}
//
////•½‹ÏO(NlogN) Åˆ«O(N^2) [l,r]
//template<typename T>
//void quick_sort(vector<T> &v, int l, int r) {
//	if (l < r) {
//		int k = partition(v, l, r, v[r]);
//		quick_sort(v, l, k - 1);
//		quick_sort(v, k + 1, r);
//	}
//}
//
//signed main() {
//	int n; cin >> n;
//	vector<char> a(n);
//	vector<int> b(n);
//	rep(i, 0, n)cin >> a[i] >> b[i];
//	vector<pair<int, int>> v;
//	rep(i, 0, n) {
//		v.emplace_back(b[i], i);
//	}
//	quick_sort(v, 0, n - 1);
//	cout << "Stable" << endl;
//	rep(i, 0, n) {
//		cout << a[v[i].second] << " " << v[i].first << endl;
//	}
//	return 0;
//}