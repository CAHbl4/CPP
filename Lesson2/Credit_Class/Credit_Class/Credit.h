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
		cout << "¬ведите период: ";
		cin >> period;
		cout << "¬ведите ставку: ";
		cin >> rate;
	}
	void Info();
	~Credit();
};

