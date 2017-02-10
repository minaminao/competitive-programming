class Parser {
public:
	using Iter = string::const_iterator;
	Iter it;
	Parser(Iter it) :it(it) {}
	void cmp(char expected) { if (*it != expected)cerr << *it << " is not " << expected << endl; assert(*it == expected); }
	/*
	EBNF
	Ž®=€,{('+'|'-'),€};
	€=c,{('*'|'/'),c};
	c='(',Ž®,')' | integer;
	*/
	int a() {
		int ret = b();
		while (true) {
			if (*it == '+') {
				it++;
				ret += b();
			}
			else if (*it == '-') {
				it++;
				ret -= b();
			}
			else break;
		}
		return ret;
	}
	int b() {
		int ret = c();
		while (true) {
			if (*it == '*') {
				it++;
				ret *= c();
			}
			else if (*it == '/') {
				it++;
				ret /= c();
			}
			else break;
		}
		return ret;
	}
	int c() {
		int ret;
		if (*it == '(') {
			it++;
			ret = a();
			cmp(')');
			it++;
		}
		else ret = integer();
		return ret;
	}
	int integer() {
		int ret = 0;
		while (isdigit(*it)) {
			ret *= 10;
			ret += *it - '0';
			it++;
		}
		return ret;
	}
};


signed main() {
	int n; cin >> n; cin.ignore();
	for (string s; getline(cin, s) && s != "$"; ) {
		s += "$";
		Parser P(s.begin());
		cout << P.a() << endl;
	}
	return 0;
}