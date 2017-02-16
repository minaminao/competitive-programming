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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

const int N = 3;
const int NN = N*N;

struct Puzzle {
	int f[NN];
	int space;
	string path;

	bool operator<(const Puzzle &p)const {
		for (int i = 0; i < NN; i++) {
			if (f[i] == p.f[i])continue;
			return f[i] > p.f[i];
		}
		return false;
	}
};

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
const char dir[4] = { 'u','l','d','r' };

bool is_target(const Puzzle &p) {
	for (int i = 0; i < NN; i++) {
		if (p.f[i] != (i + 1))return false;
	}
	return true;
}

string bfs(Puzzle s) {
	queue<Puzzle> Q;
	map<Puzzle, bool> V;
	Puzzle u, v;
	s.path = "";
	Q.emplace(s);
	V[s] = true;

	while (Q.size()) {
		u = Q.front(); Q.pop();
		if (is_target(u))return u.path;
		int sx = u.space / N;
		int sy = u.space%N;
		for (int r = 0; r < 4; r++) {
			int tx = sx + dx[r];
			int ty = sy + dy[r];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N)continue;
			v = u;
			swap(v.f[u.space], v.f[tx*N + ty]);
			v.space = tx*N + ty;
			if (!V[v]) {
				V[v] = true;
				v.path += dir[r];
				Q.emplace(v);
			}
		}
	}
	return "unsolvable";
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	Puzzle in;
	for (int i = 0; i < NN; i++) {
		cin >> in.f[i];
		if (in.f[i] == 0) {
			in.f[i] = NN;
			in.space = i;
		}
	}
	string ans = bfs(in);
	cout << ans.size() << endl;

	return 0;
}