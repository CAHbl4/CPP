#include "stdafx.h"
#include "Credit.h"


void Credit::Info()
{
	cout << "»м€: " << name << endl;
	cout << "ѕериод: " << period << endl;
	cout << "—умма кредита: " << maxSum << endl;
	cout << "≈жемес€чный платеж: " << MonthlyPay() << endl;
}

int Credit::MonthlyPay()
{
	return (maxSum + maxSum * rate / 100) / period;
}

Credit::Credit()
{
	cout << "¬ведите им€: ";
	cin >> name;
	cout << "¬ведите период: ";
	cin >> period;
	cout << "¬ведите ставку: ";
	cin >> rate;
}


Credit::~Credit()
{
}
