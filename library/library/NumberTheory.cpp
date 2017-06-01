#include "ModInt.cpp"

/*

�v�Z�ʂ𗎂Ƃ�

gcd(x%y,y) == gcd(x,y)
y�̐����������Ƃ��Agcd(x%y,y) �̒l�ŏꍇ����

�񐔂̌� N<=10^9 �̂Ƃ� ���X1344��
�f�����̌� N<=10^9 �̂Ƃ� ���X9��

*/

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

//�ő����
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//�ŏ����{��
int lcm(int x, int y) { return x*y / gcd(x, y); }
//�ő���� ������
int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}
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
long long extgcd(long long a, long long b, long long &x, long long &y) {
	long long g = a; x = 1; y = 0;
	if (b != 0) {
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

const double EPS = 1e-8;
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

//�����ݏ� �J��Ԃ�����@
//�I�[�o�[�t���[����\��������Ί|���Z��modmul()���g��
long long modpow(long long base, long long exponent, long long mod) {
	long long res = 1;
	while (exponent > 0) {
		if (exponent & 1)res = res * base % mod;
		base = base * base % mod;
		exponent >>= 1;
	}
	return res;
}
//(a*b)%mod 
long long modmul(long long a, long long b, long long mod) {
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
		long long mod = modpow(a, temp, x);
		while (temp != x - 1 && mod != 1 && mod != x - 1) {
			mod = modmul(mod, mod, x);
			temp *= 2;
		}
		if (mod != x - 1 && temp % 2 == 0)return false;
	}
	return true;
}

//�t��
//xy%m=1, y<m �ƂȂ�y�����߂�
long long modinv(long long x, long long m) {
	long long s, t;
	extgcd(x, m, s, t);
	return (s + m) % m;
}

//�f������
bool is_prime(int x) {
	if (x <= 1)return false;
	else if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return false;
	return true;
}

//1�͍������ł͂Ȃ�
//1+�f��+������

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
//�f�������� ����
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


//�I�C���[�̃ӊ֐��iEuler's totient function�j
//n�ƌ݂��ɑf�Ȑ�[1,n]�̌�
//http://mathtrain.jp/phi
int euler_totient(int n) {
	int ret = n;
	for (int x = 2; x*x <= n; x++) {
		if (n%x)continue;
		ret -= ret / x;
		while (n%x == 0)
			n /= x;
	}
	if (n != 1)
		ret -= ret / n;
	return ret;
}

//nCr�z����p�X�J���̎O�p�`���琶��
//double �Ȃ� 10^308 ���炢�܂�OK
using Num = double;
vector<vector<Num>> nCr;
void compute_nCr(int n) {
	vector<Num> a(1, 1), b(2, 1);
	nCr = { a,b };
	for (int i = 3; i <= n + 1; i++) {
		swap(a, b);
		b.resize(i);
		b[0] = 1; b[i - 1] = 1;
		for (int j = 1; j < i - 1; j++)
			b[j] = a[j - 1] + a[j];
		nCr.emplace_back(b);
	}
}
//�m����
//i�i�ڂ̘a�͕K��1.0
void compute_nCr_probability(int n) {
	vector<Num> a(1, 1.0), b(2, 1.0 / 2.0);
	nCr = { a,b };
	for (int i = 3; i <= n + 1; i++) {
		swap(a, b);
		b.resize(i);
		b.front() = a.front() / 2.0; b.back() = a.back() / 2.0;
		for (int j = 1; j < i - 1; j++)
			b[j] = a[j - 1] / 2.0 + a[j] / 2.0;
		nCr.emplace_back(b);
	}
}

//n�i�@
struct Radix {
	string s;
	int a[128];
	Radix(string s = "0123456789ABCDEF") :s(s) {
		for (int i = 0; i < s.size(); i++)
			a[s[i]] = i;
	}
	//10�i(long long) -> n�i(string)
	string format(long long x, int n, int len = 1) {
		if (!x)return string(len, s[0]);
		string ret;
		for (; x || len > 0; x /= n, len--)
			ret += s[x%n];
		reverse(ret.begin(), ret.end());
		return ret;
	}
	using It = string::iterator;
	//m�i(string) -> n�i(string)
	string format(It l, It r, int m, int n, int len = 1) {
		return format(format(l, r, m), n, len);
	}
	//m�i(string) -> 10�i(long long)
	long long format(It l, It r, int m) {
		long long x = a[*l];
		for (l++; l != r; l++)
			x = x * m + a[*l];
		return x;
	}
};
/*
��1) ������𐔒l�Ƃ��Ĉ��������� 27�i�@ Radix r(" abcdefghijklmnopqrstuvwxyz");
http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=2231361&cid=RitsCamp17Day1
��2) http://arc009.contest.atcoder.jp/submissions/1177495
*/

//L <= x <= R �𖞂��� x �̌�
int number_in_range(const vector<int> &v, int L, int R) {
	return upper_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L);
}

//���� v �̕��ו�
mint number_of_arrangement(vector<int> v) {
	int n = v.size();
	assert(fact.size() >= n);
	mint ret = fact[n];
	unordered_map<int, int> cnt;
	for (auto &e : v)cnt[e]++;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &e : v)ret /= fact[cnt[e]];
	return ret;
}

//�t�B�{�i�b�`����
vector<int> fibonacci(int n) {
	vector<int> v(n);
	v[0] = v[1] = 1;
	rep(i, 0, n - 2)
		v[i + 2] += v[i + 1] + v[i];
	return v;
}

vector<int> compute_pow(int b, int e) {
	vector<int> ret(e);
	ret[0] = 1;
	rep(i, 0, e - 1)ret[i + 1] = ret[i] * b;
	return ret;
}