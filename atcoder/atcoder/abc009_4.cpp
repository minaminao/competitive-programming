//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//using Num = unsigned long long;
//struct Matrix {
//	vector<vector<Num>> v, w;
//	Matrix() {}
//	Matrix(int n, int m) :v(n, vector<Num>(m)) { }
//	inline int height()const { return (int)v.size(); }
//	inline int width()const { return (int)v[0].size(); }
//	inline Num& at(int i, int j) { return v[i][j]; }
//	inline const Num& at(int i, int j)const { return v[i][j]; }
//	static Matrix identity(int n) {
//		Matrix A(n, n);
//		for (int i = 0; i < n; i++) A.at(i, i) = 1;
//		return A;
//	}
//	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
//	Matrix &operator*=(const Matrix& B) {
//		int n = height(), m = B.width(), p = B.height();
//		assert(p == width());
//		w.assign(n, vector<Num>(m, 0));
//		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
//			Num x = 0;
//			for (int k = 0; k < p; k++)
//				x ^= at(i, k) & B.at(k, j);
//			w[i][j] = x;
//		}
//		v.swap(w);
//		return *this;
//	}
//};
//Matrix operator^(const Matrix &m, long long exponent) {
//	Matrix A = m, B = Matrix::identity(m);
//	while (exponent) {
//		if (exponent & 1) B *= A;
//		A *= A;
//		exponent >>= 1;
//	}
//	return B;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int K, M; cin >> K >> M;
//	vector<int> A(K); rep(i, 0, K) { cin >> A[i]; }
//	vector<int> C(K); rep(i, 0, K) { cin >> C[i]; }
//	Matrix a(K, K);
//	rep(i, 0, K)
//		a.at(0, i) = C[i];
//	rep(i, 0, K - 1)
//		a.at(i + 1, i) = 1;
//	Matrix b(K, 1);
//	rep(i, 0, K)
//		b.at(i, 0) = A[K - i - 1];
//	a = a ^ (M - K);
//	a *= b;
//	rep(i, 0, K)
//		cout << a.at(i, 0) << endl;
//	return 0;
//}