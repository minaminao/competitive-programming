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

template<typename T, typename U>
class mymap {
private:
	size_t n;
	vector<T> key;
	vector<U> val;
	U dummy;
	void compress(vector<T> &v) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}
	size_t index(const T &i) {
		auto e = lower_bound(key.begin(), key.end(), i);
		assert(e != key.end() && *e == i);
		return e - key.begin();
	}
public:
	mymap(const vector<T> &key_) :key(key_), dummy() {
		compress(key);
		n = key.size();
		val.assign(n, U());
	}
	bool key_exists(const T &i) {
		auto e = lower_bound(key.begin(), key.end(), i);
		if (e == key.end())
			return false;
		else
			return *e == i;
	}
	U &operator[](const T &i) {
		if (key_exists(i))
			return val[index(i)];
		else {
			dummy = U();
			return dummy;
		}
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, V; cin >> N >> V;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	vector<int> b(N); rep(i, 0, N) { cin >> b[i]; }
	vector<int> c(N); rep(i, 0, N) { cin >> c[i]; }
	vector<int> d(N); rep(i, 0, N) { cin >> d[i]; }
	vector<int>	A, B;
	rep(i, 0, N)rep(j, 0, N) {
		A.emplace_back(a[i] + b[j]);
		B.emplace_back(c[i] + d[j]);
	}
	sort(all(A));
	sort(all(B));
	mymap<int, int> cntA(A), cntB(B);
	rep(i, 0, A.size()) {
		cntA[A[i]]++;
		cntB[B[i]]++;
	}
	A.erase(unique(A.begin(), A.end()), A.end());
	int ans = 0;
	rep(i, 0, A.size()) {
		ans += cntA[A[i]] * cntB[V - A[i]];
	}
	cout << ans << endl;
	return 0;
}