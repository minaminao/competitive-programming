#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int, int>pint;
typedef vector<pint>vpint;

template<typename A, typename B>inline void chmin(A &a, B b) { if (a > b)a = b; }
template<typename A, typename B>inline void chmax(A &a, B b) { if (a < b)a = b; }

const int mod = 1000000007;

int N;
int A[111111];

int mpow(int n, int m) {
	int res = 1;
	while (m) {
		if (m & 1)res = res*n%mod;
		n = n*n%mod;
		m >>= 1;
	}
	return res;
}

int po[111111];

signed main() {
	int T; cin >> T;
	rep(t, T) {
		memset(A, 0, sizeof(A));
		memset(po, 0, sizeof(po));
		cin >> N;
		rep(i, N)cin >> A[i];

		if (N == 1) {
			cout << A[0] << endl;
			continue;
		}

		int ans = 0;
		int luz = 0;

		int inv2 = mpow(2, mod - 2);
		po[0] = 1;
		for (int i = 1; i <= N; i++)po[i] = po[i - 1] * 2 % mod;


		for (int i = N - 1; i >= 0; i--) {
			luz = luz*A[i] % mod;
			if (i != 0)luz = luz*inv2%mod;

			if (i == N - 1 || i == 0)luz = (luz + A[i] * po[N - 2]) % mod;
			else luz = (luz + A[i] * po[N - 3]) % mod;
			ans = (ans + luz) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}