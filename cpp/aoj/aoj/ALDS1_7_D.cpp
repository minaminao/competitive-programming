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

//preorder Ç∆ inorder Ç©ÇÁ postorder Çç\íz
vector<int> reconstruct_tree(const vector<int> &pre, const vector<int> &in) {
	vector<int> post;
	int pos = 0;
	function<void(int, int)> rec = [&](int l, int r) {
		if (l >= r)return;
		int root = pre[pos++];
		int m = distance(in.begin(), find(in.begin(), in.end(), root));
		rec(l, m);
		rec(m + 1, r);
		post.emplace_back(root);
	};
	rec(0, pre.size());
	return post;
}

signed main() {
	int n; cin >> n;
	vector<int> pre(n), in(n);
	rep(i, 0, n)cin >> pre[i];
	rep(i, 0, n)cin >> in[i];
	vector<int> post = reconstruct_tree(pre, in);
	cout << post[0]; rep(i, 1, post.size()) { cout << " " << post[i]; } cout << endl;
	return 0;
}