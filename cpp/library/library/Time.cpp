class Time {
private:
	int time(int hours = 0, int minutes = 0, int seconds = 0) { return hours * 3600 + minutes * 60 + seconds; }
public:
	int t;
	Time(int time = 0) :t(time) {}
	Time(int hours, int minutes, int seconds = 0) : t(time(hours, minutes, seconds)) {}
	Time(const string &hhmm) {
		int hours = stoi(hhmm.substr(0, 2));
		int minutes = stoi(hhmm.substr(hhmm.size() - 2, 2));
		t = time(hours, minutes);
	}

	Time operator+(const Time &that) const { return Time(t + that.t); }
	Time operator-(const Time &that) const { return Time(t - that.t); }
	Time &operator+=(const Time &that) { t += that.t; return *this; }
	Time &operator-=(const Time &that) { t -= that.t; return *this; }
	bool operator==(const Time &that) const { return t == that.t; }
	bool operator<(const Time &that) const { return t < that.t; }

	int hours() { return t / 3600; }
	int minutes() { return (t % 3600) / 60; }
	int seconds() { return t % 60; }
	string hh() {
		ostringstream os;
		os << setw(2) << setfill('0') << hours();
		return os.str();
	}
	string mm() {
		ostringstream os;
		os << setw(2) << setfill('0') << minutes();
		return os.str();
	}
	string ss() {
		ostringstream os;
		os << setw(2) << setfill('0') << seconds();
		return os.str();
	}
};