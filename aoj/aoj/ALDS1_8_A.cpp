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
//	int key;
//	Node *p, *l, *r;
//};
//Node *root;
//void insert(int k) {
//	Node *y = nullptr;
//	Node *x = root;
//	Node *z;
//	z = (Node *)malloc(sizeof(Node));
//	z->key = k;
//	z->l = nullptr;
//	z->r = nullptr;
//	while (x != nullptr) {
//		y = x;
//		if (z->key < x->key)
//			x = x->l;
//		else
//			x = x->r;
//	}
//	z->p = y;
//	if (y == nullptr) {
//		root = z;
//	}
//	else {
//		if (z->key < y->key) {
//			y->l = z;
//		}
//		else {
//			y->r = z;
//		}
//	}
//}
//
//void inorder(Node *u) {
//	if (u == nullptr)return;
//	inorder(u->l);
//	cout << ' ' << u->key;
//	inorder(u->r);
//}
//
//void preorder(Node *u) {
//	if (u == nullptr)return;
//	cout << ' ' << u->key;
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
//		else {
//			inorder(root); cout << endl;
//			preorder(root); cout << endl;
//		}
//	}
//	return 0;
//}