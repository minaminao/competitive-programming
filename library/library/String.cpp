//delimiterで区切る
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

//delimiterの連続 と 両脇のdelimiter は無視
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

//inputに含まれるsearchを全てformatに置き換え 破壊的
void replace_all(string& input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
}

//inputに含まれるsearchを全てformatに置き換え 非破壊的
string replace_all_copy(string input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
	return input;
}


//Roling Hash
//RollingHash RH(s,base) base:[2,MOD)の乱数
//RH.set(s,base): vectorを再構築するのは重いのでコンストラクタを使わない
//RH.get(l,r): [l,r)のハッシュ O(1)
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
//戻り値: r[i]: s[i]を中心とする最長の回文の半径 (全長+1)/2
//奇数長のみ 偶数長はダミー文字列を入れる
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
//最長共通接辞
struct ZAlgorithm {
	//戻り値: a[i]: sとs[i:s.size()-1]の最長共通接頭辞の長さ
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
	//戻り値: a[i]: tとs[i:s.size()-1]の最長共通接頭辞の長さ
	vector<int> construct(const string &s, const string &t) {
		vector<int> a = construct(t + s);
		a.erase(a.begin(), a.begin() + t.size());
		int T = t.size();
		for (int &e : a)if (e > T)e = T;
		return a;
	}
	//戻り値: a[i]: tとs[i:s.size()-1]の最長共通接尾辞の長さ
	vector<int> construct_suffix(string s, string t) {
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		vector<int> a = construct(s, t);
		reverse(a.begin(), a.end());
		return a;
	}
};


//細かいもの他

//文字列を大文字に
void stoupper(string& s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
void stolower(string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }

//0埋め 破壊的
void fill(string& s, int length, char c = '0') {
	string prefix = "";
	for (int i = s.size(); i < length; i++)prefix += c;
	s = prefix + s;
}
//0埋め
string fill(const string &s, int length, char c = '0') {
	string prefix = "";
	for (int i = s.size(); i < length; i++)prefix += c;
	return prefix + s;
}

signed main() {
	//http://sarudeki.jp/fernweh/cpp-stdstring/
	char c;
	string s, t;
	//sにtが含まれているか if(s.find(t))はダメ
	s.find(t) != string::npos;

	isalpha(c); //alphabetか
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
	s.substr(off, count); //offからcount文字の文字列
	s.insert(off, t); //offにtを挿入
	s.replace(off, count, t); //offからcount文字をtに置換

	s.pop_back(); //1文字後ろを削除 stackっぽく使うときに便利

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	s = { c };
	s = "" + c;
	s = string(1, c);

	return 0;
}