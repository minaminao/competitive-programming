//population count
//—§‚Á‚Ä‚¢‚ébit‚Ì”‚ğ”‚¦‚é
int popcount(int x) {
	int ret = 0;
	//Œã‚ë‚©‚ç—§‚Á‚Ä‚¢‚ébit‚ğ~‚ë‚·
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}