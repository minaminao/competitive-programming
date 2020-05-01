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
//	int H, W, h, w; cin >> H >> W >> h >> w;
//	vector<vector<int>> v(H, vector<int>(W));
//	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
//	rep(i, 0, H - h + 1)rep(j, 0, W - w + 1) {
//		rep(k, 0, h)rep(l, 0, w) {
//			int ni = i + k, nj = j + l;
//			if (!inrange(ni, nj))break;
//			v[ni][nj]++;
//		}
//	}
//	vector<vector<int>> a(H, vector<int>(W));
//	auto f = [&]() {
//		int sum = 0;
//		rep(i, 0, H)rep(j, 0, W)
//			sum += a[i][j];
//		return sum > 0;
//	};
//	//while (!f()) {
//
//	//}
//	dump(v);
//	return 0;
//}