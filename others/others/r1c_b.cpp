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

template<class T, class ...Tail>
void tied_sort(vector<T> &a, vector<Tail>&... tail) {
	int n = a.size();
	using S = tuple<T, Tail...>;
	vector<S> s(n);
	for (int i = 0; i < n; i++)
		s[i] = make_tuple(a[i], tail[i]...);
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		tie(a[i], tail[i]...) = s[i];
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.txt", "w", stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int ans;
		int Ac, Aj; cin >> Ac >> Aj;
		int p[24 * 60 + 1] = {};
		vector<int> C(Ac), D(Ac); rep(i, 0, Ac) {
			cin >> C[i] >> D[i];
			rep(j, C[i], D[i])p[j] += 1;
		}
		vector<int> J(Aj), K(Aj); rep(i, 0, Aj) {
			cin >> J[i] >> K[i];
			rep(j, J[i], K[i])p[j] += 2;
		}
		tied_sort(C, D);
		tied_sort(J, K);

		dump(Ac, Aj);
		dump(C, D);
		dump(J, K);
		//dump(p);
		if (Ac <= 1 && Aj <= 1) {
			ans = 2;
		}
		else if (Ac == 2) {
			if (min(D[1] - C[0], (D[0] + 24 * 60 - C[1])) > 12 * 60)
				ans = 4;
			else
				ans = 2;
		}
		else if (Aj == 2) {
			if (min(K[1] - J[0], (K[0] + 24 * 60 - J[1])) > 12 * 60)
				ans = 4;
			else
				ans = 2;
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;

	}
	return 0;
}