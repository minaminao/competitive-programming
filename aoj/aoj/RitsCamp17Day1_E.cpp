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
//#define MAX 2010
//int dp[4][MAX][MAX];
////RLUD
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	string S;
//	int K;
//	cin >> S >> K;
//	string RL, UD;
//
//	fill(dp[0][0], dp[4][0], -INF);
//	rep(h, 0, 4)dp[h][0][0] = 0;
//
//	rep(i, 0, S.size()) {
//		if (S[i] == 'R' || S[i] == 'L')RL += S[i];
//		else UD += S[i];
//	}
//	dump(RL, UD);
//
//	rep(h, 0, 2) {
//		rep(i, 0, RL.size()) {
//			rep(k, 0, K + 1) {
//				if (RL[i] == "RLUD"[h]) {
//					if (k % 2 == 0) {
//						chmax(dp[h][i + 1][k], dp[h][i][k] + 1);
//					}
//					else {
//						chmax(dp[h][i + 1][k], dp[h][i][k] - 1);
//						chmax(dp[h][i + 1][k + 1], dp[h][i][k] + 1);
//					}
//				}
//				else {
//					if (k % 2 == 1) {
//						chmax(dp[h][i + 1][k], dp[h][i][k] + 1);
//					}
//					else {
//						chmax(dp[h][i + 1][k], dp[h][i][k] - 1);
//						chmax(dp[h][i + 1][k + 1], dp[h][i][k] + 1);
//					}
//				}
//			}
//		}
//	}
//
//	//rep(i, 0, RL.size() + 1) {
//	//	rep(k, 0, K + 1) {
//	//		dump(i, k, dp[0][i][k]);
//	//	}
//	//}
//
//	rep(h, 2, 4) {
//		rep(i, 0, UD.size()) {
//			rep(k, 0, K) {
//				if (UD[i] == "RLUD"[h]) {
//					if (k % 2 == 0) {
//						chmax(dp[h][i + 1][k], dp[h][i][k] + 1);
//					}
//					else {
//						chmax(dp[h][i + 1][k], dp[h][i][k] - 1);
//						chmax(dp[h][i + 1][k + 1], dp[h][i][k] + 1);
//					}
//				}
//				else {
//					if (k % 2 == 1) {
//						chmax(dp[h][i + 1][k], dp[h][i][k] + 1);
//					}
//					else {
//						chmax(dp[h][i + 1][k], dp[h][i][k] - 1);
//						chmax(dp[h][i + 1][k + 1], dp[h][i][k] + 1);
//					}
//				}
//			}
//		}
//	}
//
//	int ans = -INF;
//	rep(j, 0, K + 1) {
//		rep(k, 0, K + 1) {
//			if (j + k > K)break;
//			rep(a, 0, 2)rep(b, 2, 4) {
//				chmax(ans, dp[a][RL.size()][j] + dp[b][UD.size()][k]);
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}