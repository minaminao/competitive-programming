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