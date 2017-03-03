//���W���k(map) 1����
//�߂�l: zip[���k�O�̍��W]:���k��̍��W (zip.size()<=10^5�Ȃ獂���ɓ���)
template<typename T>
map<T, T> compress(vector<T> v) {
	map<T, T> zip;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
	return zip;
}

//���W���k�i�j��I�j
//index()�ƍ��킹�Ďg��
template<typename T>
vector<int> compress(vector<T> &v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

//���k��̍��W
//index(���k�O�̍��W�̔z��(����), ���k�O�̍��W)
template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }
//#define index(v,i) lower_bound((v).begin(), (v).end(), (i)) - (v).begin();
