#include "stdafx.h"
#include "Credit.h"


void Credit::Info()
{
	cout << "Имя: " << name << endl;
	cout << "Период: " << period << endl;
	cout << "Сумма кредита: " << maxSum << endl;
	cout << "Ежемесячный платеж: " << MonthlyPay() << endl;
}

int Credit::MonthlyPay()
{
	return (maxSum + maxSum * rate / 100) / period;
}

Credit::Credit()
{
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите период: ";
	cin >> period;
	cout << "Введите ставку: ";
	cin >> rate;
}


Credit::~Credit()
{
}
