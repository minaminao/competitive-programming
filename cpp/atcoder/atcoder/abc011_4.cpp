#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

//nCr配列をパスカルの三角形から生成
//double なら 10^308 くらいまでOK
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
//確率版
//i段目の和は必ず1.0
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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	int N, D; cin >> N >> D;
	int X, Y; cin >> X >> Y;
	if (X%D || Y%D) {
		cout << 0 << endl;
		return 0;
	}
	X /= D; Y /= D;
	compute_nCr_probability(N);
	double ans = 0;
	//i回左右に動くとする
	rep(lr, 0, N + 1) {
		if ((lr - X) % 2 || lr - X < 0)continue;
		int l = (lr - X) / 2;
		int r = lr - l;
		int ud = N - lr;
		if ((ud - Y) % 2 || ud - Y < 0)continue;
		int d = (ud - Y) / 2;
		int u = ud - d;
		if (l < 0 || r < 0 || u < 0 || d < 0)continue;
		ans += nCr[N][lr] * nCr[lr][l] * nCr[ud][u];
	}
	cout << ans << endl;
	return 0;
}