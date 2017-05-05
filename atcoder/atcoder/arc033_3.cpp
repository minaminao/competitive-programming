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

struct Treap {
	using Val = int;
	struct Node {
		Val val, sum, mini;
		Node *left, *right;
		int pri;
		int size;
		Node(Val v, int p)
			:val(v), mini(v), pri(p), size(1), sum(v) {
			left = right = NULL;
		}
	};
	int size(Node *t) { return !t ? 0 : t->size; }
	Val sum(Node *t) { return !t ? 0 : t->sum; }
	Val val(Node *t) { assert(t); return t->val; }
	Val mini(Node *t) { return !t ? INF : t->mini; }

	Node* root;
	Treap() :root(NULL) {};

	// Žq‚ª•Ï‚í‚Á‚½‚Æ‚«‚É•K‚¸ŒÄ‚Ô
	Node *update(Node *t) {
		if (!t)return t;
		t->size = size(t->left) + size(t->right) + 1;
		t->sum = sum(t->left) + sum(t->right) + t->val;
		t->mini = min({ val(t),mini(t->left),mini(t->right) });
		return t;
	}

	Node *update(Node *t, int k, Val v) {
		return insertAt(eraseAt(t, k), k, v);
	}

	Val mini(Node *t, int l, int r) {
		if (!t)return INF;
		if (r <= l)return INF;
		if (r - l == size(t))
			return mini(t);
		else if (size(t->left) >= r)
			return mini(t->left, l, r);
		else if (size(t->left) < l)
			return mini(t->right, l - (size(t->left) + 1), r - (size(t->left) + 1));
		return min({
			val(t),
			mini(t->left, l, size(t->left)),
			mini(t->right, 0, r - (size(t->left) + 1))
		});
	}

	Node *merge(Node *l, Node *r) {
		if (!l)return r;
		if (!r)return l;
		if (l->pri > r->pri) {
			l->right = merge(l->right, r);
			return update(l);
		}
		else {
			r->left = merge(l, r->left);
			return update(r);
		}
	}

	// ([0, k), [k, n))
	pair<Node*, Node*> split(Node *t, int k) {
		if (!t)return pair<Node*, Node*>(NULL, NULL);
		if (k <= size(t->left)) {
			pair<Node*, Node*> s = split(t->left, k);
			t->left = s.second;
			return make_pair(s.first, update(t));
		}
		else {
			pair<Node*, Node*> s = split(t->right, k - size(t->left) - 1);
			t->right = s.first;
			return make_pair(update(t), s.second);
		}
	}

	int lowerbound(Node *t, Val v) {
		if (!t) return 0;
		if (v <= val(t))
			return lowerbound(t->left, v);
		else
			return size(t->left) + 1 + lowerbound(t->right, v);
	}

	Node *insertAt(Node *t, int k, Val v) {
		auto s = split(t, k);
		Node *m = new Node(v, rand());
		return update(merge(update(merge(s.first, m)), s.second));
	}

	Node *insert(Node *t, Val v) {
		return insertAt(t, lowerbound(t, v), v);
	}

	Node *eraseAt(Node *t, int k) {
		auto s1 = split(t, k);
		auto s2 = split(s1.second, 1);
		return update(merge(s1.first, s2.second));
	}

	Node *at(Node *t, int k) {
		assert(size(t) > k);
		auto s = split(t, k);
		Node *ret = s.second;
		while (ret->left)
			ret = ret->left;
		merge(s.first, s.second);
		return ret;
	}

	Node* circularShift(Node *t, int l, int r) {
		Node *a, *b, *c, *d;
		tie(a, d) = split(t, r);
		tie(a, b) = split(a, l);
		tie(b, c) = split(b, r - l - 1);
		return merge(merge(a, merge(c, b)), d);
	}
};

ostream &operator<<(ostream &o, Treap t) {
	function<void(Treap::Node*)> rec = [&](Treap::Node *x) {
		if (!x)return;
		rec(x->left);
		cerr << x->val << " ";
		rec(x->right);
	};
	rec(t.root);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	Treap t;
	int Q; cin >> Q;
	rep(i, 0, Q) {
		int T; cin >> T;
		if (T == 1) {
			int x; cin >> x;
			t.root = t.insert(t.root, x);
		}
		else {
			int k; cin >> k; k--;
			auto x = t.at(t.root, k);
			t.root = t.eraseAt(t.root, k);
			cout << t.val(x) << endl;
		}
		dump(t);
	}
	return 0;
}