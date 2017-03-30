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

//—v‘f‚ªŒÝ‚¢‚ÉˆÙ‚È‚é•”•ª—ñ‚Ì’·‚³ r-l ‚ÌÅ‘å’l
int sliding_window(const vector<int> &a) {
	int n = a.size(), l = 0, r = 0;
	int ret = 0;
	unordered_set<int> st;
	while (l < n) {
		if (r == n) {
			break;
		}
		//‹æŠÔ‚ð‹·‚ß‚é
		else if (st.count(a[r])) {
			st.erase(a[l]);
			if (l == r) {
				l++, r++;
			}
			else {
				a[l];
				l++;
			}
		}
		//‹æŠÔ‚ðL‚°‚é
		else {
			st.emplace(a[r]);
			r++;
		}
		chmax(ret, r - l);
	}
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> A(N); rep(i, 0, N) { cin >> A[i]; }
	cout << sliding_window(A) << endl;
	return 0;
}