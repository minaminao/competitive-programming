//population count
//��납�痧���Ă���bit���~�낷
int popcount(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}