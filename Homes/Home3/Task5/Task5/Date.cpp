#include "stdafx.h"
#include "Date.h"

const int leapMonthStart[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
const int monthStart[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

void Date::ConvertFromX() {
	unsigned int secs, days;
	if (this->secs >= 0) {
		secs = this->secs;
		days = 70 * 365 + 17;
	}
	else {
		secs = 70 * 365 + 17 * 86400 + this->secs;
		days = 0;
	}
	days += secs / 86400;
	secs = secs % 86400;
	h = secs / 3600;
	secs %= 3600;
	m = secs / 60;
	s = secs % 60;
	int i;
	for (Y = days / 365; days < (i = (Y - 1) / 4 + 365 * Y); --Y) {}
	Y += 1900;
	days -= i;

	const int* pm = Y & 03 || Y == 0 ? monthStart : leapMonthStart;
	for (M = 12; days < pm[--M];) {};
	D = days - pm[M++] + 1;
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
 	ConvertFromX();
}

void Date::AddDay() {
	secs += 86400;
	ConvertFromX();
}

Date& Date::operator++() {
	secs += 86400;
	ConvertFromX();
	return *this;
}

Date Date::operator++(int) {
	Date tmp(*this);
	secs += 86400;
	ConvertFromX();
	return tmp;
}

Date& Date::operator--() {
	secs -= 86400;
	ConvertFromX();
	return *this;
}

Date Date::operator--(int) {
	Date tmp(*this);
	secs -= 86400;
	ConvertFromX();
	return tmp;
}

Date& Date::operator+=(const Date& other) {
	secs += other.secs;
	ConvertFromX();
	return *this;
}

Date& Date::operator-=(const Date& other) {
	secs -= other.secs;
	ConvertFromX();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& obj) {
	return os
		<< obj.D << "."
		<< obj.M << "."
		<< obj.Y << " "
		<< obj.h << ":"
		<< obj.m << ":"
		<< obj.s;
}
