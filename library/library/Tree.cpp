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