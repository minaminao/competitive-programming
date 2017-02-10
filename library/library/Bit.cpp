//population count
//Œã‚ë‚©‚ç—§‚Á‚Ä‚¢‚ébit‚ğ~‚ë‚·
int popcount(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}