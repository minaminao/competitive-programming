#define idx(i) (i+25)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define REMOVE(v,a) v.erase(remove(v.begin(),v.end(),a),v.end())

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }


//���W���k(map)
//v: ���k�O�̍��W�z�� ��������
//�߂�l: zip[���k�O�̍��W]:���k��̍��W (zip.size()<=10^5�Ȃ獂���ɓ���)
template<typename T>
map<T, T> compress(vector<T> v) {
	map<T, T> zip;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
	return zip;
}

//���W���k
//v: ���k�O�̍��W�z�� ��������
template<typename T>
vector<int> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

//���k��̍��W
//index(���k�O�̍��W, ���k�O�̍��W�̔z��(����))
template<typename T>
int index(const vector<T> &v, T i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }
//#define index(v,i) lower_bound((v).begin(), (v).end(), (i)) - (v).begin();

//2����imos�@
struct Imos {
	int X, Y;
	vector<vector<int>> s; //�ݐϘa 1-based
	Imos(const vector<vector<int>> &f) :X(f.size()), Y(f[0].size()), s(X + 1, vector<int>(Y + 1)) {
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				s[x + 1][y + 1] += s[x + 1][y] + s[x][y + 1] - s[x][y] + f[x][y];
	}
	//[x1,x2)����[y1,y2)��field�̘a
	int sum(int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1]; }
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

//�s��̐�
using Array = vector<int>;
using Matrix = vector<Array>;
Matrix matrix_multiplication(Matrix &a, Matrix &b) {
	int n = a.size(), m = b.size(), l = b[0].size();
	Matrix c(n, Array(l, 0));
	rep(i, 0, n) rep(j, 0, l) rep(k, 0, m) c[i][j] += a[i][k] * b[k][j];
	return c;
}

//���ʂ𑖍����ĒT������n�́A������߂�
//��.(0,2)==1 �
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
class Dice {
private:
	map<char, string> mp;
public:
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

const double PI = acos(-1);

signed main() {
	//cin������
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i;
	i & 1; //���

	vector<int> v, v2;
	v.erase(v.begin() + i); //i�Ԗڂ̗v�f���폜
	v.erase(v.begin(), v.begin() + i); //i�Ԗڂ̗v�f�܂ō폜
	find(v.begin(), v.end(), 1); //1������
	count(v.begin(), v.end(), 1); //1�̌�
	search(v.begin(), v.end(), v2.begin(), v2.end()); //�����������
	replace(v.begin(), v.end(), 1, 2); //1��2�ɒu������
	rotate(v.begin(), v.end() + 1, v.end());//����1���V�t�g
	random_shuffle(v.begin(), v.end()); //���������̏��Ԃ̓��͂Ɏア���g����
	v.insert(v.end(), v2.begin(), v2.end()); //v�̖�����v2��}��
	binary_search(v.begin(), v.end(), 2);//�\�[�g�ς݂̃V�[�P���X�ɑ΂��Ă��̒l�����݂��邩�ǂ��� set���g���Ȃ���

										 /*
										 <functional>
										 ��r�n
										 equal_to, not_equal_to, greater, less, greater_equal, less_equal
										 ���Z�n
										 plus, minus, multiplies, divides, modulus, negate
										 */

	hash<int>()(1);

	//while(query()); //bool query(){}

	string(3, 'a'); //"aaa"

					//����
	vector<char> op = { '+','-','*' };
	sort(all(op)); //�\�[�g���Ȃ��Ɠr������ɂȂ�
	do {
	} while (next_permutation(op.begin(), op.end()));

	LLONG_MAX;

	cout << setw(4) << setfill('0') << 1 << endl; //0001

	using P = pair<string, string>;


	map<string, int>mp = { { "a", 1 },{ "b", 2 } };
	/*
	map�͐錾����͋�
	map::operator[]�𑶍݂��Ȃ��L�[�ɑ΂��ČĂяo����
	�f�t�H���g�l�̃C���X�^���X���쐬���ăZ�b�g�����
	�f�t�H���g�l�Ƃ̓f�t�H���g�R���X�g���N�^�Ō��߂��l
	int���̊�{�^�̓N���X�ł͂Ȃ����Ǖ��@��̓R���X�g���N�^�A�R�s�[�R���X�g���N�^�����邩�̂悤�ɂ�����
	map<string,int>����mp["hoge"]��mp["hoge"]=int()�Ɠ���
	int()�͏��0�Ɗ��҂��Ă���
	*/
	mp["hoge"]++;//1
	for (auto it = mp.begin(); it != mp.end(); it++);
	mp.count("hoge");

	//v={1,2,...,v.size()}
	iota(v.begin(), v.end(), 1);


	//since c++17
	//template <class C>
	//constexpr auto size(const C& c) -> decltype(c.size()) {
	//	return c.size();
	//}
	//template <class T, std::size_t N>
	//constexpr std::size_t size(const T(&array)[N]) noexcept {
	//	return N;
	//}
	vector<int> v(10); dump(size(v)); //10
	int a[10]; dump(size(a)); //10

	dump(__LINE__);

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

	return 0;
}

signed main_201609() {
	int i = 1;
	double d = 1.0;
	char c = 'c';
	string s = "string";
	vector<int> vi;
	vector<double> vd;

	//���a
	int sum = accumulate(all(vi), 0), sum2 = accumulate(all(vd), 0.0);
	long long sum = accumulate(all(vi), 0LL); //long long �Ȃ� 0LL�ɂ��Ȃ��ƃI�[�o�[�t���[
	double ave = sum / vi.size();
	i = 5;
	dump(bitset<3>(i));

	//push_back���emplace_back���g���Ƒ���
	vi.emplace_back(0);

	//priority_queue�Ŏ��O�̔�r��������@�i�x���j
	//cmp��sort�Ɏw�肵���Ƃ��̋t����pop����邱�Ƃɒ���
	//struct�ŉ��Z�q�̃I�[�o�[���[�h�����ق�������
	using pii = pair<int, int>;
	auto cmp = [](pii a, pii b) {return a.first == b.first ? a.second > b.second : a.first < b.first; };
	priority_queue < pii, vector<pii>, decltype(cmp) > pq(cmp);

	//pair
	pii p{ 1,2 };

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
	set.erase(2);
	auto itr = set.find(2);
	set.count(2);
	set.size();
	set.empty();

	//map
	map<int, int> m;
	m.find(1);
	for (auto it = m.begin(); it != m.end(); it++) {

	}

	//stack
	stack<int> st;

	//list
	list<char> list;
	list.emplace_back(c);
	list.front(); list.pop_front();
	list.back(); list.pop_back();

	//�^�ϊ�
	//char��string
	s += 'c';
	//string��int
	int a = stoi(s);
	//int��string
	s = to_string(a);

	//�񕪒T��
	if (binary_search(all(vi), 0));
	//�w�肵���l�ȏ� �̒l�̈ʒu
	auto it = lower_bound(all(vi), 0);
	//�w�肵���l���� �̒l�̈ʒu
	auto it = upper_bound(all(vi), 0);
	//lower upper
	pair<deque<int>::iterator, deque<int>::iterator> range;
	range = equal_range(all(vi), 0);

	//dx,dy��rep��
	int y, x, H, W;
	rep(dy, -1, 2) rep(dx, -1, 2) {
		int yy = y + dy, xx = x + dx;
		if (1 <= yy && yy <= H - 2 && 1 <= xx && xx <= W - 2) {}
	}

	//dp��swap���g����%2���g���Ƌ�Ԃ�2�ōς�
	int dp[2];
	swap(dp[0], dp[1]);
	int i; dp[i % 2];

	//90�x��] (0,0)(0,j)(i,0)(i,j)���ǂ��ړ����邩���l���Ď���
	int N;
	char C[100][100] = {};
	rep(i, 0, N)rep(j, 0, N)cin >> C[i][j];
	rep(j, 0, N) { rrep(i, 0, N)cout << C[i][j]; cout << endl; }

	//�����A���S���Y��
	rand(); //[0,32767]

			//�v�f�������܂܂�Ă��邩
	vector<int> v;
	count(v.begin(), v.end(), 1);
	count_if(v.begin(), v.end(), [](int x) {return x % 2 == 1; });

	//�����_��
	[]	//�����_�L���v�`���[
	()	//�p�����[�^��`��
	{}	//�����X�e�[�g�����g
		()	//�֐��Ăяo����
		;

	//���d���[�v�𔲂��鎞 INF���g���ƕ֗�
	rep(i, 0, 10)rep(j, 0, 10) { i = INF; break; }
}
