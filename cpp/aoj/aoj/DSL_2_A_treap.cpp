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
const int INF = INT_MAX;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

// Treap
struct node_t {
	int val;
	node_t *ch[2];
	int pri;
	int cnt;
	int sum;
	int mini;

	node_t(int v, double p) :val(v), mini(v), pri(p), cnt(1), sum(v) {
		ch[0] = ch[1] = NULL;
	}
};

int count(node_t *t) { return !t ? 0 : t->cnt; }
int sum(node_t *t) { return !t ? 0 : t->sum; }
int val(node_t *t) { assert(t); return t->val; }
int mini(node_t *t) { return !t ? INF : t->mini; }

void inorder(node_t* root, string name = "") {
	function<void(node_t*)> rec = [&](node_t *x) {
		if (!x)return;
		rec(x->ch[0]);
		cerr << x->val << " ";
		rec(x->ch[1]);
	};
	cerr << name << ": ";
	rec(root);
	cerr << endl;
}

int mini(node_t *t, int l, int r) {
	if (!t)return INF;
	if (r <= l)return INF;
	if (r - l == count(t))
		return mini(t);
	else if (count(t->ch[0]) >= r)
		return mini(t->ch[0], l, r);
	else if (count(t->ch[0]) < l)
		return mini(t->ch[1], l - (count(t->ch[0]) + 1), r - (count(t->ch[0]) + 1));
	return min({
		val(t),
		mini(t->ch[0], l, count(t->ch[0])),
		mini(t->ch[1], 0, r - (count(t->ch[0]) + 1))
	});
}

// 子が変わったときに必ず呼ぶ
node_t *update(node_t *t) {
	if (!t)return t;
	t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
	t->sum = sum(t->ch[0]) + sum(t->ch[1]) + t->val;
	t->mini = min({ val(t),mini(t->ch[0]),mini(t->ch[1]) });
	return t;
}

node_t *merge(node_t *l, node_t *r) {
	if (!l)return r;
	if (!r)return l;
	if (l->pri > r->pri) {
		l->ch[1] = merge(l->ch[1], r);
		return update(l);
	}
	else {
		r->ch[0] = merge(l, r->ch[0]);
		return update(r);
	}
}

// ([0, k), [k, n))
pair<node_t*, node_t*> split(node_t *t, int k) {
	if (!t)return pair<node_t*, node_t*>(NULL, NULL);
	if (k <= count(t->ch[0])) {
		pair<node_t*, node_t*> s = split(t->ch[0], k);
		t->ch[0] = s.second;
		return make_pair(s.first, update(t));
	}
	else {
		pair<node_t*, node_t*> s = split(t->ch[1], k - count(t->ch[0]) - 1);
		t->ch[1] = s.first;
		return make_pair(update(t), s.second);
	}
}

node_t *insert(node_t *t, int k, int v) {
	auto s = split(t, k);
	node_t *m = new node_t(v, rand());
	return update(merge(update(merge(s.first, m)), s.second));
}

node_t *erase(node_t *t, int k) {
	auto s1 = split(t, k);
	auto s2 = split(s1.second, 1);
	return update(merge(s1.first, s2.second));
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	node_t *root = NULL;
	rep(i, 0, n) {
		root = insert(root, i, INF);
	}
	rep(i, 0, q) {
		int com, x, y; cin >> com >> x >> y;
		dump(com, x, y);
		if (com == 0) {
			root = erase(root, x);
			root = insert(root, x, y);
		}
		else {
			cout << mini(root, x, y + 1) << endl;
		}
	}
	return 0;
}