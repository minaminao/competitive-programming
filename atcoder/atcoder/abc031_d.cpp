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

int K, N;
int pow3[11] = { 1 };
vector<int> len;
vector<string> t;
string v[55], w[55];

bool f(int mask) {
	fill(t.begin(), t.end(), "");
	rep(i, 0, K)len[i] = (mask / pow3[i]) % 3 + 1;
	dump(len);
	rep(i, 0, N) {
		int l = 0;
		rep(j, 0, v[i].size()) {
			int idx = v[i][j] - '1';
			if (l + len[idx] > w[i].size()) {
				return false;
			}
			if (t[idx].size()) {
				if (t[idx] != string(w[i].begin() + l, w[i].begin() + l + len[idx])) {
					return false;
				}
			}
			else {
				t[idx] = string(w[i].begin() + l, w[i].begin() + l + len[idx]);
			}
			l += len[idx];
		}
		if (l != w[i].size())return false;
	}
	return true;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> K >> N;
	rep(i, 0, N) { cin >> v[i] >> w[i]; }
	rep(i, 0, K)pow3[i + 1] = pow3[i] * 3;
	len.resize(K);
	t.resize(K);
	for (int mask = 0; mask < pow3[K]; mask++) {
		if (f(mask)) {
			rep(i, 0, K) {
				cout << t[i] << endl;
			}
			break;
		}
	}
	return 0;
}