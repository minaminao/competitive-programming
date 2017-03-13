//Structure of Array (SoA) をソート
template<class T, class ...Tail>
void tied_sort(vector<T> &a, vector<Tail>&... tail) {
	int n = a.size();
	using S = tuple<T, Tail...>;
	vector<S> s(n);
	for (int i = 0; i < n; i++)
		s[i] = make_tuple(a[i], tail[i]...);
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		tie(a[i], tail[i]...) = s[i];
}

//merge sort
template <class It>
void merge(It l, It m, It r) {
	vector<int> tmp(r - l);
	It it = tmp.begin(), it1 = l, it2 = m;
	while (it1 != m && it2 != r) {
		if (*it1 < *it2)
			*it++ = *it1++;
		else
			*it++ = *it2++;
	}
	while (it1 != m) *it++ = *it1++;
	while (it2 != r) *it++ = *it2++;
	move(tmp.begin(), tmp.end(), l);
};

template <class It>
void merge_sort(It l, It r) {
	if (r - l <= 1)return;
	It m = l + (r - l) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, m, r);
}
//end merge sort

//反転数
//a[i] > a[j] かつ i < j である組の数
template <class It>
long long merge(It l, It m, It r) {
	long long cnt = 0;
	vector<int> tmp(r - l);
	It it = tmp.begin(), it1 = l, it2 = m;
	while (it1 != m && it2 != r) {
		if (*it1 < *it2)
			*it++ = *it1++;
		else
			*it++ = *it2++, cnt += m - it1;
	}
	while (it1 != m) *it++ = *it1++;
	while (it2 != r) *it++ = *it2++;
	move(tmp.begin(), tmp.end(), l);
	return cnt;
};

template <class It>
long long merge_sort(It l, It r) {
	if (r - l <= 1)return 0;
	long long cnt = 0;
	It m = l + (r - l) / 2;
	cnt += merge_sort(l, m);
	cnt += merge_sort(m, r);
	cnt += merge(l, m, r);
	return cnt;
}
//end 反転数

//quick sort
//v[i] <= x <= v[j] にする (i<=j) O(N) [l,r]
//STL にある。partition(v.begin(), v.end(), [x](int i) {return i <= x; }); のように使う。
template<typename T>
int partition(vector<T> &v, int l, int r, T x) {
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (v[j] <= x) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[r]);
	return i + 1;
}

//平均O(NlogN) 最悪O(N^2) [l,r]
template<typename T>
void quick_sort(vector<T> &v, int l, int r) {
	if (l < r) {
		int k = partition(v, l, r, v[r]);
		quick_sort(v, l, k - 1);
		quick_sort(v, k + 1, r);
	}
}
//end quick sort

//計数ソート O(n+k)
//制約: 0 <= v[i] <= k
void counting_sort(vector<int> &v) {
	int n = v.size(), k = *max_element(v.begin(), v.end());
	vector<int> cnt(k + 1), tmp(v);
	cnt[0]--;
	for (int x : v)cnt[x]++;
	for (int i = 0; i < k; i++)cnt[i + 1] += cnt[i];
	for (int i = n - 1; i >= 0; i--) {
		v[cnt[tmp[i]]] = tmp[i];
		cnt[tmp[i]]--;
	}
}

//最小コストソート
//コスト v[i]+v[j] の交換を用いてソートする場合の最小コスト
//オーバーフローに注意 v[i]!=v[j]
template<class T>
T minimum_cost_sort(const vector<T> &v) {
	int n = v.size();
	T total_cost = 0;
	vector<pair<T, int>> sorted(n);
	for (int i = 0; i < n; i++)sorted[i] = make_pair(v[i], i);
	sort(sorted.begin(), sorted.end());
	T mini = sorted[0].first;
	vector<bool> is_sorted(n);
	for (int i = 0; i < n; i++) {
		if (is_sorted[sorted[i].second])continue;
		T loop_cost = 0;
		T loop_sum = 0;
		T loop_mini = sorted[i].first;
		T loop_n = 0;
		for (int j = i;;) {
			T cost = sorted[j].first;
			int dst = sorted[j].second;
			is_sorted[j] = true;
			chmin(loop_mini, cost);
			loop_sum += cost;
			loop_n++;
			j = dst;
			if (is_sorted[dst])break;
		}
		total_cost += min(
			loop_sum + (loop_n - 2)*loop_mini,
			loop_sum + loop_mini + (loop_n + 1)*mini
		);
	}
	return total_cost;
}