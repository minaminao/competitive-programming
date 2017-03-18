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

int N, Q;
bool f(char a, char b) {
	if (Q == 0)return true;
	cout << "? " << a << " " << b << endl;
	char c; cin >> c;
	Q--;
	return c == '<';
}

template <class It>
bool f(It a, It b) {
	cout << "? " << *a << " " << *b << endl;
	char c; cin >> c;
	return c == '<';
}

template <class It>
void merge(It l, It m, It r) {
	using T = typename iterator_traits<It>::value_type;
	vector<T> tmp(r - l);
	It it = tmp.begin(), it1 = l, it2 = m;
	while (it1 != m && it2 != r) {
		if (f(it1, it2))
			*it++ = *it1++;
		else
			*it++ = *it2++;
	}
	while (it1 != m) *it++ = *it1++;
	while (it2 != r) *it++ = *it2++;
	move(tmp.begin(), tmp.end(), l);
};

template <class It>
void merge_sort(It l, It r) {
	if (r - l <= 1)return;
	It m = l + (r - l) / 2;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, m, r);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> Q;
	vector<char> v(N);
	auto a = v.begin();
	iota(v.begin(), v.end(), 'A');
	merge_sort(v.begin(), v.end());
	cout << "! ";
	rep(i, 0, N)cout << v[i];
	cout << endl;
	return 0;
}