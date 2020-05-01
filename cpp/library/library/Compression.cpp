//座標圧縮(map)
//戻り値: zip[圧縮前の座標]:圧縮後の座標 (zip.size()<=10^5なら高速に動作)
template<typename T>
map<T, T> compress(vector<T> v) {
	map<T, T> zip;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
	return zip;
}

//普通は↓を使う

//座標圧縮
//index()と合わせて使う
template<typename T>
vector<T> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

//圧縮後の配列のインデックス
//index(圧縮後の配列, 要素)
template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }

void solve() {
	vector<int> v;
	vector<int> compressed = compress(v);
	int idx = index(compressed, INF);
}