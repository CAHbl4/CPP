#pragma once
class Credit
{
	int period;
	const int maxSum = 2000000;
	int rate;
	char name[20];
	int MonthlyPay();
public:
	Credit();
	Credit(char *str) :maxSum(100000000)
	{
		strcpy_s(name, str);
		cout << "������� ������: ";
		cin >> period;
		cout << "������� ������: ";
		cin >> rate;
	}
	void Info();
	~Credit();
};

