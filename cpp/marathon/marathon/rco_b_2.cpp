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
//int H, W, K, T;
//int di[4] = { 0,1,0,-1 };
//int dj[4] = { 1,0,-1,0 };
//char dir[4] = { 'R','D','L','U' };
//
//using Weight = int;
//using Flow = int;
//struct Edge {
//	int s, d; Weight w; Flow c;
//	Edge() {};
//	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
//	bool operator<(const Edge &e)const { return w < e.w; }
//};
//using Edges = vector<Edge>;
//using Graph = vector<Edges>;
//using Array = vector<Weight>;
//using Matrix = vector<Array>;
//
//inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }
//
//void add_edge(Graph &g, int a, int b, Weight w = 1) {
//	g[a].emplace_back(a, b, w);
//	g[b].emplace_back(b, a, w);
//}
//void add_arc(Graph &g, int s, int d, Weight w = 1) { g[s].emplace_back(s, d, w); }
//
////“ñŽŸŒ³”z—ñ‚©‚çGraph‚ð¶¬
//Graph build(const vector<vector<char>> &v) {
//	const int H = v.size(), W = v[0].size();
//	static const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
//	auto inrange = [&](int i, int j) { return i >= 0 && i < H && j >= 0 && j < W; };
//	auto idx = [&](int i, int j) {return i*W + j; };
//	Graph g(H*W);
//	rep(i, 0, H)rep(j, 0, W) {
//		rep(k, 0, 4) {
//			int ni = i + di[k], nj = j + dj[k];
//			if (!inrange(ni, nj))continue;
//			int s = idx(i, j), d = idx(ni, nj);
//			add_arc(g, s, d);
//		}
//	}
//	return g;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cin >> H >> W >> K >> T;
//	vector<int> A(K), B(K), C(K), D(K);
//	vector<vector<char>> m(H, vector<char>(W, '.'));
//	rep(i, 0, K) {
//		cin >> A[i] >> B[i] >> C[i] >> D[i];
//		A[i]--, B[i]--, C[i]--, D[i]--;
//		m[A[i]][B[i]] = '#';
//	}
//
//	auto score = [&](int L) {
//		double PD = 20;
//		rep(i, 0, K) {
//			PD += abs(C[i] - A[i]) + abs(D[i] - B[i]);
//		}
//		double PT = 10 + L*0.01;
//		return ceil(1e7 / (PD*PT));
//	};
//
//	vector<string> ans;
//	int prev_score = score(0);
//	rep(t, 0, T) {
//		string s = "";
//		vector<vector<char>> next = m;
//		//dump(t);
//		rep(k, 0, K) {
//			//dump(k);
//			int ci = A[k], cj = B[k];
//			int idx = 0;
//
//			//dump(ci, cj);
//			//dump(C[k], D[k]);
//
//			//R
//			if (D[k] - B[k] > 0) {
//				int ni = ci + di[idx], nj = cj + dj[idx];
//				if (m[ni][nj] != '#' && next[ni][nj] != '#') {
//					next[ci][cj] = '.';
//					next[ni][nj] = '#';
//					A[k] = ni, B[k] = nj;
//					s += dir[idx];
//					continue;
//				}
//			}
//			idx++;
//			//D
//			if (C[k] - A[k] > 0) {
//				int ni = ci + di[idx], nj = cj + dj[idx];
//				if (m[ni][nj] != '#' && next[ni][nj] != '#') {
//					next[ci][cj] = '.';
//					next[ni][nj] = '#';
//					A[k] = ni, B[k] = nj;
//					s += dir[idx];
//					continue;
//				}
//			}
//			idx++;
//			//L
//			if (B[k] - D[k] > 0) {
//				int ni = ci + di[idx], nj = cj + dj[idx];
//				if (m[ni][nj] != '#' && next[ni][nj] != '#') {
//					next[ci][cj] = '.';
//					next[ni][nj] = '#';
//					A[k] = ni, B[k] = nj;
//					s += dir[idx];
//					continue;
//				}
//			}
//			idx++;
//			//U
//			if (A[k] - C[k] > 0) {
//				int ni = ci + di[idx], nj = cj + dj[idx];
//				if (m[ni][nj] != '#' && next[ni][nj] != '#') {
//					next[ci][cj] = '.';
//					next[ni][nj] = '#';
//					A[k] = ni, B[k] = nj;
//					s += dir[idx];
//					continue;
//				}
//			}
//			s += '-';
//		}
//		if (s == string(K, '-'))break;
//
//		m = next;
//
//		dump(score(t));
//		if (prev_score > score(t))break;
//		prev_score = score(t);
//
//		ans.emplace_back(s);
//	}
//
//	int L = min(T, (int)ans.size());
//	if (1) {
//		cout << L << endl;
//		rep(i, 0, L) {
//			cout << ans[i] << endl;
//		}
//	}
//	else {
//		cout << 66 << endl;
//		rep(i, 0, 66) {
//			cout << ans[i] << endl;
//		}
//	}
//
//	return 0;
//}