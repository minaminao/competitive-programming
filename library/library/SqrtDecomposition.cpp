/*
平方分割
更新クエリ・質問クエリ共にをO(√n)以下にする
sqrt_n は定数にしても良い
x は bucket[x / sqrt_n] に属する
*/

struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> data;
	vector<int> bucket;
	SqrtDecomposition(int n) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		data.assign(bucket_size * sqrt_n, 0);
		bucket.assign(bucket_size, 0);
	}
	void query1(int x, int val) {
		data[x];
		int k = x / sqrt_n;
		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
			data[i];
		}
		bucket[k];
	}
	void query2(int l, int r, int val) {
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				bucket[k];
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					data[i];
				}
			}
		}
	}
};

//Range Minimum Query (RMQ)
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232123
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> data;
	vector<int> bucket;
	SqrtDecomposition(int n, int val = 0) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		data.assign(bucket_size * sqrt_n, val);
		bucket.assign(bucket_size, val);
	}
	void update(int x, int y) {
		int k = x / sqrt_n;
		data[x] = y;
		int mini = y;
		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
			chmin(mini, data[i]);
		}
		bucket[k] = mini;
	}
	int get_min(int l, int r) {
		int ret = data[l];
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				chmin(ret, bucket[k]);
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					chmin(ret, data[i]);
				}
			}
		}
		return ret;
	}
};

//Range Sum Query (RSQ)
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232132
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> data;
	vector<int> bucket;
	SqrtDecomposition(int n, int val = 0) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		data.assign(bucket_size * sqrt_n, val);
		bucket.assign(bucket_size, val);
	}
	void add(int x, int val) {
		int k = x / sqrt_n;
		data[x] += val;
		bucket[k] += val;
	}
	int get_sum(int l, int r) {
		int ret = 0;
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				ret += bucket[k];
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					ret += data[i];
				}
			}
		}
		return ret;
	}
};

//Range Add Query (RAQ)
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232193
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> data;
	vector<int> bucket;
	SqrtDecomposition(int n) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		data.assign(bucket_size * sqrt_n, 0);
		bucket.assign(bucket_size, 0);
	}
	int get(int x) {
		return data[x] + bucket[x / sqrt_n];
	}
	void add(int l, int r, int val) {
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				bucket[k] += val;
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					data[i] += val;
				}
			}
		}
	}
};