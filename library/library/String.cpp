//delimiter�ŋ�؂�
vector<string> split(const string &input, const char &delimiter) {
	vector<string> ret;
	string w;
	for (const char &c : input) {
		if (c == delimiter) {
			ret.emplace_back(w);
			w.clear();
		}
		else w += c;
	}
	if (input.back() == delimiter)ret.emplace_back("");
	else ret.emplace_back(w);
	return ret;
}

//delimiter�̘A�� �� ���e��delimiter �͖���
vector<string> split(const string &input, const char &delimiter) {
	vector<string> ret;
	string w;
	for (const char &c : input) {
		if (c == delimiter) {
			if (w.size())ret.emplace_back(w);
			w.clear();
		}
		else w += c;
	}
	if (w.size())ret.emplace_back(w);
	return ret;
}

string join(const vector<string> &input, const char &separator) {
	string ret = input[0];
	for (int i = 1; i < input.size(); i++) {
		ret += separator;
		ret += input[i];
	}
	return ret;
}

//input�Ɋ܂܂��search��S��format�ɒu������ �j��I
void replace_all(string& input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
}

//input�Ɋ܂܂��search��S��format�ɒu������ ��j��I
string replace_all_copy(string input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
	return input;
}


//Roling Hash
//RollingHash RH(s,base) base:[2,MOD)�̗���
//RH.set(s,base): vector���č\�z����̂͏d���̂ŃR���X�g���N�^���g��Ȃ�
//RH.get(l,r): [l,r)�̃n�b�V�� O(1)
//1000000007, 1000000009, 1000000021
template<long long MOD>
struct RollingHash {
	int n;
	long long base;
	vector<long long> pow, hash;
	RollingHash() {}
	RollingHash(const string &s, long long base_ = 10007) { init(s, base_); }
	void init(const string &s, long long base_ = 10007) {
		n = s.size();
		base = base_;
		calc(s.c_str());
	}
	long long get(int x)const { return hash[x]; }
	long long get(int l, int r)const { return (get(r) - get(l)*pow[r - l] % MOD + MOD) % MOD; }
	void calc(const char *s) {
		pow.resize(n + 1);
		pow[0] = 1;
		hash.resize(n + 1);
		hash[0] = 0;
		for (int i = 0; i < n; i++) {
			pow[i + 1] = pow[i] * base % MOD;
			hash[i + 1] = (s[i] + hash[i] * base) % MOD;
		}
	}
};

//Manacher O(S)
//�߂�l: r[i]: s[i]�𒆐S�Ƃ���Œ��̉񕶂̔��a (�S��+1)/2
//����̂� �������̓_�~�[�����������
vector<int> manacher(const string &s) {
	int n = s.size();
	vector<int> r(n);
	int i = 0, j = 0;
	while (i < n) {
		while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
		r[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < n && k + r[i - k] < j) r[i + k] = r[i - k], ++k;
		i += k; j -= k;
	}
	return r;
}

//Z algorithm O(S)
//�Œ����ʐڎ�
struct ZAlgorithm {
	//�߂�l: a[i]: s��s[i:s.size()-1]�̍Œ����ʐړ����̒���
	vector<int> construct(const string &s) {
		int n = s.size();
		vector<int> a(n); a[0] = n;
		int i = 1, j = 0;
		while (i < n) {
			while (i + j < n && s[j] == s[i + j]) ++j;
			a[i] = j;
			if (j == 0) { ++i; continue; }
			int k = 1;
			while (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;
			i += k; j -= k;
		}
		return a;
	}
	//�߂�l: a[i]: t��s[i:s.size()-1]�̍Œ����ʐړ����̒���
	vector<int> construct(const string &s, const string &t) {
		vector<int> a = construct(t + s);
		a.erase(a.begin(), a.begin() + t.size());
		int T = t.size();
		for (int &e : a)if (e > T)e = T;
		return a;
	}
	//�߂�l: a[i]: t��s[i:s.size()-1]�̍Œ����ʐڔ����̒���
	vector<int> construct_suffix(string s, string t) {
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		vector<int> a = construct(s, t);
		reverse(a.begin(), a.end());
		return a;
	}
};


//�ׂ������̑�

//�������啶����
void stoupper(string& s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
void stolower(string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }

//0���� �j��I
void fill(string& s, int length, char c = '0') {
	string prefix = "";
	for (int i = s.size(); i < length; i++)prefix += c;
	s = prefix + s;
}
//0����
string fill(const string &s, int length, char c = '0') {
	string prefix = "";
	for (int i = s.size(); i < length; i++)prefix += c;
	return prefix + s;
}

signed main() {
	//http://sarudeki.jp/fernweh/cpp-stdstring/
	char c;
	string s, t;
	//s��t���܂܂�Ă��邩 if(s.find(t))�̓_��
	s.find(t) != string::npos;

	isalpha(c); //alphabet��
	isdigit(c);
	islower(c);
	isupper(c);

	s.size();
	{
		s.length(); //s.size()
		s.empty(); //s.size() == 0
	}
	s.front();
	s.back();

	size_t off, count;
	s.substr(off, count); //off����count�����̕�����
	s.insert(off, t); //off��t��}��
	s.replace(off, count, t); //off����count������t�ɒu��

	s.pop_back(); //1���������폜 stack���ۂ��g���Ƃ��ɕ֗�

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	s = { c };
	s = "" + c;
	s = string(1, c);

	return 0;
}