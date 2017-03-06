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

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Int = mp::cpp_int;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, a; cin >> N >> a; a--;
	Int k; cin >> k;
	vector<int> b(N); rep(i, 0, N) { cin >> b[i]; b[i]--; }
	dump(b);
	vector<int> loop = { a };
	unordered_set<int> st;
	while (!st.count(loop.back())) {
		if (loop.size() > k) {
			cout << loop.back() + 1 << endl;
			return 0;
		}
		st.insert(loop.back());
		loop.emplace_back(b[loop.back()]);
		dump(loop);
	}
	rep(i, 0, loop.size()) {
		if (loop[i] == loop.back()) {
			loop.erase(loop.end() - 1);
			loop.erase(loop.begin(), loop.begin() + i);
			k -= i;
			break;
		}
	}
	dump(loop);
	dump(k);
	cout << loop[(int)(k%loop.size())] + 1 << endl;
	return 0;
}