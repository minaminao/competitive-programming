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

bool p[5010][5010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	auto inrange = [&](int i, int j) { return i >= 0 && i < 5010 && j >= 0 && j < 5010; };
	for (int N; cin >> N&&N;) {
		vector<int> x(N), y(N); rep(i, 0, N) {
			cin >> x[i] >> y[i];
			p[x[i]][y[i]] = true;
		}
		int ans = 0;
		rep(i, 0, N)rep(j, i + 1, N) {
			int dx = x[i] - x[j],
				dy = y[i] - y[j];
			if (inrange(x[i] - dy, y[i] + dx) &&
				p[x[i] - dy][y[i] + dx] &&
				inrange(x[j] - dy, y[j] + dx) &&
				p[x[j] - dy][y[j] + dx]) {
				chmax(ans, dx*dx + dy*dy);
			}
			if (inrange(x[i] + dy, y[i] - dx) &&
				p[x[i] + dy][y[i] - dx] &&
				inrange(x[j] + dy, y[j] - dx) &&
				p[x[j] + dy][y[j] - dx]) {
				chmax(ans, dx*dx + dy*dy);
			}
		}
		cout << ans << endl;
	}
	return 0;
}