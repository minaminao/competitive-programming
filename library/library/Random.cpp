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
	rand() ‚æ‚è mt ‚Ì‚Ù‚¤‚ª‘¬‚¢ê‡‚à‚ ‚é
	random_devise ‚Í’x‚¢

	•ª•z¶¬Ší‚à‚ ‚é‚ª mt % N ‚Å\•ª
	*/

	random_device rd;
	mt19937 mt(rd());
	//[0, 2^32)
	mt();

	mt19937_64 mt64(rd());
	mt64();
}