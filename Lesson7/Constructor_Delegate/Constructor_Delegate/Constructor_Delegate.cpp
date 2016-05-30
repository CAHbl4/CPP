// Constructor_Delegate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class Test
{
	int min;
	int max;
	int middle;
public:
	Test() :min(0), max(10), middle(min){}

	Test(int value) :max(10)
	{
		//if (value < 0)
		//	min = value;
		//else min = 0;
		(value < 0) ? min = value : min = 0;
		middle = min;
	}

	Test(int value1, int value2) : Test(value1)
	{
		//(value1 < 0) ? min = value1 : min = 0;
		//middle = min;
		(value2 > 10) ? max = value2 : max = 10;
	}

	void Show()
	{
		cout << "Min: " << min << ", Max: " << max << ", Middle: " << middle << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Test t1(4);
	t1.Show();
	Test t2(-3, 12);
	t2.Show();

	system("pause");
	return 0;
}