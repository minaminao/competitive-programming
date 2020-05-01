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
	int A, B; cin >> A >> B;
	vector<int> a(A); rep(i, 0, A) { cin >> a[i]; }
	vector<int> b(B); rep(i, 0, B) { cin >> b[i]; }
	int ans = 0;
	rep(i, 0, B){
		int ii = i;
		rep(j, 0, A) {
			if (b[ii] == a[j]) {
				ii++;
				if (ii == B)break;
			}
		}
		chmax(ans, ii - i);
	}
	cout << ans << endl;
	return 0;
}