signed main() {
	int n = 4;
	regex a(">'={" + to_string(n) + "}#={" + to_string(n) + "}~");
	regex b(R"(>\^(Q=)+~~)");
	//R"()" 生文字列リテラル
	//エスケープ不要

	string s = "";
	if (regex_match(s, a));//完全一致
	if (regex_search(s, b));//部分一致
	return 0;
}