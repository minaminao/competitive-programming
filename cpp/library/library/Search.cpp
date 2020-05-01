/*
false  ... false [true] ...  true
[true]�̃C���f�b�N�X��Ԃ�

true ... (true) false ... false
(true)���~�����Ȃ�����𔽓]����
false ... (false) [true] ... true
[true]�̃C���f�b�N�X����1������
*/
template<class F>
int binary_search_(int l, int r, F f) {
	if (f(l))return l; //exception f(l):true
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	//f(l):false, f(r):true
	return r;
}

template<class F>
double binary_search_(double l, double r, F f) {
	if (f(l))return l; //exception f(l):true
	for (int i = 0; i < 60; i++) { //���[�v�̉񐔂͓K��
		double m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	return r; //f(l):false, f(r):true
}

void solve() {
	auto f = [&](int x) {return x > 0; };
	auto binary_search = [&](int l, int r) {
		if (f(l))return l; //exception f(l):true
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (f(m))
				r = m;
			else
				l = m;
		}
		//f(l):false, f(r):true
		return r;
	};
	auto f = [&](double x) {
		return x*x;
	};
	auto binary_search = [&](double l, double r) {
		if (f(l))return l; //exception f(l):true
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2;
			if (f(m))
				r = m;
			else
				l = m;
		}
		return r; //f(l):false, f(r):true
	};
	//�O���T��
	auto ternary_search = [&](double l, double r) {
		for (int i = 0; i < 100; i++) {
			double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			//min �� : f(m1) > f(m2)
			//max �� : f(m1) < f(m2)
			if (f(m1) > f(m2)) {
				l = m1;
			}
			else {
				r = m2;
			}
		}
		return r;
	};
}