//�f�W���f�[�^�\��
struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
};

//�f�W���f�[�^�\�� + �W�����̍ŏ��l�����߂�@�\
struct UnionFind_ {
	vector<int> parent;
	vector<int> mini;
	int size;
	UnionFind_(int n) :parent(n, -1), size(n), mini(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		mini[x] = min(mini[x], mini[y]);
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
	int minOf(int x) { return mini[root(x)]; }
};

//�A�������ɃC���f�b�N�X�����蓖�Ă�
struct UnionFind_ {
	vector<int> parent;
	vector<int> idx;
	int size;
	UnionFind_(int n) :parent(n, -1), size(n), idx(n) {
		iota(all(idx), 0);
	}
	bool unite(int x, int y, int i) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		idx[x] = idx[y] = i;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
	int getIdx(int x) { return idx[root(x)]; }
};

//�����O���t�̕H�̌��o
//����A�������� id �Ƃ��Č���Ɠs��������
struct UnionFind {
	vector<int> parent;
	vector<bool> cycle;
	int size;
	UnionFind(int n) :parent(n, -1), size(n), cycle(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) {
			cycle[x] = true;
			return false;
		}
		if (cycle[x] || cycle[y])cycle[x] = cycle[y] = true;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
	bool has_cycle(int x) { return cycle[root(x)]; }
};