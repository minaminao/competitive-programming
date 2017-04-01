template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

const double PI = acos(-1);

//�C�e���[�^����^���擾
template<class It>
void f() {
	using T = typename iterator_traits<It>::value_type;
}

//�C���^���N�e�B�u�Ȗ��͖ⓚ�������֐�������ƈ����₷��
template <class It>
bool f(It a, It b) {
	cout << "? " << *a << " " << *b << endl;
	char c; cin >> c;
	return c == '<';
}

//�\�[�g�ςݔz��̗v�f�Ƃ̍��̍ŏ��l
template<typename T>
T min_diff(const vector<T> &v, T x) {
	auto u = upper_bound(v.begin(), v.end(), x);
	if (u == v.begin())return v.front() - x;
	if (u == v.end())return x - v.back();
	return min(*u - x, x - *(u - 1));
}

//2�����z��𓮓I��
template<typename T, size_t MAX_H, size_t MAX_W>
struct _ {
	T a[MAX_H + 1][MAX_W + 1];
};

//���@�w
void magical_square(int n) {
	int f[30][30] = {};
	for (int i = n / 2 + 1, j = n / 2, cnt = 1; cnt <= n*n; cnt++) {
		while (f[i][j] != 0) (i += 1) %= n, (j += -1 + n) %= n;
		f[i][j] = cnt;
		(i += 1) %= n, (j += 1) %= n;
	}
	rep(i, 0, n) {
		cout << setw(4) << f[i][0];
		rep(j, 1, n) cout << setw(4) << f[i][j];
		cout << endl;
	}
}

//���ʂ𑖍����ĒT������n�́A������߂�
//�� (0, 2)�
int blur[3][5][5] = {
	{
		{ 0,0,1,0,0 },
		{ 0,1,1,1,0 },
		{ 0,0,1,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
	},{
		{ 0,0,1,1,1 },
		{ 0,0,1,1,1 },
		{ 0,0,1,1,1 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
	},{
		{ 0,0,1,0,0 },
		{ 0,1,1,1,0 },
		{ 1,1,1,1,1 },
		{ 0,1,1,1,0 },
		{ 0,0,1,0,0 },
	}
};

//�T�C�R��
struct Dice {
	map<char, string> mp;
	//string d = "UFRLBD";
	string d = "RENSWL";
	vector<int> v; //UFRLBD:123456
	Dice() {
		init();
		v.resize(6);
	};
	Dice(vector<int> v) :v(v) {
		init();
	};
	void init() {
		mp[d[0]] = "2354";
		mp[d[1]] = "1463";
		mp[d[2]] = "1265";
		mp[d[3]] = "1562";
		mp[d[4]] = "1364";
		mp[d[5]] = "2453";
	}
	void input() { rep(i, 0, 6) { cin >> v[i]; } }
	void roll(char c) { roll(mp[c]); }
	void roll(string s) {
		int tmp = v[s[0] - '1'];
		rep(i, 1, s.size())v[s[i - 1] - '1'] = v[s[i] - '1'];
		v[s[s.size() - 1] - '1'] = tmp;
	}
	bool operator==(const Dice &D)const { return v == D.v; }
};

signed main() {
	//cin������
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	cout << setw(4) << setfill('0') << 1 << endl; //0001
	bool flag = true;
	cout << (flag ? "YES" : "NO") << endl;
	cin.ignore();
	string s; getline(cin, s);
	return 0;
}

void f() {
	LLONG_MAX;

	using It = vector<int>::iterator;

	int i;
	i & 1; //���

	char c;
	double d;
	dump(-1 / 2); // 0

	vector<int> v, v2;
	vector<double> vd;

	//�ϐ���
	int qw, er, as, df, zx, cv;

	v.emplace_back(0); 	//push_back���emplace_back���g���Ƒ���
	v.erase(v.begin() + i); //i�Ԗڂ̗v�f���폜
	v.erase(v.begin(), v.begin() + i); //i�Ԗڂ̗v�f�܂ō폜
	find(v.begin(), v.end(), 1); //1������
	count(v.begin(), v.end(), 1); //1�̌�
	count_if(v.begin(), v.end(), [](int x) {return x % 2 == 1; });
	search(v.begin(), v.end(), v2.begin(), v2.end()); //�����������
	replace(v.begin(), v.end(), 1, 2); //1��2�ɒu������
	rotate(v.begin(), v.end() + 1, v.end()); //����1���V�t�g
	random_shuffle(v.begin(), v.end()); //���������̏��Ԃ̓��͂Ɏア���g����
	v.insert(v.end(), v2.begin(), v2.end()); //v�̖�����v2��}��
	iota(v.begin(), v.end(), 1); //{1, 2, ... , v.size()}

	;//nth_element(first, nth, last);
	//*nth = �\�[�g��������n�Ԗڂ̗v�f
	//���� ���`����
	//nth�ȊO�̕��я��̓\�[�g�ς݂ɂȂ�Ƃ͕ۏ؂���Ȃ�
	nth_element(v.begin(), v.begin() + v.size() / 2, v.end());

	;//�\�[�g�ς݂̃V�[�P���X�ɑ΂��Ă��̒l�����݂��邩�ǂ����񕪒T��
	//set���g���Ȃ���		 
	if (binary_search(all(v), 0));
	//�w�肵���l�ȏ� �̒l�̈ʒu
	auto it = lower_bound(all(v), 0);
	//�w�肵���l���� �̒l�̈ʒu
	auto it = upper_bound(all(v), 0);

	//pair<lower, upper>
	auto range = equal_range(all(v), 0);

	int sum = accumulate(all(v), 0);
	double sum2 = accumulate(all(vd), 0.0);
	long long sum = accumulate(all(v), 0LL); //long long �Ȃ� 0LL �ɂ��Ȃ��ƃI�[�o�[�t���[
	double ave = sum2 / v.size();

	;////since c++17
	//template <class C>
	//constexpr auto size(const C& c) -> decltype(c.size()) {
	//	return c.size();
	//}
	//template <class T, std::size_t N>
	//constexpr std::size_t size(const T(&array)[N]) noexcept {
	//	return N;
	//}
	v.resize(10); dump(size(v)); //10
	int a[10]; dump(size(a)); //10

	string s;
	string(3, 'a'); //"aaa"
	"URDL"[1]; //'R'

	;//�^�ϊ�
	//char��string
	s += 'c';
	//string��int
	int a = stoi(s);
	//int��string
	s = to_string(i);

	string op = "+-*";
	sort(all(op)); //�\�[�g���Ȃ��Ɠr������ɂȂ�
	do {
	} while (next_permutation(all(op)));

	//pair
	using P = pair<int, int>;
	P p{ 1,2 };
	tie(i, ignore) = p; // pair �� tuple �� = ���Z�q���ϊ�

	//tuple
	//�e�f�[�^�ɗD�揇�ʂ�����A�f�[�^���Ƃɏ����E�~��(-1������)�Ń\�[�g����Ƃ��ɕ֗�
	//tuple��memseet�͎g���Ȃ��HOR string�Ŏg���Ȃ��H�@�i�v���؁j
	tuple<int, double, string> t;
	cin >> get<0>(t);
	t = make_tuple(1, 2.0, "a");
	tie(i, ignore, s) = t;

	//set
	//�W���̂悤�Ɏg��
	//�o������ł���
	set<int> set{ 2,7,1 };
	set.insert(8);
	set.insert(v.begin(), v.end());
	set.emplace(8);
	set.erase(2);
	auto it = set.find(2);
	set.count(2);
	set.size();
	set.empty();
	//i�Ԗڂ̗v�f�����o�����Ƃ͂ł��Ȃ�

	/*
	map �͐錾����͋�
	map::operator[] �𑶍݂��Ȃ��L�[�ɑ΂��ČĂяo����
	�f�t�H���g�l�̃C���X�^���X���쐬���ăZ�b�g�����
	�f�t�H���g�l�Ƃ̓f�t�H���g�R���X�g���N�^�Ō��߂��l
	int���̊�{�^�̓N���X�ł͂Ȃ����Ǖ��@��̓R���X�g���N�^�A�R�s�[�R���X�g���N�^�����邩�̗l�ɋL�q�ł���
	map<string, int> ���� mp["hoge"] �� mp["hoge"] = int() �Ɠ���
	���� int() ����� 0 �Ɗ��҂��ėǂ�
	*/
	map<string, int> mp = { { "a", 1 },{ "b", 2 } };
	mp["hoge"]++; //1
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	mp.count("hoge");
	mp.find("hoge");
	for (auto &e : mp) {
		e.first; e.second;
	}

	//stack
	stack<int> st;

	//priority_queue�Ŏ��O�̔�r��������@�i�x���j
	//cmp��sort�Ɏw�肵���Ƃ��̋t����pop����邱�Ƃɒ���
	//struct�ŉ��Z�q�̃I�[�o�[���[�h�����ق�������
	auto cmp = [](P a, P b) {return a.first == b.first ? a.second > b.second : a.first < b.first; };
	priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

	//list
	list<char> list;
	list.emplace_back(c);
	list.front(); list.pop_front();
	list.back(); list.pop_back();

	//bitset
	bitset<8> bs1(5); dump(bs1);
	bitset<8> bs2("110"); dump(bs2);
	dump(bs1&bs2);
	dump(bs1 | bs2);
	dump(bs1^bs2);
	dump(~bs1); //���]

	bitset<8> bs;
	bs[0] = 1; dump(bs);
	bs.set(1); dump(bs, bs.count()); //1�̌�
	bs.reset(0); dump(bs, bs.size());
	dump(bs, bs.test(2)); //2�̈ʒu��bit��1
	dump(bs, bs.any()); //�����ꂩ��bit��1
	dump(bs, bs.none()); //�S�Ă�bit��0
	dump(bs.to_ulong());
	dump(bs.to_ullong());
	dump(bs.to_string());
	dump(bs << 1);
	dump(bs >> 1);

	//11111.....
	dump(bitset<100>(~0ULL)); //64bit
	dump(bitset<100>(~0)); //64bit
	dump(bitset<100>(-1)); //64bit
	dump(bitset<100>(~0U)); //32bit


	hash<int>()(1);
	auto query = []() {return true; };
	while (query());

	//3^N�̏�Ԃ��
	int N;
	vector<int> pow3(N + 1, 1);
	rep(i, 0, N)pow3[i + 1] *= pow3[i] * 3;
	vector<int> a(N);
	auto f = [&](int mask) {
		rep(i, 0, N)a[i] = (mask / pow3[i]) % 3;
		dump(a);
	};
	for (int mask = 0; mask < pow3[N]; mask++) {
		f(mask);
	}

	//�� a b c ... z aa ab ...
	int N;
	vector<int> pow27(N + 1, 1);

	dump(is_array<int>::value);
	dump(is_array<int[]>::value);


	//�����_�̂݃W���b�W�������Ƃ�
	assert(N <= 1000);


	//�� ���Z�q�̗D�揇��

	//90�x��] (0,0)(0,j)(i,0)(i,j)���ǂ��ړ����邩���l���Ď���
	int N;
	char C[100][100] = {};
	rep(i, 0, N)rep(j, 0, N)cin >> C[i][j];
	rep(j, 0, N) { rrep(i, 0, N)cout << C[i][j]; cout << endl; }

	//�����_��
	[]	//�����_�L���v�`���[
	()	//�p�����[�^��`��
	{}	//�����X�e�[�g�����g
		()	//�֐��Ăяo����
		;

	//���d���[�v�𔲂��鎞 INF���g���ƕ֗�
	rep(i, 0, 10)rep(j, 0, 10) { i = INF; break; }

	//���dbreak�̑���Ƀ����_��
	rep(i, 0, 10)rep(j, 0, 10) {
		auto f = [&]() {
			rep(k, 0, 10)rep(l, 0, 10) {
				return;
			}
		};
		f();
	}

	//�j��
	vector<string> v = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

}

/*
<functional>
��r�n
equal_to, not_equal_to, greater, less, greater_equal, less_equal
���Z�n
plus, minus, multiplies, divides, modulus, negate
*/

void miss() {
	int x, y; bool z;
	z = x == y; //z �� true �ɂȂ����炸���� true �ɂ��Ă��������Ȃ�
	if (x == y)z = true; //�ɂ��Ă���
}

//������
using Point = pair<double, double>;
using Rectangle = pair<Point, Point>;
// t
//s

Rectangle common(const Rectangle &r1, const Rectangle &r2) {
	Point s1, t1, s2, t2;
	tie(s1, t1) = r1;
	tie(s2, t2) = r2;
	chmax(s1, s2);
	chmin(t1, t2);
	return Rectangle(s1, t1);
}