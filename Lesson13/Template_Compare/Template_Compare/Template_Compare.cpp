// Template_Compare.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T1, class T2>
auto Max(T1 a, T2 b)->decltype(b + a)
{
	return (a > b) ? a : b;
}

auto Max(char* str1, char* str2)->decltype(str1)
{
	return (strcmp(str1, str2) > 0) ? str1 : str2;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << Max(1, 2) << endl;
	cout << Max(3.2, 2.4) << endl;
	cout << Max('A', 32) << endl;
	char *str11 = "1,2,3!!!";
	char *str22 = "5,6,7!!!";
	cout << Max(str11, str22) << endl;
	cout << "-----------------------------------\n";
	//�������� ���������� � ������������� auto
	auto a = 4;
	//������������ ����������� ����
	cout << a << ", type:" << typeid(a).name() << endl;
	//����������� ���� �� ����� ����������
	auto ptr = new decltype(a);
	cout << ptr << ", type:" << typeid(ptr).name() << endl;
	auto str = "123!!!";
	cout << str << ", type:" << typeid(str).name() << endl;
	//��������� ���������� str1 �� �� �� ����, ��� � str
	decltype(str) str1 = str;
	cout << str1 << ", type:" << typeid(str1).name() << endl;

	system("pause");
	return 0;
}

