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
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, K; cin >> N >> K;
//	string s; cin >> s;
//	vector<bool> f(N);
//	rep(i, 0, N) {
//		if (K == 0)break;
//		char m = s[i];
//		int k = -1;
//		rep(j, i + 1, N) {
//			if (K == 0 && !(f[i] && f[j]))continue;
//			if (K == 1 && !(f[i] || f[j]))continue;
//			if (chmin(m, s[j])) {
//				k = j;
//			}
//		}
//		if (k == -1)continue;
//		K -= (int)!f[i] + !f[k];
//		f[i] = f[k] = true;
//		swap(s[i], s[k]);
//		dump(s, K);
//	}
//	cout << s << endl;
//	return 0;
//}