/*
平方分割
更新クエリ・質問クエリ共にをO(√n)以下にする
sqrt_n は定数にしても良い
x は bucket[x / sqrt_n] に属する

構造体の方は遅い
定数倍高速化するならグローバル変数の方を使う
最速は処理をmain関数内に埋め込む

log10(n), n, sqrt(n)
1, 10, 3.16228
3, 1000, 31.6228
5, 100000, 316.228
7, 10000000, 3162.28
*/

const int MAX_N = 1e5;
const int SQRT_N = 317;
const int BUCKET_SIZE = 1 + (MAX_N - 1) / SQRT_N;
int dat[MAX_N] = {};
int bucket[SQRT_N] = {};

void init(const vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		dat[i] = v[i];
	}
}

void query1(int x, int val) {
	dat[x];
	int k = x / SQRT_N;
	for (int i = k * SQRT_N; i < (k + 1) * SQRT_N; i++) {
		dat[i];
	}
	bucket[k];
}

void query2(int l, int r, int val) {
	for (int k = 0; k < BUCKET_SIZE; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			bucket[k];
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i];
			}
		}
	}
}

//構造体ver
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> dat;
	vector<int> bucket;
	SqrtDecomposition(int n) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		dat.assign(bucket_size * sqrt_n, 0);
		bucket.assign(bucket_size, 0);
	}
	void query1(int x, int val) {
		dat[x];
		int k = x / sqrt_n;
		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
			dat[i];
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
					dat[i];
				}
			}
		}
	}
};

//Range Minimum Query (RMQ)
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232123
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> dat;
	vector<int> bucket;
	SqrtDecomposition(int n, int val = 0) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		dat.assign(bucket_size * sqrt_n, val);
		bucket.assign(bucket_size, val);
	}
	void update(int x, int y) {
		int k = x / sqrt_n;
		dat[x] = y;
		int mini = y;
		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
			chmin(mini, dat[i]);
		}
		bucket[k] = mini;
	}
	int get_min(int l, int r) {
		int ret = dat[l];
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				chmin(ret, bucket[k]);
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					chmin(ret, dat[i]);
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
	vector<int> dat;
	vector<int> bucket;
	SqrtDecomposition(int n, int val = 0) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		dat.assign(bucket_size * sqrt_n, val);
		bucket.assign(bucket_size, val);
	}
	void add(int x, int val) {
		int k = x / sqrt_n;
		dat[x] += val;
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
					ret += dat[i];
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
	vector<int> dat;
	vector<int> bucket;
	SqrtDecomposition(int n) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		dat.assign(bucket_size * sqrt_n, 0);
		bucket.assign(bucket_size, 0);
	}
	int get(int x) {
		return dat[x] + bucket[x / sqrt_n];
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
					dat[i] += val;
				}
			}
		}
	}
};