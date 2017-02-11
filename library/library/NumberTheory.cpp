//素数判定
bool is_prime(int x) {
	if (x <= 1)return false;
	else if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return false;
	return true;
}

//高速累乗 繰り返し自乗法
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
//素数判定（Miller-Rabin primality test）2^24程度から
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

//旧 エラトステネスの篩
//n以下の正整数を素数か合成数か判定してis_prime[]に格納
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

//エラトステネスの篩
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
//戻り値: n以下の素数
vector<int> get_primes(int n) {
	vector<char> is_prime = eratos(n);
	vector<int> primes;
	for (int i = 0; i < n + 1; i++)
		if (is_prime[i])
			primes.emplace_back(i);
	return primes;
}
//素因数分解
vector<int> prime_factorization(int x) {
	vector<int> primes = get_primes(sqrt(x)); //√x以下の素数について調べれば良い
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

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//最大公約数 複数個
int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}
//最小公倍数
int lcm(int x, int y) { return x*y / gcd(x, y); }
//最小公倍数 複数個
int lcm(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = lcm(ret, v[i]);
	return ret;
}

//拡張ユークリッドの互除法
//ax+by=gcd(a,b) を満たす x, y を求める
//http://mathtrain.jp/euclid (一次不定方程式への応用)
int extgcd(int a, int b, int &x, int &y) {
	int g = a; x = 1; y = 0;
	if (b != 0) {
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

//約数を求める 未ソート
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

//オイラーのφ関数（Euler's totient function）
//nと互いに素な数[1,n]の個数
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

//パスカルの三角形のn段目
vector<int> pascal_triangle(int n) {
	vector<int> a(n, 1), b(n, 1);
	//3段目からn段目まで計算
	for (int i = 3; i < n + 1; i++) {
		swap(a, b);
		a[0] = 1; a[i - 1] = 1;
		for (int j = 1; j < i - 1; j++)
			a[j] = b[j - 1] + b[j];
	}
	return a;
}

//n進法
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
	//10進整数 → n進法文字列
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
	//m進法文字列 → n進法文字列
	string format(const string &t, int m, int n) {
		return format(format(t, m), n);
	}
	//m進法文字列 → 10進整数
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

//最小非負剰余(c/c++は絶対値最小剰余)
int modulo(int x, int mod) {
	return (x%mod < 0) ? x%mod + abs(mod) : x%mod;
}