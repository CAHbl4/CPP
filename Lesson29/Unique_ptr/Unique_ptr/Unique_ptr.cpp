// Unique_ptr.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//�������, ������������ ��������� �� ������
unique_ptr<string> demo(string str)
{
	cout << str << endl;
	return unique_ptr<string>(new string);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	//������� ��������� �� ������
	unique_ptr< string> pul(new string("Hello!"));
	//������ ���������
	unique_ptr< string> pu2;
	//pu2 = pul; // #1 �� ��������� 
	unique_ptr<string> pu3;
	pu3 = unique_ptr<string>(new string("Yo!")); // #2 ��������� 

	unique_ptr<string> psl, ps2;
	psl = demo("Uniquely special");
	
	// ������ ��������� ������������ 
	psl = demo(" and more");
	cout << *ps2 << *psl << endl;


	system("pause");


	return 0;
}

