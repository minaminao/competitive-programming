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
//int main() {
//	int N, K; cin >> N >> K;
//	string s; cin >> s;
//	string S(N, '?'), T(N, '?');
//	vector<int> Tcnt(26);
//	rep(i, 0, N) Tcnt[S[i] - 'a']++;
//	rep(i, 0, N) {
//		rep(a, 'a', 'z' + 1)
//			if (Tcnt[a - 'a'] > 0) {
//				T[i] = a;
//				Tcnt[a - 'a'] --;
//				int x = 0;
//				rep(j, 0, i + 1) x += S[j] != T[j];
//				vector<int> Scnt(26);
//				rep(j, i + 1, N)
//					Scnt[S[j] - 'a']++;
//				int y = 0;
//				rep(j, 0, 26) y += max(Scnt[j], Tcnt[j]) - min(Scnt[j], Tcnt[j]);
//				x += y / 2;
//				if (x <= K)
//					break;
//				Tcnt[a - 'a']++;
//				T[i] = '?';
//			}
//	}
//	cout << T << endl;
//	return 0;
//}