#include "NumberTheory.cpp"
#include "Bit.cpp"
#include "ModInt.cpp"

//2éüå≥ó›êœòa
template<typename T>
struct RectangleSum {
	int H, W;
	vector<vector<T>> sum;
	RectangleSum(vector<vector<T>> v)
		:H(v.size()), W(v.front().size()), sum(H + 1, vector<T>(W + 1)) {
		rep(i, 0, H + 1)rep(j, 0, W + 1) {
			sum[i][j] = (i == 0 || j == 0) ? 0 :
				sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i - 1][j - 1];
		}
	}
	//[si, ti), [sj, tj)
	T get(int si, int sj, int ti, int tj) {
		return sum[ti][tj] - sum[si][tj] - sum[ti][sj] + sum[si][sj];
	}
};
//http://arc025.contest.atcoder.jp/submissions/183410

//2éüå≥imosñ@
struct Imos {
	int X, Y;
	vector<vector<int>> s; //ó›êœòa 1-based
	Imos(const vector<vector<int>> &f) :X(f.size()), Y(f[0].size()), s(X + 1, vector<int>(Y + 1)) {
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				s[x + 1][y + 1] += s[x + 1][y] + s[x][y + 1] - s[x][y] + f[x][y];
	}
	//[x1,x2)Ç©Ç¬[y1,y2)ÇÃfieldÇÃòa
	int sum(int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1]; }
};

//1+2+...+n
mint arithsum(int n) {
	return (mint)n*(n + 1) / 2;
}

//gcd(a, K) = 1, a <= N ÇñûÇΩÇ∑ a ÇÃëçòa
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

//gcd(a, K) = g, a <= N ÇñûÇΩÇ∑ a ÇÃëçòa
mint solve(int N, int K, int g) {
	if (K%g)return 0;
	return solve(N / g, K / g)*g;
}