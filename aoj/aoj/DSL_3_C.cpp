#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

//a_l + a_l+1 + ... + a_r-1 <= x ‚ð–ž‚½‚· [l, r) ‚ÌŒÂ” 
int number_of_windows(const vector<int> &a, int x) {
	int n = a.size(), l = 0, r = 0;
	int num = 0;
	int sum = 0;
	while (l < n) {
		if (r == n || sum + a[r] > x) {
			if (l == r) {
				l++, r++;
			}
			else {
				num += r - l;
				sum -= a[l];
				l++;
			}
		}
		else {
			sum += a[r];
			r++;
		}
	}
	return num;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q; cin >> N >> Q;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	rep(i, 0, Q) {
		int x; cin >> x;
		dump(x);
		cout << number_of_windows(a, x) << endl;
	}
	return 0;
}