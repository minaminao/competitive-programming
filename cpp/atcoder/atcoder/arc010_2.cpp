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

//ƒƒCƒ“•”•ª‚Íˆê‰žsmallCheck‚µ‚½
//offset: <http://fuka5.contest.atcoder.jp/submissions/134493>
struct Date {
	typedef int Integer; Integer offset;
	static const int days[12], dayscumsum[13], dayscumsuml[13];
	struct YMD {
		Integer Y; int M, D;
		YMD(Integer Y_, int M_, int D_) : Y(Y_), M(M_), D(D_) { }
	};
	Date() : offset(0) { }
	explicit Date(Integer offset_) : offset(offset_) { }
	Date(Integer Y, int M, int D) : offset(toOffset(Y, M, D)) { }

	static bool isLeapYear(Integer Y) {
		return Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0);
	}
	static int getDays(int Y, int M) {
		return days[M - 1] + (M == 2 && isLeapYear(Y));
	}
	static Integer toOffset(int y, int m, int d) {
		if (m <= 2) y--, m += 12;
		return y * 365 + div(y, 4) - div(y, 100) + div(y, 400) + 153 * (m + 1) / 5 + d - 428;
	}
	void getYearMonthDay(Integer &Y, int &M, int &D) const {
		Integer a = offset - 1, quadcent = div(a, 146097);
		Integer b = a - quadcent * 146097, cent = min(b / 36524, Integer(3));
		Integer c = b - cent * 36524, quad = c / 1461;
		Integer d = c - quad * 1461, y = min(d / 365, Integer(3));
		Y = quadcent * 400 + cent * 100 + quad * 4 + y + 1;
		int yd = (int)(d - y * 365 + 1);
		fromOrdinalDate(Y, yd, M, D);
	}
	static void fromOrdinalDate(const Integer &Y, int yd, int &M, int &D) {
		const int *cumsum = isLeapYear(Y) ? dayscumsuml : dayscumsum;
		M = upper_bound(cumsum, cumsum + 13, yd - 1) - cumsum;
		D = yd - cumsum[M - 1];
	}

	Integer getYear() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return Y; }
	int getMonth() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return M; }
	int getDay() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return D; }
	int getDayOfWeek() const { return offset % 7; }

	Date operator+(Integer that) const { return Date(offset + that); }
	Date &operator+=(Integer that) { offset += that; return *this; }
	Integer operator-(const Date &that) const { return offset - that.offset; }

	bool operator==(const Date &that) const { return offset == that.offset; }
	bool operator!=(const Date &that) const { return offset != that.offset; }
	bool operator< (const Date &that) const { return offset < that.offset; }
	bool operator> (const Date &that) const { return offset > that.offset; }
	bool operator<=(const Date &that) const { return offset <= that.offset; }
	bool operator>=(const Date &that) const { return offset >= that.offset; }

	friend ostream &operator<<(ostream &o, const Date &that) {
		Date::Integer Y; int M, D; that.getYearMonthDay(Y, M, D);
		return o << Y << "/" << M << "/" << D;
	}
private:
	static inline Integer div(Integer x, int y) { return x / y - (x % y != 0 && x < 0); };
};
const int Date::days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int Date::dayscumsum[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
const int Date::dayscumsuml[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };

//delimiter‚Ì˜A‘± ‚Æ —¼˜e‚Ìdelimiter ‚Í–³Ž‹
vector<string> split(const string &input, const char &delimiter) {
	vector<string> ret;
	string w;
	for (const char &c : input) {
		if (c == delimiter) {
			if (w.size())ret.emplace_back(w);
			w.clear();
		}
		else w += c;
	}
	if (w.size())ret.emplace_back(w);
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	Date a(2012, 1, 1); //sunday
	int N; cin >> N;
	int f[410] = {};
	f[0]++;
	for (int i = 6; i < 400; i += 7) {
		f[i]++;
		f[i + 1]++;
	}
	rep(i, 0, N) {
		string s; cin >> s;
		vector<string> v = split(s, '/');
		Date b(2012, stoi(v[0]), stoi(v[1]));
		f[b - a]++;
	}
	rep(i, 0, 400) {
		dump(i, f[i]);
	}
	int tmp = 0;
	rep(i, 0, 400) {
		if (f[i] > 1) {
			tmp += f[i] - 1;
			f[i] = 1;
		}
		else if (f[i] == 0 && tmp > 0) {
			f[i] = 1;
			tmp--;
		}
	}
	rep(i, 0, 400) {
		if (f[i + 1])f[i + 1] += f[i];
	}
	int ans = *max_element(f, f + 366);
	cout << ans << endl;
	return 0;
}