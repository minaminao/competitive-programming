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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<string> S(N); rep(i, 0, N) { cin >> S[i]; }
//
//	vector<int> pow(10);
//	pow[0] = 1;
//	rep(i, 0, pow.size() - 1)pow[i + 1] = pow[i] * 26;
//
//	unordered_set<long long> st;
//	rep(h, 1, 5) {
//		rep(i, 0, N) {
//			int tmp = 0;
//			if (S[i].size() > h)continue;
//			rep(j, 0, h) {
//				tmp += (S[i][j] - 'a')*pow[j];
//			}
//			st.emplace(tmp);
//			rep(j, h, S[i].size()) {
//				tmp -= S[i][j - h] - 'a';
//				tmp *= 26;
//				tmp += (S[i][j] - 'a')*pow[h];
//				st.emplace(tmp);
//			}
//		}
//		dump(st);
//	}
//	
//	rep(i, 0, pow[6]) {
//		if (!st.count(i)) {
//			dump(i);
//			while (i) {
//				cout << (char)(i%26 + 'a') << endl;
//				i /= 26;
//			}
//			return 0;
//		}
//	}
//	return 0;
//}