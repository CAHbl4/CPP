// Test_string.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//�������� ������
	string str1;
	str1 = "String One!\n";
	string str2 = "String Two!\n";
	string str3("String Three!\n");
	//����� ������
	cout << str1 << str2 << str3;
	//���� ������
	cout << "Enter string:";
	//���� ������ �� �����������
	cin >> str3;
	cout << str3<<endl;
	cout << "Enter string:";
	//���� ������ � �������������
	//������� ����� �����
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin,str3,'\n');
	cout << str3 << endl;

	//����������
	cout << "Enter your name:";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	string greeting="Hello, ";
	string name;
	getline(cin, name);
	greeting += name + " ";
	cout << "Enter your surname:";
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	string surname;
	getline(cin, surname);
	greeting += surname + "!\nWe nice to meet you!!!\n";
	cout << greeting;

	//�������������� � char*
	char str10[256];
	strcpy_s(str10,256,greeting.c_str());
	cout << str10;
	const char *ptr;
	ptr = greeting.c_str();
	cout << ptr;
	system("pause");
	return 0;
}

