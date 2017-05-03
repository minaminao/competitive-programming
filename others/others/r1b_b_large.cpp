//#include "bits/stdc++.h"
//using namespace std;
//#define dump(...)
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
//	freopen("B-large-practice.in", "r", stdin);
//	freopen("B-large-practice.txt", "w", stdout);
//	//freopen("in.txt", "r", stdin);
//	////freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	cout << fixed << setprecision(10);
//	for (int t = 0; t < T; t++) {
//		string ans;
//
//		int N; cin >> N;
//		int R, O, Y, G, B, V;
//		cin >> R >> O >> Y >> G >> B >> V;
//
//		if (R < G || B < O || Y < V) {
//			ans = "IMPOSSIBLE";
//		}
//		else if (R&&G&&R + G != N&&R == G) {
//			ans = "IMPOSSIBLE";
//		}
//		else if (B&&O&&B + O != N&&B == O) {
//			ans = "IMPOSSIBLE";
//		}
//		else if (Y&&V&&Y + V != N&&Y == V) {
//			ans = "IMPOSSIBLE";
//		}
//		else if (R&&G&&R + G == N&&R == G) {
//			rep(i, 0, R) {
//				ans += "RG";
//			}
//		}
//		else if (B&&O&&B + O == N&&B == O) {
//			rep(i, 0, B) {
//				ans += "BO";
//			}
//		}
//		else if (Y&&V&&Y + V == N&&Y == V) {
//			rep(i, 0, Y) {
//				ans += "YV";
//			}
//		}
//		else {
//			dump(1);
//			R -= G;
//			B -= O;
//			Y -= V;
//			N = R + B + Y;
//			int maxi = N / 2;
//			if (R > maxi || Y > maxi || B > maxi) {
//				ans = "IMPOSSIBLE";
//			}
//			else {
//				using P = pair<int, char>;
//				vector<P> v;
//				v.emplace_back(R, 'R');
//				v.emplace_back(Y, 'Y');
//				v.emplace_back(B, 'B');
//				sort(all(v));
//				reverse(all(v));
//				vector<string> p;
//				rep(i, 0, v[0].first) {
//					p.emplace_back(string(1, v[0].second));
//				}
//				int cur = 0;
//				rep(i, 0, v[1].first) {
//					p[(cur++) % p.size()] += v[1].second;
//				}
//				rep(i, 0, v[2].first) {
//					p[(cur++) % p.size()] += v[2].second;
//				}
//				dump(p);
//				rep(i, 0, p.size()) {
//					ans += p[i];
//				}
//
//				dump(ans);
//				if (G) {
//					auto pos = ans.find("R");
//					string format = "R";
//					rep(i, 0, G)format += "GR";
//					ans.replace(pos, 1, format);
//				}
//				if (O) {
//					auto pos = ans.find("B");
//					string format = "B";
//					rep(i, 0, O)format += "OB";
//					ans.replace(pos, 1, format);
//				}
//				if (V) {
//					auto pos = ans.find("Y");
//					string format = "Y";
//					rep(i, 0, V)format += "VY";
//					ans.replace(pos, 1, format);
//				}
//			}
//		}
//		cout << "Case #" << t + 1 << ": " << ans << endl;
//	}
//	return 0;
//}