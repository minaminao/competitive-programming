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
	int N, R; cin >> N >> R;
	string S; cin >> S;
	while (S.size() && S.back() == 'o')S.pop_back();
	int ans = 0;
	if (S.size() && S.back() == '.') {
		for (int i = 0; S.size() && i < R - 1; i++)S.pop_back();
		ans++;
		S.back() = 'o';
	}
	ans += max(0, (int)S.size() - 1);
	dump(ans, S);
	while (S.size()) {
		if (S.back() == '.') {
			for (int i = 0; S.size() && i < R - 1; i++)S.pop_back();
			ans++;
			if (S.size())S.back() = 'o';
		}
		if (S.size())S.pop_back();
	}
	dump(ans);
	cout << ans << endl;
	return 0;
}