#pragma once
#include <iostream>

class Date {
	int secs;
	int Y, M, D, h, m, s;
	void ConvertFromX();
public:
	Date(int secs = 0) : secs(secs) { ConvertFromX(); }

	Date(int day, int month, int year = 1970, int hour = 0, int min = 0, int sec = 0);

	void AddDay();

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	Date& operator+=(const Date& other);
	Date& operator-=(const Date& other);


	friend bool operator<(const Date& lhs, const Date& rhs) {
		return lhs.secs < rhs.secs;
	}

	friend bool operator<=(const Date& lhs, const Date& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Date& lhs, const Date& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Date& lhs, const Date& rhs) {
		return !(lhs < rhs);
	}

	friend bool operator==(const Date& lhs, const Date& rhs) {
		return lhs.secs == rhs.secs;
	}

	friend bool operator!=(const Date& lhs, const Date& rhs) {
		return !(lhs == rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& obj);

	void ShowDate() const {
		std::cout << *this << std::endl;
	}
};
