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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, D; cin >> N >> M >> D;
	vector<int> A(M); rep(i, 0, M) { cin >> A[i]; }

	vector<int> a(N);
	iota(a.begin(), a.end(), 0);
	dump(a);
	rep(i, 0, M) {
		swap(a[A[i] - 1], a[A[i]]);
	}
	dump(a);

	vector<vector<int>> p = { a };
	rep(i, 0, 32) {
		vector<int> add(N);
		rep(j, 0, N) {
			add[j] = p.back()[p.back()[j]];
		}
		p.emplace_back(add);
		dump(add);
	}

	iota(a.begin(), a.end(), 0);
	while (D > 0) {
		int idx = log2(D);
		vector<int> tmp(N);
		rep(i, 0, N) {
			tmp[i] = a[p[idx][i]];
		}
		swap(a, tmp);
		D -= pow(2, idx);
		dump(D);
	}
	vector<int> ans(N);
	rep(i, 0, N) {
		ans[a[i]] = i + 1;
	}
	rep(i, 0, N) {
		cout << ans[i] << endl;
	}
	return 0;
}