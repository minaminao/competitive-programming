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
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	int NA, NB; cin >> NA >> NB;
	unordered_map<int, int> cnt;
	vector<int> A(NA); rep(i, 0, NA) {
		cin >> A[i];
		cnt[A[i]]++;
	}
	vector<int> B(NB); rep(i, 0, NB) {
		cin >> B[i];
		cnt[B[i]]++;
	}
	int a = 0;
	for (auto &e : cnt) {
		if (e.second == 2)a++;
	}
	cout << (double)a / cnt.size() << endl;
	return 0;
}