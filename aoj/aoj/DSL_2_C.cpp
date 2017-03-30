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

using Point = pair<int, int>;
#define x first
#define y second
struct Node {
	Point p;
	int idx;
	Node() {}
	Node(const Point &p, int idx) :p(p), idx(idx) {}
};
bool base_x(const Node &n1, const Node &n2) {
	const Point &p1 = n1.p, &p2 = n2.p;
	return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}
bool base_y(const Node &n1, const Node &n2) {
	const Point &p1 = n1.p, &p2 = n2.p;
	return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}

struct StaticKdTree {
	int n;
	vector<Node> nodes;
	using It = vector<Node>::iterator;
	vector<Node> tree;
	StaticKdTree(const vector<Point> &ps) :n(ps.size()), nodes(n), tree(n) {
		rep(i, 0, n) {
			nodes[i].p = ps[i];
			nodes[i].idx = i;
		}
		build(0, n, true);
	}
	//•½‹Ï O(nlogn)
	void build(int l, int r, bool is_x_base) {
		if (l >= r)return;
		int m = (l + r) / 2;
		It first = nodes.begin() + l,
			nth = nodes.begin() + m,
			last = nodes.begin() + r;
		//•½‹Ï O(r-l)
		if (is_x_base)
			nth_element(first, nth, last, base_x);
		else
			nth_element(first, nth, last, base_y);
		tree[m] = *nth;
		build(l, m, !is_x_base);
		build(m + 1, r, !is_x_base);
	}
	bool inrange(const Point &p, int sx, int sy, int tx, int ty) {
		return sx <= p.x&&p.x <= tx&&sy <= p.y&&p.y <= ty;
	}
	void query(int sx, int sy, int tx, int ty, vector<int> &idxs) {
		query(0, n, true, sx, sy, tx, ty, idxs);
	}
	void query(int l, int r, bool is_x_base, int sx, int sy, int tx, int ty, vector<int> &idxs) {
		dump(l, r, is_x_base, sx, sy, tx, ty);
		if (l >= r)return;
		int m = (l + r) / 2;
		Node node = tree[m];
		Point p = node.p;
		dump(p);
		if (is_x_base) {
			if (tx < p.x) {
				query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
			}
			else if (p.x < sx) {
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
			}
			else {
				if (inrange(p, sx, sy, tx, ty))idxs.emplace_back(node.idx);
				query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
			}
		}
		else {
			if (ty < p.y) {
				query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
			}
			else if (p.y < sy) {
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
			}
			else {
				if (inrange(p, sx, sy, tx, ty))idxs.emplace_back(node.idx);
				query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
			}
		}
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<Point> ps(n); rep(i, 0, n) { cin >> ps[i].x >> ps[i].y; }
	StaticKdTree tree(ps);
	int q; cin >> q;
	rep(i, 0, q) {
		int sx, tx, sy, ty; cin >> sx >> tx >> sy >> ty;
		vector<int> res;
		tree.query(sx, sy, tx, ty, res);
		sort(all(res));
		rep(i, 0, res.size()) {
			cout << res[i] << endl;
			dump(ps[res[i]]);
		}
		cout << endl;
	}
	return 0;
}