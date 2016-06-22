#pragma once
#include <iomanip>

class Time {
	int sec;
public:
	Time(int h = 0, int m = 0, int s = 0) {
		sec = (h * 60 + m) * 60 + s;
	}

	Time operator+(const Time& rval) const {
		Time tmp(*this);
		tmp.sec += rval.sec;
		return tmp;
	}

	Time operator-(const Time& rval) const {
		Time tmp(*this);
		tmp.sec -= rval.sec;
		return tmp;
	}

	friend bool operator==(const Time& lval, const Time& rval) {
		return lval.sec == rval.sec;
	}

	friend bool operator!=(const Time& lval, const Time& rval) {
		return !(lval == rval);
	}

	operator int() const {
		return sec;
	}

	friend std::ostream& operator<<(std::ostream& os, const Time& obj) {
		if (obj.sec < 0)
			os << "-";

		os << std::setfill('0') << std::setw(2)
			<< abs(obj.sec / 60 / 60 % 24) << ":"
			<< std::setfill('0') << std::setw(2)
			<< abs(obj.sec / 60 % 60) << ":"
			<< std::setfill('0') << std::setw(2)
			<< abs(obj.sec % 60) << std::endl;
		return os;
	}
};
