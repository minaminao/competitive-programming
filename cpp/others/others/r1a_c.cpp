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
//#define MAX 202
//int dp[2][101][MAX][101];
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	//freopen("B-small-attempt0.in", "r", stdin);
//	//freopen("B-small-attempt0.txt", "w", stdout);
//	//freopen("in.txt", "r", stdin);
//	////freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	for (int t = 0; t < T; t++) {
//		int Hd, Ad, Hk, Ak; cin >> Hd >> Ad >> Hk >> Ak;
//		int B, D; cin >> B >> D;
//		memset(dp, -1, sizeof(dp));
//		dp[0][Hd][Ad][Ak] = Hk;
//		//if (t == 3)break;
//		auto f = [&]() {
//			rep(i, 0, 220) {
//				memset(dp[1], 0x3f, sizeof(dp[1]));
//
//				rep(hd, 1, Hd + 1)rep(ad, 0, MAX)rep(ak, 0, 101) {
//					if (dp[0][hd][ad][ak] != -1) {
//						dump(dp[0][hd][ad][ak], hd, ad, ak);
//						if (dp[0][hd][ad][ak] - ad <= 0) {
//							return i + 1;
//						}
//						//attack
//						chmin(dp[1][hd][ad][ak], dp[0][hd][ad][ak] - ad);
//						//buff
//						if (ad + B < MAX)
//							chmin(dp[1][hd][ad + B][ak], dp[0][hd][ad][ak]);
//						//cure
//						chmin(dp[1][Hd][ad][ak], dp[0][hd][ad][ak]);
//						//debuff
//						chmin(dp[1][hd][ad][max(0LL, ak - D)], dp[0][hd][ad][ak]);
//					}
//				}
//
//				memset(dp[0], -1, sizeof(dp[0]));
//
//				bool dead = true;
//				rep(hd, 1, Hd + 1)rep(ad, 0, MAX)rep(ak, 0, 101) {
//					if (dp[1][hd][ad][ak] != INF) {
//						if (hd - ak > 0) {
//							//attack
//							chmax(dp[0][hd - ak][ad][ak], dp[1][hd][ad][ak]);
//							dead = false;
//						}
//					}
//				}
//				if (dead)return INF;
//			}
//			return INF;
//		};
//		int ans = f();
//		if (ans == INF) {
//			cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
//		}
//		else {
//			cout << "Case #" << t + 1 << ": " << ans << endl;
//		}
//	}
//	return 0;
//}