#define MAX 1010

int K, N;
int w[MAX]; //�d��
int p[MAX]; //�P�ʏd��������̔Z�x
double y[MAX]; //��g(*100)�H�����]�邩����Ȃ���

bool C(double x) {
	rep(i, 0, N) y[i] = (p[i] - x)*w[i];
	sort(y, y + N);
	double sum = 0;
	rep(i, 0, K) sum += y[N - 1 - i];
	return sum >= 0;
}

signed main() {
	cin >> N >> K;
	rep(i, 0, N) cin >> w[i] >> p[i];
	double lb = 0, ub = INF;
	rep(i, 0, 100) {
		double mid = (lb + ub) / 2;
		if (C(mid))lb = mid;
		else ub = mid;
	}
	cout << fixed << setprecision(9);
	cout << ub << endl;
	return 0;
}