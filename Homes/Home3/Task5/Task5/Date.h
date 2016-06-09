#pragma once
#include <ostream>

class Date {
	int secs;
	void ConvertFromX(int& days, int& month, int& year, int& hour, int &min, int& sec) const;
public:
	Date(int secs): secs(secs) {}

	Date(int day, int month, int year = 1970, int hour = 0, int min = 0, int sec = 0);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetHour() const;
	int GetMin() const;
	int GetSec() const;

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
};
