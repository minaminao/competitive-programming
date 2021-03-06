string random(size_t N) {
	string res;
	for (auto i = 0; i < N; i++)
		res.push_back('a' + rand() % 26);
	return res;
}

void solve() {
	//[0, 2^15) = [0, 32769)
	rand(); 

	/*
	rand() より mt のほうが速い場合もある
	random_devise
		遅い
		g++(windows) だと毎回同じ値になる

	分布生成器もあるが mt % N で十分なはず
	*/

	random_device rd;
	mt19937 mt(rd());
	//[0, 2^32)
	mt();

	mt19937_64 mt64(rd());
	mt64();
}