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
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N; cin >> N;
//	vector<int> a(N); rep(i, 0, N) {
//		cin >> a[i];
//	}
//	sort(all(a));
//	dump(a);
//	if (a.back() - a.front() >= 2) {
//		cout << "No" << endl;
//	}
//	if (a.front() == a.back()) {
//		int base = a.front();
//		bool no1 = false, no2 = false;
//
//		{
//			int w = N / base;
//			vector<int> c(N);
//			rep(i, 0, N) {
//				c[i] = i / w;
//			}
//			dump(c);
//			unordered_set<int> st;
//			rep(i, 1, N) {
//				st.insert(c[i]);
//			}
//			if (st.size() != base)
//				no1 = true;
//			st.clear();
//			rep(i, 0, N - 1) {
//				st.insert(c[i]);
//			}
//			if (st.size() != base)
//				no1 = true;
//		}
//
//		{
//			int w = N / base + 1;
//			vector<int> c(N);
//			rep(i, 0, N) {
//				c[i] = i / w;
//			}
//			dump(c);
//			unordered_set<int> st;
//			rep(i, 1, N) {
//				st.insert(c[i]);
//			}
//			if (st.size() != base)
//				no2 = true;
//			st.clear();
//			rep(i, 0, N - 1) {
//				st.insert(c[i]);
//			}
//			if (st.size() != base)
//				no2 = true;
//		}
//
//		if (!no1 || !no2)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	else {
//		int k = lower_bound(all(a), a.back()) - a.begin();
//		dump(k);
//
//		int base = a.back();
//		bool no1 = false, no2 = false;
//
//		{
//			vector<int> c(N);
//			rep(i, 0, k) {
//					c[i] = i;
//			}
//
//			if (base > k) {
//				int w = (N - k) / (base - k);
//				if (w > 0) {
//					dump(w);
//					rep(i, k, N) {
//						c[i] = (i - k) / w + k;
//					}
//					dump(c);
//					unordered_set<int> st;
//					rep(i, 1, N) {
//						st.insert(c[i]);
//					}
//					if (st.size() != a.front())
//						no1 = true;
//					st.clear();
//					rep(i, 0, N - 1) {
//						st.insert(c[i]);
//					}
//					if (st.size() != a.back())
//						no1 = true;
//					st.clear();
//					rep(i, 0, N) {
//						if (i == k)continue;
//						st.insert(c[i]);
//					}
//					if (st.size() != a[k])
//						no1 = true;
//				}
//				else {
//					no1 = true;
//				}
//			}
//			else {
//				no1 = true;
//			}
//		}
//
//		{
//			vector<int> c(N);
//			rep(i, 0, k) {
//				c[i] = i;
//			}
//
//			if (base > k) {
//				int w = (N - k) / (base - k) + 1;
//				dump(w);
//				if (w > 0) {
//					rep(i, k, N) {
//						c[i] = (i - k) / w + k;
//					}
//					dump(c);
//					unordered_set<int> st;
//					rep(i, 1, N) {
//						st.insert(c[i]);
//					}
//					if (st.size() != a.front())
//						no2 = true;
//					st.clear();
//					rep(i, 0, N - 1) {
//						st.insert(c[i]);
//					}
//					if (st.size() != a.back())
//						no2 = true;
//					st.clear();
//					rep(i, 0, N) {
//						if (i == k)continue;
//						st.insert(c[i]);
//					}
//					if (st.size() != a[k])
//						no2 = true;
//				}
//				else {
//					no2 = true;
//				}
//			}
//			else {
//				no2 = true;
//			}
//		}
//
//		if (!no1 || !no2)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}