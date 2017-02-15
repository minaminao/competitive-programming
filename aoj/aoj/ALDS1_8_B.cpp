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

struct Node {
	int v;
	Node *p, *l, *r;
};

Node *root;

void insert(int v) {
	Node *p = root;
	Node *u = (Node *)malloc(sizeof(Node));
	u->v = v;
	u->l = u->r = nullptr;
	while (p != nullptr) {
		u->p = p;
		if (u->v < p->v)
			p = p->l;
		else
			p = p->r;
	}
	if (p == root)
		root = u;
	else {
		if (u->v < u->p->v)
			u->p->l = u;
		else
			u->p->r = u;
	}
}

Node *find(Node *u, int v) {
	while (u != nullptr && v != u->v) {
		if (v < u->v)
			u = u->l;
		else
			u = u->r;
	}
	return u;
}

void inorder(Node *u) {
	if (u == nullptr)return;
	inorder(u->l);
	cout << ' ' << u->v;
	inorder(u->r);
}

void preorder(Node *u) {
	if (u == nullptr)return;
	cout << ' ' << u->v;
	preorder(u->l);
	preorder(u->r);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, 0, n) {
		string com;
		cin >> com;
		if (com[0] == 'i') {
			int key; cin >> key;
			insert(key);
		}
		else if (com[0] == 'f') {
			int key; cin >> key;
			if (find(root, key))cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else {
			inorder(root); cout << endl;
			preorder(root); cout << endl;
		}
	}
	return 0;
}