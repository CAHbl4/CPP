// References.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>


using namespace std;

void f1(int x, int y)
{
	cout << "�������� ���������� ��� ������\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;

	x = 10; y = 20;

	cout << "�������� ���������� ����� ���������\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;
}

void f2(int &x, int &y)
{
	cout << "�������� ���������� �� ������\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;

	cout << "Adress2" << &x;
	x = 10; y = 20;

	cout << "�������� ���������� ����� ���������\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;
}

void f3(int *x, int *y)
{
	cout << "�������� ���������� �� ���������\n";
	cout << "X = " << *x << ", adress = " << &x << endl;
	cout << "Y = " << *y << ", adress = " << &y << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	int x = 1, y = 2;

	cout << "�������� ���������� � �������� ���������\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;

	f1(x, y);

	cout << "�������� ���������� � �������� ��������� ����� ������ f1()\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;


	f2(x, y);

	cout << "�������� ���������� � �������� ��������� ����� ������ f2()\n";
	cout << "X = " << x << ", adress = " << &x << endl;
	cout << "Y = " << y << ", adress = " << &y << endl;


	system("pause");
	return 0;
}