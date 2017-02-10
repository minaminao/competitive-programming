//素集合データ構造
struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
};

//素集合データ構造 + 集合内の最小値を求める機能
struct UnionFind {
	vector<int> parent;
	vector<int> mini;
	int size;
	UnionFind(int n) :parent(n, -1), size(n), mini(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		mini[x] = min(mini[x], mini[y]);
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
	int min_of(int x) { return mini[root(x)]; }
};