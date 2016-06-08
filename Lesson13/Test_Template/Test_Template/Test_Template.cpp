// Test_Template.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//функции нахождения максимума среди двух значений
//для цлочисленных значений

void Max(int a, int b)
{
	(a > b) ? cout << "Bigger a=" << a << endl : cout << "Bigger b=" << b << endl;
}

void Max(double a, double b)
{
	(a > b) ? cout << "Bigger a=" << a << endl : cout << "Bigger b=" << b << endl;
}

void Max(char a, char b)
{
	(a > b) ? cout << "Bigger a=" << a << endl : cout << "Bigger b=" << b << endl;
}


//шаблон для нахождения максимума
template<typename T1, class T2>
void Max1(T1 a, T2 b)
{
	(a > b) ? cout << "Bigger a=" << a << endl : cout << "Bigger b=" << b << endl;
}

//шаблон для нахождения максимума в массиве
template<class T>
T MaxArray(T mas[], int size)
{
	T max = mas[0];
	for (int i = 1; i < size; i++)
	if (mas[i]>max)
		max = mas[i];
	cout << "Maximum - " << max << endl;
	return max;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Max(3, 5);
	Max(2.3, 5.4);
	Max('A', 'B');
	cout << "------------------------------------------------\n";
	Max1(3, 5);
	Max1(2.3, 1);
	Max1('A', 'B');
	cout << "------------------------------------------------\n";
	int ar1[4] = { 1, 2, 3, 4 };
	float ar2[3] = { 2.5, 6.2, 7.4 };
	char ar3[4] = { 'Z', '5', 'A', '0' };
	cout << MaxArray(ar1, 4) << endl;
	cout << MaxArray(ar2, 3) << endl;
	cout << MaxArray(ar3, 4) << endl;

	system("pause");
	return 0;
}

