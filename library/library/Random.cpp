string random(size_t N) {
	string res;
	for (auto i = 0; i < N; i++)
		res.push_back('a' + rand() % 26);
	return res;
}

void solve() {
	rand(); //[0,32767]
}