//愚直解との比較
template<class F>
void diff(F f1, F f2) {
	static const int N = 1;
	//f1, f2 の引数として考えられるものを全て（一部）比較
	for (int mask = 0; mask < (1 << N*N); mask++) {
		//引数生成
		vector<vector<int>> v(N, vector<int>(N, 0));
		rep(i, 0, N*N)v[i / N][i % N] = ((mask >> i) & 1) ? 1 : 0;

		auto res1 = f1(v), res2 = f2(v);
		dump(res1, res2);
		assert(res1 == res2);
	}
}

#include "Random.cpp"
template<class F>
void diff(F f1, F f2) {
	static const int N = 5;
	for (int i = 0; i < 1000; i++) {
		string s = random(N);
		string res1 = solve(s), res2 = solve2(s);
		if (res1 == res2)continue;
		dump(s, res1, res2);
	}
}

#include "Geometry.cpp"
void debug(const vector<Point> &v) {
	if (!_DEBUG)return;
	int xmax, xmin, ymax, ymin;
	xmax = xmin = v[0].x;
	ymax = ymin = v[0].y;
	rep(i, 1, v.size()) {
		chmax(xmax, (int)v[i].x);
		chmin(xmin, (int)v[i].x);
		chmax(ymax, (int)v[i].y);
		chmin(ymin, (int)v[i].y);
	}
	vector<vector<char>> out(ymax - ymin + 1, vector<char>(xmax - xmin + 1, '.'));
	rep(i, 0, v.size()) {
		out[v[i].y - ymin][v[i].x - xmin] = '*';
	}
	int w = 3 + log10(xmin) + 1 + log10(ymin) + 1;
	cout << string(xmax - xmin + 1 + w, ' ');
	cout << '(' << xmax << ',' << ymax << ')' << endl;
	rrep(i, 0, out.size()) {
		cout << string(w, ' ');
		cout << out[i][0];
		rep(j, 1, out[i].size()) { cout << out[i][j]; }
		cout << endl;
	}
	cout << '(' << xmin << ',' << ymin << ')' << endl;
}

signed main() {
	dump(__LINE__);
	return 0;
}