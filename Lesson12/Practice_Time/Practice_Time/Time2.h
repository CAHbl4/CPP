#pragma once
#include <iomanip>

class Time2 {
	int sec;
public:
	Time2(int h = 0, int m = 0, int s = 0) {
		sec = (h * 60 + m) * 60 + s;
	}


	Time2& operator++() {
		++sec;
		return *this;
	}


	Time2 operator++(int) {
		Time2 tmp(*this);
		sec += 60 * 60;
		return tmp;
	}


	Time2& operator--() {
		sec -= 60;
		return *this;
	}


	Time2 operator--(int) {
		Time2 tmp(*this);
		sec -= 60;
		return tmp;
	}


	Time2 operator+(const Time2& rval) const {
		Time2 tmp(*this);
		tmp.sec += rval.sec;
		return tmp;
	}


	Time2 operator-(const Time2& rval) const {
		Time2 tmp(*this);
		tmp.sec -= rval.sec;
		return tmp;
	}


	friend bool operator==(const Time2& lval, const Time2& rval) {
		return lval.sec == rval.sec;
	}


	friend bool operator!=(const Time2& lval, const Time2& rval) {
		return !(lval == rval);
	}


	operator int() const {
		return sec;
	}


	friend ostream& operator<<(ostream& os, const Time2& obj) {
		if (obj.sec < 0)
			os << "-";

		os << setfill('0') << setw(2)
			<< abs(obj.sec / 60 / 60 % 24) << ":"
			<< setfill('0') << setw(2)
			<< abs(obj.sec / 60 % 60) << ":"
			<< setfill('0') << setw(2)
			<< abs(obj.sec % 60) << endl;
		return os;
	}


	~Time2();
};
