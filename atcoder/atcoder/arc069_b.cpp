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
	for (int N; cin >> N;) {
		string s; cin >> s;

		vector<int> tmp;
		tmp = vector<int>{ 1,1 };
		rep(i, 1, s.size()) {
			if (tmp[i] == 1) {
				if (s[i] == 'o') {
					tmp.push_back(tmp[i - 1]);
				}
				else {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
			}
			else {
				if (s[i] == 'o') {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
				else {
					tmp.push_back(tmp[i - 1]);
				}
			}
		}
		dump(tmp);
		if (tmp[0] == tmp[N]) {
			bool flag = false;
			if (tmp[0] == 1) {
				if (s[0] == 'o') {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
			}
			else {
				if (s[0] == 'o') {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
			}
			if (flag) {
				rep(i, 0, tmp.size() - 1) {
					if (tmp[i])cout << 'S';
					else cout << 'W';
				}
				cout << endl;
				return 0;
			}
		}

		tmp = vector<int>{ 1,0 };
		rep(i, 1, s.size()) {
			if (tmp[i] == 1) {
				if (s[i] == 'o') {
					tmp.push_back(tmp[i - 1]);
				}
				else {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
			}
			else {
				if (s[i] == 'o') {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
				else {
					tmp.push_back(tmp[i - 1]);
				}
			}
		}
		dump(tmp);
		if (tmp[0] == tmp[N]) {
			bool flag = false;
			if (tmp[0] == 1) {
				if (s[0] == 'o') {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
			}
			else {
				if (s[0] == 'o') {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
			}
			if (flag) {
				rep(i, 0, tmp.size() - 1) {
					if (tmp[i])cout << 'S';
					else cout << 'W';
				}
				cout << endl;
				return 0;
			}
		}

		tmp = vector<int>{ 0,1 };
		rep(i, 1, s.size()) {
			if (tmp[i] == 1) {
				if (s[i] == 'o') {
					tmp.push_back(tmp[i - 1]);
				}
				else {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
			}
			else {
				if (s[i] == 'o') {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
				else {
					tmp.push_back(tmp[i - 1]);
				}
			}
		}
		dump(tmp);
		if (tmp[0] == tmp[N]) {
			bool flag = false;
			if (tmp[0] == 1) {
				if (s[0] == 'o') {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
			}
			else {
				if (s[0] == 'o') {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
			}
			if (flag) {
				rep(i, 0, tmp.size() - 1) {
					if (tmp[i])cout << 'S';
					else cout << 'W';
				}
				cout << endl;
				return 0;
			}
		}

		tmp = vector<int>{ 0,0 };
		rep(i, 1, s.size()) {
			if (tmp[i] == 1) {
				if (s[i] == 'o') {
					tmp.push_back(tmp[i - 1]);
				}
				else {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
			}
			else {
				if (s[i] == 'o') {
					tmp.push_back((tmp[i - 1] + 1) % 2);
				}
				else {
					tmp.push_back(tmp[i - 1]);
				}
			}
		}
		dump(tmp);
		if (tmp[0] == tmp[N]) {
			bool flag = false;
			if (tmp[0] == 1) {
				if (s[0] == 'o') {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
			}
			else {
				if (s[0] == 'o') {
					if (tmp[1] != tmp[N - 1])flag = true;
				}
				else {
					if (tmp[1] == tmp[N - 1])flag = true;
				}
			}
			if (flag) {
				rep(i, 0, tmp.size() - 1) {
					if (tmp[i])cout << 'S';
					else cout << 'W';
				}
				cout << endl;
				return 0;
			}
		}

		cout << -1 << endl;
	}
	return 0;
}