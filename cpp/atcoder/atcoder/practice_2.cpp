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

int N, Q;

template <class It>
bool f(It a, It b) {
	cout << "? " << *a << " " << *b << endl;
	char c; cin >> c;
	return c == '<';
}

template <class It>
void merge(It l, It m, It r) {
	using T = typename iterator_traits<It>::value_type;
	vector<T> tmp(r - l);
	It it = tmp.begin(), it1 = l, it2 = m;
	while (it1 != m && it2 != r) {
		if (f(it1, it2))
			*it++ = *it1++;
		else
			*it++ = *it2++;
	}
	while (it1 != m) *it++ = *it1++;
	while (it2 != r) *it++ = *it2++;
	move(tmp.begin(), tmp.end(), l);
};

template <class It>
void merge_sort(It l, It r) {
	if (r - l <= 1)return;
	It m = l + (r - l) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, m, r);
}

using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
	bool operator<(const Edge &e)const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int s, int d, Weight w = 1) { g[s].emplace_back(s, d, w); }


//トポロジカルソート O(E+V)
//入次数が0の点と辺を取り除きながらretに突っ込む
vector<int> topological_sort(const Graph &g) {
	int n = g.size(), k = 0;
	vector<int> ord(n), indeg(n); //入次数
	for (auto &es : g) for (auto &e : es) indeg[e.d]++;
	queue<int> Q;
	for (int i = 0; i < n; i++) if (indeg[i] == 0) Q.push(i);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop(); ord[k++] = v;
		for (auto &e : g[v]) if (--indeg[e.d] == 0) Q.push(e.d);
	}
	return *max_element(indeg.begin(), indeg.end()) == 0 ? ord : vector<int>();
}

void solve() {
	Graph g(5);
	auto q = [&](char a, char b) {
		cout << "? " << a << " " << b << endl;
		char c; cin >> c;
		if (c == '<')add_arc(g, a - 'A', b - 'A');
		else add_arc(g, b - 'A', a - 'A');
		return c == '<';
	};


	vector<int> f(120);
	vector<char> v(5);
	iota(v.begin(), v.end(), 'A');
	int idx = 0;
	int x = 0, y = 0;
	rep(p, 0, 7) {
		rep(i, 0, 5) {
			rep(j, i + 1, 5) {
				sort(all(v));
				int idx = 0;
				int x = 0, y = 0;
				do {
					if (!f[idx]) {
						if (find(all(v), i + 'A') < find(all(v), j + 'A')) {
							x++;
						}
						else {
							y++;
						}
					}
					idx++;
				} while (next_permutation(v.begin(), v.end()));
				dump(x, y);
				if (abs(x - y) <= 1) {
					bool res = q(i + 'A', j + 'A');
					idx = 0;
					do {
						if (!f[idx]) {
							if (res) {
								if (find(all(v), i + 'A') > find(all(v), j + 'A')) {
									f[idx] = true;
								}
							}
							else {
								if (find(all(v), i + 'A') < find(all(v), j + 'A')) {
									f[idx] = true;
								}
							}
						}
						idx++;
					} while (next_permutation(v.begin(), v.end()));
					dump((char)('A' + i), (char)('A' + j));
					i = INF; j = INF;
				}
			}
		}
	}
	vector<int> ans = topological_sort(g);
	cout << "! ";
	rep(i, 0, N)cout << (char)(ans[i] + 'A');
	cout << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> Q;
	if (N == 26) {
		vector<char> v(N);
		iota(v.begin(), v.end(), 'A');
		merge_sort(v.begin(), v.end());
		cout << "! ";
		rep(i, 0, N)cout << v[i];
		cout << endl;
	}
	else {
		solve();
	}
	return 0;
}