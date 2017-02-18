//by anta

using Num = unsigned long long;
struct Matrix {
	vector<vector<Num>> v, w;
	Matrix() {}
	Matrix(int n, int m) :v(n, vector<Num>(m)) { }
	inline int height()const { return (int)v.size(); }
	inline int width()const { return (int)v[0].size(); }
	inline Num& at(int i, int j) { return v[i][j]; }
	inline const Num& at(int i, int j)const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		for (int i = 0; i < n; i++) A.at(i, i) = 1;
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	Matrix &operator*=(const Matrix& B) {
		int n = height(), m = B.width(), p = B.height();
		assert(p == width());
		w.assign(n, vector<Num>(m, 0));
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
			Num x = 0;
			for (int k = 0; k < p; k++)
				x += at(i, k) * B.at(k, j);
			w[i][j] = x;
		}
		v.swap(w);
		return *this;
	}
};
Matrix operator^(const Matrix &m, long long exponent) {
	Matrix A = m, B = Matrix::identity(m);
	while (exponent) {
		if (exponent & 1) B *= A;
		A *= A;
		exponent >>= 1;
	}
	return B;
}