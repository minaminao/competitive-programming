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
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())
//
//
//template<class F>
//int binary_search_(int l, int r, F f) {
//	if (f(l))return l; //exception f(l):true
//	while (l + 1 < r) {
//		int m = (l + r) / 2;
//		if (f(m))
//			r = m;
//		else
//			l = m;
//	}
//	//f(l):false, f(r):true
//	return r;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> x(N), y(N); rep(i, 0, N) { cin >> x[i] >> y[i]; }
//	map<int, vector<int>> mp;
//	vector<int> k;
//	rep(i, 0, N) {
//		mp[x[i]].push_back(i);
//		mp[y[i]].push_back(i);
//		k.push_back(x[i]);
//		k.push_back(y[i]);
//	}
//	sort(all(k));
//	UNIQUE(k);
//	dump(k);
//	dump(mp);
//	int l = 0, r = k.size();
//
//	return 0;
//}