//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }
//
//vector<int> compute_pow(int b, int e) {
//	vector<int> ret(e + 1);
//	ret[0] = 1;
//	rep(i, 0, e)ret[i + 1] = ret[i] * b;
//	return ret;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	//freopen("C-small-2-attempt0.in", "r", stdin);
//	//freopen("C-small-2-attempt0.txt", "w", stdout);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	int T; cin >> T;
//	vector<int> pow2 = compute_pow(2, 30);
//	for (int t = 0; t < T; t++) {
//		dump(t);
//		int N; cin >> N;
//		int K; cin >> K;
//		int a = log2(K);
//		dump(a);
//		rep(i, 0, a) {
//			N--;
//			N = N / 2 + (N % 2);
//			dump(N);
//		}
//		N--;
//		int b = N / 2;
//		cout << "Case #" << t + 1 << ": ";
//		cout << N - b << " " << b << endl;
//		//priority_queue<int> pq;
//		//rep(k, 0, K) {
//		//	int a = pq.top(); pq.pop();
//		//	a--;
//		//	int b = a / 2, c = a - b;
//		//	//dump(a, b, c);
//		//	pq.emplace(b);
//		//	pq.emplace(c);
//		//	if (k == K - 1) {
//		//		cout << "Case #" << t + 1 << ": ";
//		//		cout << max(b, c) << " " << min(b, c) << endl;
//		//	}
//		//}
//	}
//	return 0;
//}