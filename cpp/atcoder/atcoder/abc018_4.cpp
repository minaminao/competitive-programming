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

//population count
//—§‚Á‚Ä‚¢‚ébit‚Ì”‚ð”‚¦‚é
int popcount(int x) {
	int ret = 0;
	//Œã‚ë‚©‚ç—§‚Á‚Ä‚¢‚ébit‚ð~‚ë‚·
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	int P, Q, R; cin >> P >> Q >> R;
	vector<int> x(R), y(R), z(R); rep(i, 0, R) {
		cin >> x[i] >> y[i] >> z[i];
		x[i]--, y[i]--;
	}

	int ans = 0;
	for (int mask = 0; mask < (1 << N); mask++) {
		if (popcount(mask) != P)continue;
		vector<int> sum(M);
		rep(i, 0, R) {
			if ((mask >> x[i]) & 1) {
				sum[y[i]] += z[i];
			}
		}
		sort(all(sum), greater<int>());
		int tmp = 0;
		rep(i, 0, Q) {
			tmp += sum[i];
		}
		chmax(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}