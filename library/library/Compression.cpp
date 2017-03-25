//���W���k(map)
//�߂�l: zip[���k�O�̍��W]:���k��̍��W (zip.size()<=10^5�Ȃ獂���ɓ���)
template<typename T>
map<T, T> compress(vector<T> v) {
	map<T, T> zip;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
	return zip;
}

//���ʂ́����g��

//���W���k
//index()�ƍ��킹�Ďg��
template<typename T>
vector<T> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

//���k��̔z��̃C���f�b�N�X
//index(���k��̔z��, �v�f)
template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }

void solve() {
	vector<int> v;
	vector<int> compressed = compress(v);
	int idx = index(compressed, INF);
}