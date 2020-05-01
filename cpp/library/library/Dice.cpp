struct Dice {
	static const int tbl[6][4];
	int t, f;
	Dice(int top, int front) : t(top), f(front) {}
	int top() { return t; }
	int front() { return f; }
	int right() {
		for (int i = 0; i < 4; i++)
			if (tbl[t - 1][i] == f)
				return tbl[t - 1][(i + 1) % 4];
		return -1;
	}
	int bottom() { return 7 - top(); }
	int left() { return 7 - right(); }
	int rear() { return 7 - front(); }
};
const int Dice::tbl[6][4] = {
	{ 5, 4, 2, 3 },
	{ 3, 1, 4, 6 },
	{ 6, 5, 1, 2 },
	{ 1, 5, 6, 2 },
	{ 1, 3, 6, 4 },
	{ 3, 2, 4, 5 },
};

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
Dice next(int top, int front, int dir) {
	Dice d(top, front);
	switch (dir) {
	case 0: return Dice(d.front(), d.bottom());
	case 1: return Dice(d.left(), d.front());
	case 2: return Dice(d.rear(), d.top());
	case 3: return Dice(d.right(), d.front());
	}
}

namespace _ {
	//‹Œ ƒTƒCƒRƒ
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
}