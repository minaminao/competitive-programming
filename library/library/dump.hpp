#define dump(...) cerr << #__VA_ARGS__; _dump(__VA_ARGS__);

template<class T>
void _dump(vector<T> &v) {
	for (auto &e : v)
		cerr << " " << e;
	cerr << endl;
}

template<class T1, class T2>
void _dump(map<T1, T2> &m) {
	for (auto it = m.begin(); it != m.end(); it++)
		cerr << " (" << it->first << "," << it->second << ")";
	cerr << endl;
}

template<class T1>
void _dump(T1 a) {
	cerr << " " << a << endl;
}

template<class T1, class T2>
void _dump(T1 a, T2 b) {
	cerr << " " << a << " " << b << endl;
}

template<class T1, class T2, class T3>
void _dump(T1 a, T2 b, T3 c) {
	cerr << " " << a << " " << b << " " << c << endl;
}

template<class T1, class T2, class T3, class T4>
void _dump(T1 a, T2 b, T3 c, T4 d) {
	cerr << " " << a << " " << b << " " << c << " " << d << endl;
}
template<class T1, class T2, class T3, class T4, class T5>
void _dump(T1 a, T2 b, T3 c, T4 d, T5 e) {
	cerr << " " << a << " " << b << " " << c << " " << d << " " << e << endl;
}