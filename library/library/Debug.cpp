//�𒼉��Ƃ̔�r
template<class F>
void diff(F f1, F f2) {
	static const int N = 1;
	//f1, f2 �̈����Ƃ��čl��������̂�S�āi�ꕔ�j��r
	for (int mask = 0; mask < (1 << N*N); mask++) {
		//��������
		vector<vector<int>> v(N, vector<int>(N, 0));
		rep(i, 0, N*N)v[i / N][i % N] = ((mask >> i) & 1) ? 1 : 0;

		auto res1 = f1(v), res2 = f2(v);
		dump(res1, res2);
		assert(res1 == res2);
	}
}