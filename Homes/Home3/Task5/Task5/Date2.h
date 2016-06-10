#pragma once
class Date2 {
	int sec;	// 0 = 1970-01-01 00:00:00
	int Y, M, D, h, m, s;
	int DaysInMonth(int, int) const;
	void Convert();
public:
	Date2(int = 0);
	~Date2();

	void ShowDate() const;
};

