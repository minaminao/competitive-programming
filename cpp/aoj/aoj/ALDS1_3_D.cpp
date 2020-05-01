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
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	string s; cin >> s;
	stack<int> st1;
	stack<pair<int, int>> st2;
	rep(i, 0, s.size()) {
		if (s[i] == '\\') {
			st1.emplace(i);
		}
		else if (s[i] == '/'&&st1.size()) {
			int a = st1.top(); st1.pop();
			int b = i - a + 1;
			int c = (b + b - 2) * 1 / 2;
			while (st2.size() && a < st2.top().first) {
				c += st2.top().second; st2.pop();
			}
			st2.emplace(a, c);
		}
		dump(st1, st2);
	}

	vector<int> L;
	while (st2.size()) {
		L.emplace_back(st2.top().second);
		st2.pop();
	}
	reverse(all(L));
	cout << accumulate(all(L), 0) << endl;
	cout << L.size();
	rep(i, 0, L.size()) {
		cout << " " << L[i];
	}
	cout << endl;
	return 0;
}