/*
キー静的連想配列
座標圧縮のようなイメージ
定数倍高速化に有効
unordered_map より3倍くらい速い
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236737 0,40sec
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236680 1.31sec (unordered_map)
*/
template<typename T, typename U>
class StaticKeyMap {
private:
	size_t n;
	vector<T> key;
	vector<U> val;
	U dummy;
	void compress(vector<T> &v) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}
	size_t index(const T &i) {
		auto e = lower_bound(key.begin(), key.end(), i);
		assert(e != key.end() && *e == i);
		return e - key.begin();
	}
public:
	StaticKeyMap(const vector<T> &key_) :key(key_), dummy() {
		compress(key);
		n = key.size();
		val.assign(n, U());
	}
	bool key_exists(const T &i) {
		auto e = lower_bound(key.begin(), key.end(), i);
		if (e == key.end())
			return false;
		else
			return *e == i;
	}
	U &operator[](const T &i) {
		if (key_exists(i))
			return val[index(i)];
		else {
			dummy = U();
			return dummy;
		}
	}
};