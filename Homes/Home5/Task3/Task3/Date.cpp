#include "stdafx.h"
#include "Date.h"
#include <iomanip>

const int leapMonthStart[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
const int monthStart[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

void Date::ConvertFromX(int& days, int& month, int& year, int& hour, int &min, int& sec) const {
	unsigned int secs;
	if (this->secs >= 0) {
		secs = this->secs;
		days = 70 * 365 + 17;
	}
	else {
		secs = static_cast<unsigned int>(70 * 365 + 17) * 86400 + this->secs;
		days = 0;
	}
	days += secs / 86400;
	secs = secs % 86400;
	hour = secs / 3600;
	secs %= 3600;
	min = secs / 60;
	sec = secs % 60;
	int i;
	for (year = days / 365; days < (i = (year - 1) / 4 + (year & 03 || year == 0 ? monthStart : leapMonthStart)[0] + 365 * year);) { --year; }
	days -= i;

	const int* pm = year & 03 || year == 0 ? monthStart : leapMonthStart;
	for (month = 12; days < pm[--month];) {};
	days -= pm[month] - 1;
}

Date::Date(int day, int month, int year, int hour, int min, int sec) {
	int d, m, y;
	m = month - 1;
	y = year - 1900;
	const int* pm = y & 03 || year == 0 ? monthStart : leapMonthStart;
	d = (y - 1) / 4 + pm[m] - 1;
	d += 365 * y;
	d += day;
	d -= 70 * 365 + 17;

	secs = 3600 * hour;
	secs += 60 * min;
	secs += sec;

	secs += d * 86400;
}

int Date::GetYear() const {
	int days, month, year, hour, min, sec;
	ConvertFromX(days, month, year, hour, min, sec);
	return year + 1900;
}


int Date::GetMonth() const {
	int days, month, year, hour, min, sec;
	ConvertFromX(days, month, year, hour, min, sec);
	return month + 1;
}

int Date::GetDay() const {
	int days, month, year, hour, min, sec;
	ConvertFromX(days, month, year, hour, min, sec);
	return days;
}

int Date::GetHour() const {
	int days, month, year, hour, min, sec;
	ConvertFromX(days, month, year, hour, min, sec);
	return hour;
}

int Date::GetMin() const {
	int days, month, year, hour, min, sec;
	ConvertFromX(days, month, year, hour, min, sec);
	return min;
}

int Date::GetSec() const {
	int days, month, year, hour, min, sec;
	ConvertFromX(days, month, year, hour, min, sec);
	return sec;
}

void Date::AddDay() {
	secs += 86400;
}

Date& Date::operator++() {
	secs += 86400;
	return *this;
}

Date Date::operator++(int) {
	Date tmp(*this);
	secs += 86400;
	return tmp;
}

Date& Date::operator--() {
	secs -= 86400;
	return *this;
}

Date Date::operator--(int) {
	Date tmp(*this);
	secs -= 86400;
	return tmp;
}

Date& Date::operator+=(const Date& other) {
	secs += other.secs;
	return *this;
}

Date& Date::operator-=(const Date& other) {
	secs -= other.secs;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& obj) {
	return os
		<< obj.GetDay() << "."
		<< obj.GetMonth() << "."
		<< obj.GetYear() << " "
		<< std::setfill('0') << std::setw(2)
		<< obj.GetHour() << ":"
		<< std::setfill('0') << std::setw(2)
		<< obj.GetMin() << ":"
		<< std::setfill('0') << std::setw(2)
		<< obj.GetSec();
}