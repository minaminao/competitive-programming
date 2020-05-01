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

//a_l + a_l+1 + ... + a_r-1 >= S ‚Æ‚È‚é•”•ª—ñ‚Ì’·‚³ r-l ‚ÌÅ¬’l
int smallest_window(const vector<int> &a, int S) {
	int n = a.size(), l = 0, r = 0;
	int sum = 0;
	int ret = INF;
	while (l < n) {
		if (r == n) {
			sum -= a[l];
			l++;
		}
		else if (sum + a[r] >= S) {
			chmin(ret, r + 1 - l);
			if (l == r) {
				l++, r++;
			}
			else {
				sum -= a[l];
				l++;
			}
		}
		else {
			sum += a[r];
			r++;
		}
	}
	return ret == INF ? 0 : ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, S; cin >> N >> S;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	cout << smallest_window(a, S) << endl;
	return 0;
}