#include "NumberTheory.cpp"
#include "Bit.cpp"
#include "ModInt.cpp"

//1+2+...+n
mint arithsum(int n) {
	return (mint)n*(n + 1) / 2;
}

//gcd(a, K) = 1, a <= N ‚ð–ž‚½‚· a ‚Ì‘˜a
mint solve(int N, int K) {
	vector<int> factors = prime_factorization(K);
	factors.erase(unique(factors.begin(), factors.end()), factors.end());
	int n = factors.size();
	mint ret = arithsum(N);
	rep(mask, 1, 1 << n) {
		int x = 1;
		rep(i, 0, n)
			if (mask >> i & 1)
				x *= factors[i];
		if (popcount(mask) & 1)
			ret -= arithsum(N / x)*x;
		else
			ret += arithsum(N / x)*x;
	}
	return ret;
}

//gcd(a, K) = g, a <= N ‚ð–ž‚½‚· a ‚Ì‘˜a
mint solve(int N, int K, int g) {
	if (K%g)return 0;
	return solve(N / g, K / g)*g;
}