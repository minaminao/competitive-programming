signed main() {
	int n = 4;
	regex a(">'={" + to_string(n) + "}#={" + to_string(n) + "}~");
	regex b(R"(>\^(Q=)+~~)");
	//R"()" �������񃊃e����
	//�G�X�P�[�v�s�v

	string s = "";
	if (regex_match(s, a));//���S��v
	if (regex_search(s, b));//������v
	return 0;
}