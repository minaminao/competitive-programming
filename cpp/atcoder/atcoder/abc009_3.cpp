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

string solve(int K, string s) {
	int N = s.size();
	vector<bool> f(N);
	rep(i, 0, N) {
		char m = s[i];
		int k = -1;
		rrep(j, i + 1, N) {
			if (K == 0 && !(f[i] && f[j]))continue;
			if (K == 1 && !(f[i] || f[j]))continue;
			if (chmin(m, s[j])) {
				k = j;
			}
			else if (m == s[j] && s[i] != s[j] && f[j]) {
				k = j;
			}
		}
		if (k == -1)continue;
		if (!f[i])K--;
		if (!f[k])K--;
		f[i] = f[k] = true;
		swap(s[i], s[k]);
	}
	return s;
}

string solve2(int K, string s) {
	int N = s.size();
	string t = s;
	sort(all(t));
	do {
		int k = 0;
		rep(i, 0, N) {
			if (s[i] != t[i])k++;
		}
		if (k > K)continue;
		return t;
	} while (next_permutation(all(t)));
}

string random(size_t N) {
	string res;
	for (auto i = 0; i < N; i++)
		res.push_back('a' + rand() % 26);
	return res;
}

//‹ð’¼‰ð‚Æ‚Ì”äŠr
template<class F>
void diff(F f1, F f2) {
	static const int N = 5;
	for (int i = 0; i < 1000; i++) {
		string s = random(N);
		for (int k = 0; k < N; k++) {
			string res1 = solve(k, s), res2 = solve2(k, s);
			if (res1 == res2)continue;
			dump(s, k, res1, res2);
		}
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int N, K; cin >> N >> K;) {
		string s; cin >> s;
		cout << solve(K, s) << endl;
	}
	//diff(solve, solve2);
	return 0;
}