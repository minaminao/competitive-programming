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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//population count
//�����Ă���bit�̐��𐔂���
int popcount(int x) {
	int ret = 0;
	//��납�痧���Ă���bit���~�낷
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}
signed main() {
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	vector<int> sum;
	for (int i = 0; i < (1 << 5); i++) {
		if (popcount(i) != 3)continue;
		int tmp = 0;
		if (i&(1 << 0))tmp += a;
		if (i&(1 << 1))tmp += b;
		if (i&(1 << 2))tmp += c;
		if (i&(1 << 3))tmp += d;
		if (i&(1 << 4))tmp += e;
		sum.emplace_back(tmp);
	}
	sort(all(sum), greater<int>());
	cout << sum[2] << endl;
	return 0;
}