template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

const double PI = acos(-1);

//イテレータから型を取得
template<class It>
void f() {
	using T = typename iterator_traits<It>::value_type;
}

//インタラクティブな問題は問答部分を関数化すると扱いやすい
template <class It>
bool f(It a, It b) {
	cout << "? " << *a << " " << *b << endl;
	char c; cin >> c;
	return c == '<';
}

//ソート済み配列の要素との差の最小値
template<typename T>
T min_diff(const vector<T> &v, T x) {
	auto u = upper_bound(v.begin(), v.end(), x);
	if (u == v.begin())return v.front() - x;
	if (u == v.end())return x - v.back();
	return min(*u - x, x - *(u - 1));
}

//2次元配列を動的に
template<typename T, size_t MAX_H, size_t MAX_W>
struct _ {
	T a[MAX_H + 1][MAX_W + 1];
};

//魔法陣
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

//平面を走査して探索する系は、基準を決める
//例 (0, 2)基準
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

//サイコロ
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
	//cin高速化
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
	i & 1; //奇数か

	char c;
	double d;
	dump(-1 / 2); // 0

	vector<int> v, v2;
	vector<double> vd;

	//変数名
	int qw, er, as, df, zx, cv;

	v.emplace_back(0); 	//push_backよりemplace_backを使うと速い
	v.erase(v.begin() + i); //i番目の要素を削除
	v.erase(v.begin(), v.begin() + i); //i番目の要素まで削除
	find(v.begin(), v.end(), 1); //1を検索
	count(v.begin(), v.end(), 1); //1の個数
	count_if(v.begin(), v.end(), [](int x) {return x % 2 == 1; });
	search(v.begin(), v.end(), v2.begin(), v2.end()); //部分列を検索
	replace(v.begin(), v.end(), 1, 2); //1を2に置き換え
	rotate(v.begin(), v.end() + 1, v.end()); //左に1つ分シフト
	random_shuffle(v.begin(), v.end()); //乱択や特定の順番の入力に弱い時使える
	v.insert(v.end(), v2.begin(), v2.end()); //vの末尾にv2を挿入
	iota(v.begin(), v.end(), 1); //{1, 2, ... , v.size()}

	;//nth_element(first, nth, last);
	//*nth = ソートした時のn番目の要素
	//平均 線形時間
	//nth以外の並び順はソート済みになるとは保証されない
	nth_element(v.begin(), v.begin() + v.size() / 2, v.end());

	;//ソート済みのシーケンスに対してその値が存在するかどうか二分探索
	//setが使えない時		 
	if (binary_search(all(v), 0));
	//指定した値以上 の値の位置
	auto it = lower_bound(all(v), 0);
	//指定した値超え の値の位置
	auto it = upper_bound(all(v), 0);

	//pair<lower, upper>
	auto range = equal_range(all(v), 0);

	int sum = accumulate(all(v), 0);
	double sum2 = accumulate(all(vd), 0.0);
	long long sum = accumulate(all(v), 0LL); //long long なら 0LL にしないとオーバーフロー
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

	;//型変換
	//char→string
	s += 'c';
	//string→int
	int a = stoi(s);
	//int→string
	s = to_string(i);

	string op = "+-*";
	sort(all(op)); //ソートしないと途中からになる
	do {
	} while (next_permutation(all(op)));

	//pair
	using P = pair<int, int>;
	P p{ 1,2 };
	tie(i, ignore) = p; // pair → tuple に = 演算子が変換

	//tuple
	//各データに優先順位があり、データごとに昇順・降順(-1かける)でソートするときに便利
	//tupleでmemseetは使えない？OR stringで使えない？　（要検証）
	tuple<int, double, string> t;
	cin >> get<0>(t);
	t = make_tuple(1, 2.0, "a");
	tie(i, ignore, s) = t;

	//set
	//集合のように使う
	//出し入れできる
	set<int> set{ 2,7,1 };
	set.insert(8);
	set.insert(v.begin(), v.end());
	set.emplace(8);
	set.erase(2);
	auto it = set.find(2);
	set.count(2);
	set.size();
	set.empty();
	//i番目の要素を取り出すことはできない

	/*
	map は宣言直後は空
	map::operator[] を存在しないキーに対して呼び出すと
	デフォルト値のインスタンスを作成してセットされる
	デフォルト値とはデフォルトコンストラクタで決めた値
	int等の基本型はクラスではないけど文法上はコンストラクタ、コピーコンストラクタがあるかの様に記述できる
	map<string, int> だと mp["hoge"] は mp["hoge"] = int() と同じ
	他の int() も常に 0 と期待して良い
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

	//priority_queueで自前の比較をする方法（遅い）
	//cmpをsortに指定したときの逆順にpopされることに注意
	//structで演算子のオーバーロードしたほうが速い
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
	dump(~bs1); //反転

	bitset<8> bs;
	bs[0] = 1; dump(bs);
	bs.set(1); dump(bs, bs.count()); //1の個数
	bs.reset(0); dump(bs, bs.size());
	dump(bs, bs.test(2)); //2の位置のbitが1
	dump(bs, bs.any()); //いずれかのbitが1
	dump(bs, bs.none()); //全てのbitが0
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

	//3^Nの状態を列挙
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

	//未 a b c ... z aa ab ...
	int N;
	vector<int> pow27(N + 1, 1);

	dump(is_array<int>::value);
	dump(is_array<int[]>::value);


	//部分点のみジャッジしたいとき
	assert(N <= 1000);


	//未 演算子の優先順位

	//90度回転 (0,0)(0,j)(i,0)(i,j)がどう移動するかを考えて実装
	int N;
	char C[100][100] = {};
	rep(i, 0, N)rep(j, 0, N)cin >> C[i][j];
	rep(j, 0, N) { rrep(i, 0, N)cout << C[i][j]; cout << endl; }

	//ラムダ式
	[]	//ラムダキャプチャー
	()	//パラメータ定義節
	{}	//複合ステートメント
		()	//関数呼び出し式
		;

	//多重ループを抜ける時 INFを使うと便利
	rep(i, 0, 10)rep(j, 0, 10) { i = INF; break; }

	//多重breakの代わりにラムダ式
	rep(i, 0, 10)rep(j, 0, 10) {
		auto f = [&]() {
			rep(k, 0, 10)rep(l, 0, 10) {
				return;
			}
		};
		f();
	}

	//曜日
	vector<string> v = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

}

/*
<functional>
比較系
equal_to, not_equal_to, greater, less, greater_equal, less_equal
演算系
plus, minus, multiplies, divides, modulus, negate
*/

void miss() {
	int x, y; bool z;
	z = x == y; //z が true になったらずっと true にしておきたいなら
	if (x == y)z = true; //にしておく
}

//未検証
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