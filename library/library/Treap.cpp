
struct Node {
	int val;
	Node *ch[2];
	int pri;
	int cnt;
	int sum;
	int mini;

	Node(int v, double p) :val(v), mini(v), pri(p), cnt(1), sum(v) {
		ch[0] = ch[1] = NULL;
	}
};

int count(Node *t) { return !t ? 0 : t->cnt; }
int sum(Node *t) { return !t ? 0 : t->sum; }
int val(Node *t) { assert(t); return t->val; }
int mini(Node *t) { return !t ? INF : t->mini; }

void inorder(Node* root, string name = "") {
	function<void(Node*)> rec = [&](Node *x) {
		if (!x)return;
		rec(x->ch[0]);
		cerr << x->val << " ";
		rec(x->ch[1]);
	};
	cerr << name << ": ";
	rec(root);
	cerr << endl;
}

int mini(Node *t, int l, int r) {
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

// Žq‚ª•Ï‚í‚Á‚½‚Æ‚«‚É•K‚¸ŒÄ‚Ô
Node *update(Node *t) {
	if (!t)return t;
	t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
	t->sum = sum(t->ch[0]) + sum(t->ch[1]) + t->val;
	t->mini = min({ val(t),mini(t->ch[0]),mini(t->ch[1]) });
	return t;
}

Node *merge(Node *l, Node *r) {
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
pair<Node*, Node*> split(Node *t, int k) {
	if (!t)return pair<Node*, Node*>(NULL, NULL);
	if (k <= count(t->ch[0])) {
		pair<Node*, Node*> s = split(t->ch[0], k);
		t->ch[0] = s.second;
		return make_pair(s.first, update(t));
	}
	else {
		pair<Node*, Node*> s = split(t->ch[1], k - count(t->ch[0]) - 1);
		t->ch[1] = s.first;
		return make_pair(update(t), s.second);
	}
}

Node *insert(Node *t, int k, int v) {
	auto s = split(t, k);
	Node *m = new Node(v, rand());
	return update(merge(update(merge(s.first, m)), s.second));
}

Node *erase(Node *t, int k) {
	auto s1 = split(t, k);
	auto s2 = split(s1.second, 1);
	return update(merge(s1.first, s2.second));
}

Node* circularShift(Node *t, int l, int r) {
	Node *a, *b, *c, *d;
	tie(a, d) = split(t, r);
	tie(a, b) = split(a, l);
	tie(b, c) = split(b, r - l - 1);
	return merge(merge(a, merge(c, b)), d);
}

Node *update(Node*t, int k, int v) {
	t = erase(t, k);
	t = insert(t, k, v);
	return t;
}

//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2299004#1