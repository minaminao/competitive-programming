//‚µ‚á‚­‚Æ‚è–@
void sliding_window(const vector<int> &a) {
	int n = a.size(), l = 0, r = 0;
	while (l < n) {
		if (r == n) {
			//break;
			a[l];
			l++;
		}
		//‹æŠÔ‚ğ‹·‚ß‚é
		else if (1/*‹æŠÔ‚ªL‚°‚ç‚ê‚È‚¢ğŒ*/) {
			/* ˆ— */
			if (l == r) {
				l++, r++;
			}
			else {
				a[l];
				l++;
			}
		}
		//‹æŠÔ‚ğL‚°‚é
		else {
			a[r];
			r++;
		}
	}
}

//a_l + a_l+1 + ... + a_r-1 >= S ‚Æ‚È‚é•”•ª—ñ‚Ì’·‚³ r-l ‚ÌÅ¬’l
int smallest_window(const vector<int> &a, int S) {
	int n = a.size(), l = 0, r = 0;
	int sum = 0;
	int ret = INF;
	while (l < n) {
		if (r == n) {
			sum -= a[l];
			l++;
		}
		else if (sum + a[r] >= S) {
			chmin(ret, r + 1 - l);
			if (l == r) {
				l++, r++;
			}
			else {
				sum -= a[l];
				l++;
			}
		}
		else {
			sum += a[r];
			r++;
		}
	}
	return ret == INF ? 0 : ret;
}

//a_l + a_l+1 + ... + a_r-1 <= x ‚ğ–‚½‚· [l, r) ‚ÌŒÂ” 
int number_of_windows(const vector<int> &a, int x) {
	int n = a.size(), l = 0, r = 0;
	int num = 0;
	int sum = 0;
	while (l < n) {
		if (r == n || sum + a[r] > x) {
			if (l == r) {
				l++, r++;
			}
			else {
				num += r - l;
				sum -= a[l];
				l++;
			}
		}
		else {
			sum += a[r];
			r++;
		}
	}
	return num;
}