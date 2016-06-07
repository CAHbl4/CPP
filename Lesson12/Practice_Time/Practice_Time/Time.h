#pragma once
#include <iomanip>

class Time {
	int hour;
	int min;
	int sec;
public:
	Time(int h = 0, int m = 0, int s = 0) {
		hour = 0;
		min = 0;
		sec = 0;
		AddSec(s);
		AddMin(m);
		AddHour(h);
	}


	void AddHour(int val) {
		hour = (hour + val) % 24;
	}


	void AddMin(int val) {
		if (val < 0) {
			if (min + val < 0) {
				AddHour(-1);
				min = 60 + (min + val);
			}
			else
				min = min + val;
		}
		else {
			AddHour((min + val) / 60);
			min = (min + val) % 60;
		}
	}


	void AddSec(int val) {
		if (val < 0) {
			if (sec + val < 0) {
				AddMin(-1);
				sec = 60 +(sec + val);
			}
			else
				sec = sec + val;
		}
		else {
			AddMin((sec + val) / 60);
			sec = (sec + val) % 60;
		}
	}


	Time& operator++() {
		AddSec(1);
		return *this;
	}


	Time operator++(int) {
		Time tmp(*this);
		AddHour(1);
		return tmp;
	}


	Time& operator--() {
		AddMin(-1);
		return *this;
	}


	Time operator--(int) {
		Time tmp(*this);
		AddMin(-1);
		return tmp;
	}


	Time operator+(const Time& rval) const {
		Time tmp(*this);
		tmp.AddSec(rval.sec);
		tmp.AddMin(rval.min);
		tmp.AddHour(rval.hour);
		return tmp;
	}


	Time operator-(const Time& rval) const {
		Time tmp(*this);
		tmp.AddSec(-rval.sec);
		tmp.AddMin(-rval.min);
		tmp.AddHour(-rval.hour);
		return tmp;
	}


	friend bool operator==(const Time& lval, const Time& rval) {
		return lval.hour == rval.hour
			&& lval.min == rval.min
			&& lval.sec == rval.sec;
	}


	friend bool operator!=(const Time& lval, const Time& rval) {
		return !(lval == rval);
	}


	operator int() const {
		return hour * 24 * 60 + min * 60 + sec;
	}


	friend ostream& operator<<(ostream& os, const Time& obj) {
		if (obj.hour < 0 || obj.min < 0 || obj.sec < 0)
			os << "-";

		os << setfill('0') << setw(2)
			<< abs(obj.hour) << ":"
			<< setfill('0') << setw(2)
			<< abs(obj.min) << ":"
			<< setfill('0') << setw(2)
			<< abs(obj.sec) << endl;
		return os;
	}


	~Time();
};
