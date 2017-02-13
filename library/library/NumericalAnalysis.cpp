template<class F>
double binary_search_(double l, double r, F f) {
	//assert(lb < ub + EPS);
	double d = r - l;
	for (int i = 0; i < 100; i++) {
		d /= 2;
		if (f(l + d)) l += d;
	}
	return l;
}