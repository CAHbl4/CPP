#include "stdafx.h"
#include "Credit.h"


void Credit::Info()
{
	cout << "���: " << name << endl;
	cout << "������: " << period << endl;
	cout << "����� �������: " << maxSum << endl;
	cout << "����������� ������: " << MonthlyPay() << endl;
}

int Credit::MonthlyPay()
{
	return (maxSum + maxSum * rate / 100) / period;
}

Credit::Credit()
{
	cout << "������� ���: ";
	cin >> name;
	cout << "������� ������: ";
	cin >> period;
	cout << "������� ������: ";
	cin >> rate;
}


Credit::~Credit()
{
}
