//population count
//�����Ă���bit�̐��𐔂���
int popcount(int x) {
	int ret = 0;
	//��납�痧���Ă���bit���~�낷
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}