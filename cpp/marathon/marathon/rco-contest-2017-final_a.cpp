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
////population count
////—§‚Á‚Ä‚¢‚ébit‚Ì”‚ð”‚¦‚é
//int popcount(int x) {
//	int ret = 0;
//	//Œã‚ë‚©‚ç—§‚Á‚Ä‚¢‚ébit‚ð~‚ë‚·
//	while (x) {
//		x &= x - 1;
//		ret++;
//	}
//	return ret;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	auto f = [&]() {
//		int D, T; cin >> D >> T;
//		vector<int> C(8); rep(i, 0, 8) { cin >> C[i]; }
//		vector<int> A(8); rep(i, 0, 8) { cin >> A[i]; }
//
//		rep(mask, 1, 1 << 8) {
//			int tmp = 0;
//			int n = popcount(mask);
//
//			bool flag = false;
//			rep(i, 0, 8) {
//				if (mask >> i & 1) {
//					if (A[i] == 0)flag = true;
//					tmp += A[i];
//				}
//			}
//			if (flag)continue;
//
//			if (tmp == D) {
//				cout << "sell " << n;
//				rep(i, 0, 8) {
//					if (mask >> i & 1) {
//						cout << " " << i + 1;
//					}
//				}
//				cout << endl;
//				return;
//			}
//		}
//
//		rep(i, 0, 8) {
//			if (C[i] == D&&T >= 2) {
//				cout << "fill " << i + 1 << endl;
//				return;
//			}
//		}
//		if (D > 35) {
//			int mint = INF, mint_mask = 0;
//			rep(mask, 1, 1 << 8) {
//				int tmp = 0;
//				int n = popcount(mask);
//				int t = 0;
//				bool flag = false;
//				rep(i, 0, 8) {
//					if (mask >> i & 1) {
//						if (C[i] == 0)flag = true;
//						if (A[i] != C[i])t++;
//						tmp += C[i];
//					}
//				}
//				if (flag)continue;
//
//				if (t + 1 > T)continue;
//				if (tmp == D) {
//					if (chmin(mint, t)) {
//						mint_mask = mask;
//					}
//				}
//			}
//
//			if (mint != INF) {
//				dump(mint, bitset<8>(mint_mask));
//				rep(i, 0, 8) {
//					if (mint_mask >> i & 1) {
//						if (A[i] == C[i])continue;
//						cout << "fill " << i + 1 << endl;
//						return;
//					}
//				}
//			}
//		}
//
//		if (*min_element(all(A)) == 0) {
//			rep(i, 0, 8) {
//				if (A[i] == 0) {
//					cout << "fill " << i + 1 << endl;
//					return;
//				}
//			}
//		}
//		else {
//			cout << "pass" << endl;
//			return;
//		}
//	};
//	rep(q, 0, 1000) {
//		f();
//	}
//	return 0;
//}


#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

//population count
//—§‚Á‚Ä‚¢‚ébit‚Ì”‚ð”‚¦‚é
int popcount(int x) {
	int ret = 0;
	//Œã‚ë‚©‚ç—§‚Á‚Ä‚¢‚ébit‚ð~‚ë‚·
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	auto f = [&]() {
		int D, T; cin >> D >> T;
		vector<int> C(8); rep(i, 0, 8) { cin >> C[i]; }
		vector<int> A(8); rep(i, 0, 8) { cin >> A[i]; }
		rep(mask, 1, 1 << 8) {
			int tmp = 0;

			bool flag = false;
			rep(i, 0, 8) {
				if (mask >> i & 1) {
					if (A[i] == 0)flag = true;
					tmp += A[i];
				}
			}
			if (flag)continue;

			if (tmp == D) {
				int n = popcount(mask);
				cout << "sell " << n;
				rep(i, 0, 8) {
					if (mask >> i & 1) {
						cout << " " << i + 1;
					}
				}
				cout << endl;
				return;
			}
		}

		rep(i, 0, 8) {
			if (C[i] == D&&T >= 2) {
				cout << "fill " << i + 1 << endl;
				return;
			}
		}
		if (*min_element(all(A)) == 0) {
			rep(i, 0, 8) {
				if (A[i] == 0) {
					cout << "fill " << i + 1 << endl;
					return;
				}
			}
		}
		else {
			cout << "pass" << endl;
			return;
		}
	};
	cout << "pass" << endl;
	rep(q, 0, 999) {
		f();
	}
	return 0;
}