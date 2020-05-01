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
//const int H = 2;
//const int W = 4;
//const int N = H*W;
//const int dx[4] = { -1,0,1,0 };
//const int dy[4] = { 0,-1,0,1 };
//const char dir[4] = { 'u','l','d','r' };
//
////n puzzle
//struct Puzzle {
//	int f[N];
//	int space;
//	Puzzle() {};
//	bool operator<(const Puzzle &p)const {
//		for (int i = 0; i < N; i++) {
//			if (f[i] == p.f[i])continue;
//			return f[i] > p.f[i];
//		}
//		return false;
//	}
//	void slide(int t) {
//		assert(0 <= t&&t < N);
//		swap(f[space], f[t]);
//		space = t;
//	}
//};
//inline istream &operator >> (istream &is, Puzzle &p) {
//	for (int i = 0; i < N; i++) {
//		is >> p.f[i];
//		if (p.f[i] == 0)
//			p.space = i;
//	}
//	return is;
//}
//inline ostream &operator << (ostream &os, const Puzzle &p) {
//	for (int i = 0; i < N; i++)
//		os << p.f[i];
//	return os;
//}
//
//
//bool is_target(const Puzzle &p) {
//	for (int i = 0; i < N; i++)
//		if (p.f[i] != i)
//			return false;
//	return true;
//}
//
//map<Puzzle, int> mp;
//string bfs() {
//	queue<pair<Puzzle, int>> q;
//	Puzzle u, v;
//	Puzzle s;
//
//	q.emplace(s, 0);
//	mp[s] = true;
//	while (q.size()) {
//		u = q.front(); q.pop();
//		if (is_target(u))return u.path;
//		int sx = u.space % W;
//		int sy = u.space / W;
//		for (int r = 0; r < 4; r++) {
//			int tx = sx + dx[r];
//			int ty = sy + dy[r];
//			if (tx < 0 || ty < 0 || tx >= W || ty >= H)continue;
//			v = u;
//			v.slide(ty*W + tx);
//			if (mp[v])continue;
//			mp[v] = true;
//			v.path += dir[r];
//			q.emplace(v);
//		}
//	}
//	return "unsolvable";
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//	for (Puzzle p; cin >> p;) {
//		cout << dfs(p) << endl;
//	}
//	return 0;
//}