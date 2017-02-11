//�f������
bool is_prime(int x) {
	if (x <= 1)return false;
	else if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return false;
	return true;
}

//�����ݏ� �J��Ԃ�����@
long long mod_pow(long long base, long long exponent, long long mod) {
	long long res = 1;
	while (exponent > 0) {
		if (exponent & 1)res = res * base % mod;
		base = base * base % mod;
		exponent >>= 1;
	}
	return res;
}
//(a*b)%mod 
long long mod_mul(long long a, long long b, long long mod) {
	long long x = 0, y = a % mod;
	while (b > 0) {
		if (b & 1)x = x + y % mod;
		y = y * 2 % mod;
		b >>= 1;
	}
	return x % mod;
}
//�f������iMiller-Rabin primality test�j2^24���x����
//miller_rabin_primality_test(n, 5)
bool miller_rabin_primality_test(long long x, int iteration) {
	if (x < 2)return false;
	if (x != 2 && x % 2 == 0)return false;
	long long s = x - 1;
	while (s % 2 == 0)s /= 2;
	for (int i = 0; i < iteration; i++) {
		long long a = rand() % (x - 1) + 1, temp = s;
		long long mod = mod_pow(a, temp, x);
		while (temp != x - 1 && mod != 1 && mod != x - 1) {
			mod = mod_mul(mod, mod, x);
			temp *= 2;
		}
		if (mod != x - 1 && temp % 2 == 0)return false;
	}
	return true;
}

//�� �G���g�X�e�l�X���
//n�ȉ��̐�������f���������������肵��is_prime[]�Ɋi�[
void eratos(int n, bool is_prime[]) {
	fill(is_prime, is_prime + n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++)
		if (is_prime[i]) {
			int j = i + i;
			while (j <= n) {
				is_prime[j] = false;
				j += i;
			}
		}
}

//�G���g�X�e�l�X���
vector<char> eratos(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++)
		if (is_prime[i]) {
			int j = i + i;
			while (j <= n) {
				is_prime[j] = false;
				j += i;
			}
		}
	return is_prime;
}
//�߂�l: n�ȉ��̑f��
vector<int> get_primes(int n) {
	vector<char> is_prime = eratos(n);
	vector<int> primes;
	for (int i = 0; i < n + 1; i++)
		if (is_prime[i])
			primes.emplace_back(i);
	return primes;
}
//�f��������
vector<int> prime_factorization(int x) {
	vector<int> primes = get_primes(sqrt(x)); //��x�ȉ��̑f���ɂ��Ē��ׂ�Ηǂ�
	vector<int> factors;
	for (auto &p : primes) {
		while (x%p == 0) {
			x /= p;
			factors.emplace_back(p);
		}
	}
	if (x != 1)factors.emplace_back(x);
	return factors;
}

//�ő����
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//�ő���� ������
int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}
//�ŏ����{��
int lcm(int x, int y) { return x*y / gcd(x, y); }
//�ŏ����{�� ������
int lcm(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = lcm(ret, v[i]);
	return ret;
}

//�g�����[�N���b�h�̌ݏ��@
//ax+by=gcd(a,b) �𖞂��� x, y �����߂�
//http://mathtrain.jp/euclid (�ꎟ�s��������ւ̉��p)
int extgcd(int a, int b, int &x, int &y) {
	int g = a; x = 1; y = 0;
	if (b != 0) {
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

//�񐔂����߂� ���\�[�g
vector<int> divisor(int x) {
	vector<int> ret;
	int i;
	for (i = 1; i*i < x; i++) {
		if (x%i)continue;
		ret.emplace_back(i);
		ret.emplace_back(x / i);
	}
	if (i*i == x)ret.emplace_back(i);
	return ret;
}

//�I�C���[�̃ӊ֐��iEuler's totient function�j
//n�ƌ݂��ɑf�Ȑ�[1,n]�̌�
//http://mathtrain.jp/phi
int euler_totient(int n) {
	int ret = n;
	for (int x = 2; x*x <= n; x++) {
		if (n%x)continue;
		ret -= ret / x;
		while (n%x == 0)n /= x;
	}
	if (n != 1)ret -= ret / n;
	return ret;
}

//�p�X�J���̎O�p�`��n�i��
vector<int> pascal_triangle(int n) {
	vector<int> a(n, 1), b(n, 1);
	//3�i�ڂ���n�i�ڂ܂Ōv�Z
	for (int i = 3; i < n + 1; i++) {
		swap(a, b);
		a[0] = 1; a[i - 1] = 1;
		for (int j = 1; j < i - 1; j++)
			a[j] = b[j - 1] + b[j];
	}
	return a;
}

//n�i�@
//Radix r("0123456789abcdef");
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0208
class Radix {
private:
	const char* s;
	int a[128];
public:
	Radix(const char* s = "0123456789ABCDEF") : s(s) {
		for (int i = 0; s[i]; i++) a[(int)s[i]] = i;
	}
	//10�i���� �� n�i�@������
	string format(long long x, int n) {
		if (!x) return "0";
		char t[64] = {};
		int i;
		for (i = 62; x; i--) {
			t[i] = s[x % n];
			x /= n;
		}
		return string(t + i + 1);
	}
	//m�i�@������ �� n�i�@������
	string format(const string &t, int m, int n) {
		return format(format(t, m), n);
	}
	//m�i�@������ �� 10�i����
	long long format(const string &t, int m) {
		long long sm = a[(int)t[0]];
		for (int i = 1; i < (int)t.length(); i++)
			sm = sm * m + a[(int)t[i]];
		return sm;
	}
};

#include "Geometry.cpp"
//mod(double)
double modulo(double x, double mod) {
	x -= floor(x / mod)*mod;
	if (x<EPS || x + EPS>mod)x = 0;
	return x;
}

//�ŏ��񕉏�](c/c++�͐�Βl�ŏ���])
int modulo(int x, int mod) {
	return (x%mod < 0) ? x%mod + abs(mod) : x%mod;
}