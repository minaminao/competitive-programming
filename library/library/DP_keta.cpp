//S�ȉ��̔񕉐���
void keta1() {
	//i����
	//S�����m�肩
	int dp[10][2] = {};
	string S; cin >> S;
	dp[0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			//���łɖ����m��||�����m��
			(dp[i + 1][j || d != lim] += dp[i][j]) %= MOD;
		}
	}
	int ans = dp[S.size()][0] + dp[S.size()][1];
	ans %= MOD;
	cout << ans << endl;
}

//S�ȉ��̔񕉐��� ���� 3���t��
void keta2() {
	//i����
	//S�����m�肩
	//3���t���� 
	int dp[10][2][2] = {};
	string S; cin >> S;
	dp[0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			(dp[i + 1][j || d < lim][k || d == 3] += dp[i][j][k]) %= MOD;
		}
	}
	int ans = dp[S.size()][0][1] + dp[S.size()][1][1];
	ans %= MOD;
	cout << ans << endl;
}

//S�ȉ��̔񕉐��� ���� 1���t����
void keta2a() {
	//i����
	//S�����m�肩
	//1���t����
	int dp[15][2][15] = {};
	string S; cin >> S;
	dp[0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 14) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			dp[i + 1][j || d < lim][k + (d == 1)] += dp[i][j][k];
		}
	}
	int ans = 0;
	rep(k, 1, 15) {
		ans += (dp[S.size()][0][k] + dp[S.size()][1][k])*k;
	}
	cout << ans << endl;
}

//S�ȉ��̔񕉐��� ���� (3���t�� �܂��� 3�̔{��)
void keta3() {
	//i����
	//S�����m�肩
	//3���t����
	//mod3
	int dp[10][2][2][3] = {};
	string S; cin >> S;
	dp[0][0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2)rep(l, 0, 3) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			(dp[i + 1][j || d < lim][k || d == 3][(d + l) % 3] += dp[i][j][k][l]) %= MOD;
		}
	}
	int ans = 0;
	rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 3) {
		if (k || l == 0)
			(ans += dp[S.size()][j][j][l]) %= MOD;
	}
	cout << ans << endl;
}

//S�ȉ��̔񕉐��� ���� (3���t�� �܂��� 3�̔{��) ���� 8�̔{���łȂ�
void keta4() {
	//i����
	//S�����m�肩
	//3���t����
	//mod3
	//mod8
	int dp[10][2][2][3][8] = {};
	string S; cin >> S;
	dp[0][0][0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2)rep(l, 0, 3)rep(m, 0, 8) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			(dp[i + 1][j || d < lim][k || d == 3][(d + l) % 3][(m * 10 + d) % 8] += dp[i][j][k][l][m]) %= MOD;
		}
	}
	int ans = 0;
	rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 3)rep(m, 1, 8) {
		if (k || l == 0)
			(ans += dp[S.size()][j][j][l][m]) %= MOD;
	}
	cout << ans << endl;
}

//S�ȉ��̔񕉐��� ���� 4���t������ 9���t��
int keta5(string S) {
	//i����
	//S�����m�肩
	//4���t���� 
	//9���t���� 
	int dp[20][2][2][2] = {};
	dp[0][0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2)rep(l, 0, 2) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			dp[i + 1][j || d < lim][k || d == 4][l || d == 9] += dp[i][j][k][l];
		}
	}
	int ret = dp[S.size()][1][1][0] + dp[S.size()][1][0][1] + dp[S.size()][1][1][1] + dp[S.size()][0][1][0] + dp[S.size()][0][0][1] + dp[S.size()][0][1][1];
	return ret;
}

signed main_keta5() {
	int A, B; cin >> A >> B;
	cout << keta5(to_string(B)) - keta5(to_string(A - 1)) << endl;
	return 0;
}