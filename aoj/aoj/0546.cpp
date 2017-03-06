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
	for (int N; cin >> N&&N;) {
		int K; cin >> K;
		unordered_set<string> st;
		vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
		for (int mask = 1; mask < (1 << N); mask++) {
			if (popcount(mask) != K)continue;
			vector<int> base;
			rep(i, 0, N) {
				if ((mask >> i) & 1) {
					base.emplace_back(v[i]);
				}
			}
			sort(all(base));
			do {
				string tmp = "";
				rep(i, 0, K) {
					tmp += to_string(base[i]);
				}
				st.insert(tmp);
			} while (next_permutation(all(base)));
		}
		cout << st.size() << endl;
	}
	return 0;
}