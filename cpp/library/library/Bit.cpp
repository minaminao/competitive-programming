//population count
//立っているbitの数を数える
int popcount(int x) {
	int ret = 0;
	//後ろから立っているbitを降ろす
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}