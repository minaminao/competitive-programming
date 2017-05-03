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

const double PI = acos(-1);

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.txt", "w", stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	cout << fixed << setprecision(10);
	for (int t = 0; t < T; t++) {
		int N, K; cin >> N >> K;
		vector<int> R(N), H(N); rep(i, 0, N) {
			cin >> R[i] >> H[i];
		}
		vector<double> a(N);
		rep(i, 0, N) {
			a[i] = 2.0 * R[i] * PI * H[i];
		}
		tied_sort(a, R, H);
		//dump(a, R, H);
		double ans = 0;
		rep(i, 0, N) {
			//dump(i);
			int k = 1;
			double area = 0;
			area += R[i] * R[i] * PI;
			area += a[i];
			rrep(j, 0, N) {
				if (i == j)continue;
				if (k < K&&R[j] <= R[i]) {
					k++;
					area += a[j];
					//dump(j, a[j]);
				}
			}
			//dump(area);
			chmax(ans, area);
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;

	}
	return 0;
}