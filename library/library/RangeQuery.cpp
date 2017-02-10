class RangeMinimumQuery {
public:
	int n;
	vector<int> d;
	RangeMinimumQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
	}
	void update(int i, int x) {
		d[n + i] = x;
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			d[j] = min(d[j * 2], d[j * 2 + 1]);
	}
	//[l, r)
	int query(int l, int r) {
		int mi = get(l);
		for (; l && l + (l&-l) <= r; l += l&-l)
			mi = min(mi, d[(n + l) / (l&-l)]);
		for (; l < r; r -= r&-r)
			mi = min(mi, d[(n + r) / (r&-r) - 1]);
		return mi;
	}
	int get(int i) { return d[n + i]; }
};

class RangeSumQuery {
public:
	int n;
	vector<int> d;
	RangeSumQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0);
	}
	void add(int i, int x) {
		d[n + i] += x;
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			d[j] = d[j * 2] + d[j * 2 + 1];
	}
	//[l, r)
	int query(int l, int r) {
		int sum = 0;
		for (; l && l + (l&-l) <= r; l += l&-l)
			sum += d[(n + l) / (l&-l)];
		for (; l < r; r -= r&-r)
			sum += d[(n + r) / (r&-r) - 1];
		return sum;
	}
	int get(int i) { return d[n + i]; }
};

//最適か不明
class RangeUpdateQuery {
public:
	int n;
	vector<int> d;
	vector<int> timestamp;
	int time;
	RangeUpdateQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
		time = 0;
		timestamp.assign(n * 2, 0);
	}
	//[l, r)
	void update(int l, int r, int x) {
		time++;
		for (; l && l + (l&-l) <= r; l += l&-l) {
			d[(n + l) / (l&-l)] = x;
			timestamp[(n + l) / (l&-l)] = time;
		}
		for (; l < r; r -= r&-r) {
			d[(n + r) / (r&-r) - 1] = x;
			timestamp[(n + r) / (r&-r) - 1] = time;
		}
	}
	int get(int i) {
		int ret = d[n + i];
		int max_time = timestamp[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1) {
			if (max_time > timestamp[j])continue;
			max_time = timestamp[j];
			ret = d[j];
		}
		return ret;
	}
};

//最適か不明
class RangeAddQuery {
public:
	int n;
	vector<int> d;
	int time;
	RangeAddQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0);
	}
	//[l, r)
	void add(int l, int r, int x) {
		for (; l && l + (l&-l) <= r; l += l&-l)
			d[(n + l) / (l&-l)] += x;
		for (; l < r; r -= r&-r)
			d[(n + r) / (r&-r) - 1] += x;
	}
	int get(int i) {
		int ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret += d[j];
		return ret;
	}
};