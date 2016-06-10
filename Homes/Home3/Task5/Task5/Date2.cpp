#include "stdafx.h"
#include "Date2.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Date2::DaysInMonth(int year, int month) const {
	int result	= 0;

	if (!month) {
		month	= 12;
		--year;
	}

	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			result = 31;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			result = 30;
			break;

		case 2:
			result = 28;
			if (!(year%400) || (!(year%4) && year%100))
				++result;
			break;
	}
	return result;
}

void Date2::Convert() {

		int step = 1;	// идем вверх от стартовой даты.
		if (this->sec < 0) {
			step = -1;	// идем вниз от стартовой даты.
		}

		int days;

		Y = 1970;
		M = 1;
		D = 1;
		h = 0;
		m = 0;
		s = 0;

		int sec = this->sec % 86400 * step;
		int all = this->sec / 86400 * step;

		// Выше стартовой даты
		if (step>0) {
			while (all >= (days = DaysInMonth(Y, M))) {
				all -= days;
				M++;

				if (M > 12) {
					M = 1;
					Y++;
				}
			}
			D += all;

			h = sec / 3600;
			m = (sec % 3600) / 60;
			s = sec % 60;
		}

		// Ниже стартовой даты.
		if (step<0) {
			if (sec > 0) {
				++all;
				sec = 86400 - sec;
			}

			while (all >= 0) {
				days = DaysInMonth(Y, M - 1);
				all -= days;
				--M;

				if (!M) {
					M = 12;
					--Y;
				}
			}
			all *= -1;
			D += all;

			if (D > DaysInMonth(Y, M)) {
				D = 1;
				++M;
				if (M > 12) {
					M = 1;
					++Y;
				}
			}
			h = sec / 3600;
			m = (sec % 3600) / 60;
			s = sec % 60;
		}
	}


Date2::Date2(int val) : sec(val) { Convert(); }

Date2::~Date2() {}

void Date2::ShowDate() const {

	int step	= 1;	// идем вверх от стартовой даты.
	if (this->sec < 0) {
		step	= -1;	// идем вниз от стартовой даты.
	}

	int days;

	int Y		= 1970;
	int M		= 1;
	int D		= 1;
	int h		= 0;
	int m		= 0;
	int s		= 0;

	int sec		= this->sec % 86400 * step;
	int all		= this->sec / 86400 * step;

	// Выше стартовой даты
	if (step>0) {
		while (all >= (days = DaysInMonth(Y, M))) {
			all -= days;
			M++;

			if (M > 12) {
				M	= 1;
				Y++;
			}
		}
		D	+= all;

		h	= sec / 3600;
		m	= (sec % 3600) / 60;
		s	= sec % 60;
	}

	// Ниже стартовой даты.
	if (step<0) {
		if (sec > 0) {
			++all;
			sec	= 86400 - sec;
		}

		while (all >= 0) {
			days = DaysInMonth(Y, M-1);
			all -= days;
			--M;

			if (!M) {
				M	= 12;
				--Y;
			}
		}
		all *= -1;
		D	+= all;

		if (D > DaysInMonth(Y, M)) {
			D	= 1;
			++M;
			if (M > 12) {
				M	= 1;
				++Y;
			}
		}
		h	= sec / 3600;
		m	= (sec % 3600) / 60;
		s	= sec % 60;
	}

	cout 
		<< "sec = " << setfill(' ') << setw(35) << this->sec << " [" 
		<< setfill('0') << setw(4) << Y << "-" 
		<< setfill('0') << setw(2) << M << "-" 
		<< setfill('0') << setw(2) << D << " " 
		<< setfill('0') << setw(2) << h << ":" 
		<< setfill('0') << setw(2) << m << ":" 
		<< setfill('0') << setw(2) << s << "]\n";
}
