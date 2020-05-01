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
//struct Node {
//	int k;
//	Node *p, *l, *r;
//};
//
//Node *root;
//
//void insert(int k) {
//	Node *p = root;
//	Node *u = (Node *)malloc(sizeof(Node));
//	u->k = k;
//	u->l = u->r = nullptr;
//	while (p != nullptr) {
//		u->p = p;
//		if (u->k < p->k)
//			p = p->l;
//		else
//			p = p->r;
//	}
//	if (p == root)
//		root = u;
//	else {
//		if (u->k < u->p->k)
//			u->p->l = u;
//		else
//			u->p->r = u;
//	}
//}
//
//Node *find(Node *u, int k) {
//	while (u != nullptr && k != u->k) {
//		if (k < u->k)
//			u = u->l;
//		else
//			u = u->r;
//	}
//	return u;
//}
//
//Node *tree_minimum(Node *u) {
//	while (u->l != nullptr)u = u->l;
//	return u;
//}
//
//Node *tree_successor(Node *u) {
//	if (u->r != nullptr)return tree_minimum(u->r);
//	Node *v = u->p;
//	while (v != nullptr&&u == v->r) {
//		u = v;
//		v = v->p;
//	}
//	return v;
//}
//
//void tree_delete(Node *u) {
//	Node *y;
//	Node *x;
//	if (u->l == nullptr || u->r == nullptr)y = u;
//	else y = tree_successor(u);
//	if (y->l != nullptr) {
//		x = x->l;
//	}
//	else {
//		x = y->r;
//	}
//
//	if (x != nullptr)x->p = y->p;
//
//	if (y->p == nullptr) {
//		root = x;
//	}
//	else {
//		if (y == y->p->l) {
//			y->p->l = x;
//		}
//		else {
//			y->p->r = x;
//		}
//	}
//	if (y != x) {
//		u->k = y->k;
//	}
//	free(y);
//}
//
//void inorder(Node *u) {
//	if (u == nullptr)return;
//	inorder(u->l);
//	cout << ' ' << u->k;
//	inorder(u->r);
//}
//
//void preorder(Node *u) {
//	if (u == nullptr)return;
//	cout << ' ' << u->k;
//	preorder(u->l);
//	preorder(u->r);
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n; cin >> n;
//	rep(i, 0, n) {
//		string com;
//		cin >> com;
//		if (com[0] == 'i') {
//			int key; cin >> key;
//			insert(key);
//		}
//		else if (com[0] == 'f') {
//			int key; cin >> key;
//			if (find(root, key))cout << "yes" << endl;
//			else cout << "no" << endl;
//		}
//		else if (com[0] == 'd') {
//			int key; cin >> key;
//			tree_delete(find(root, key));
//		}
//		else {
//			inorder(root); cout << endl;
//			preorder(root); cout << endl;
//		}
//	}
//	return 0;
//}