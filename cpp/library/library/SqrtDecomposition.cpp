/*
平方分割
更新クエリ・質問クエリ共にをO(√n)以下にする
sqrt_n は定数にしても良い
x は bucket[x / sqrt_n] に属する

構造体の方は遅い
定数倍高速化するならグローバル変数の方を使う
最速は処理をmain関数内に埋め込む

遅延伝播は RUQ を参照

MAX_N <= SQRT_N^2 を満たす値にする
log10(n), n, sqrt(n)
1, 10, 3.16228
3, 1000, 31.6228
5, 100000, 316.228
7, 10000000, 3162.28

[l, r)

*/

const int SQRT_N = 317;
const int MAX_N = SQRT_N*SQRT_N;
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
	for (int k = 0; k < SQRT_N; k++) {
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

//Range Update Query (RUQ)
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232387
const int SQRT_N = 317;
const int MAX_N = SQRT_N*SQRT_N;
int dat[MAX_N] = {};
int lazy_bucket[SQRT_N] = {};
bool lazy_flag[SQRT_N] = {};

void init(int n) {
	rep(i, 0, n) {
		dat[i] = INT_MAX;
	}
}

int get(int x) {
	int k = x / SQRT_N;
	return lazy_flag[k] ? lazy_bucket[k] : dat[x];
}

void update(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			lazy_bucket[k] = val;
			lazy_flag[k] = true;
		}
		else {
			if (lazy_flag[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket[k];
				}
				lazy_flag[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] = val;
			}
		}
	}
}

//RSQ and RAQ
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232416#1
const int SQRT_N = 317;
const int MAX_N = SQRT_N*SQRT_N;
int dat[MAX_N] = {};
int bucket_add[SQRT_N] = {};
int bucket_sum[SQRT_N] = {};

void add(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			bucket_add[k] += val;
			bucket_sum[k] += val*SQRT_N;
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] += val;
				bucket_sum[k] += val;
			}
		}
	}
}

int get_sum(int l, int r) {
	int ret = 0;
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			ret += bucket_sum[k];
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				ret += dat[i] + bucket_add[k];
			}
		}
	}
	return ret;
}

//RMQ and RUQ
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232449
const int SQRT_N = 317;
const int MAX_N = SQRT_N*SQRT_N;
int dat[MAX_N] = {};
int bucket_min[SQRT_N] = {};
int lazy_bucket_update[SQRT_N] = {};
bool lazy_flag_update[SQRT_N] = {};

void init() {
	rep(i, 0, MAX_N)
		dat[i] = INT_MAX;
	rep(k, 0, SQRT_N)
		bucket_min[k] = INT_MAX;
}

void update(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			lazy_bucket_update[k] = val;
			lazy_flag_update[k] = true;
			bucket_min[k] = val;
		}
		else {
			if (lazy_flag_update[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket_update[k];
				}
				lazy_flag_update[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] = val;
			}
			int mini = dat[bl];
			for (int i = bl; i < br; i++)
				chmin(mini, dat[i]);
			bucket_min[k] = mini;
		}
	}
}

int find(int l, int r) {
	int mini = INT_MAX;
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			chmin(mini, bucket_min[k]);
		}
		else {
			if (lazy_flag_update[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket_update[k];
				}
				lazy_flag_update[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				chmin(mini, dat[i]);
			}
		}
	}
	return mini;
}