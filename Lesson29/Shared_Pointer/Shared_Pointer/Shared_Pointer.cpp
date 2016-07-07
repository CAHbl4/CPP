// Shared_Pointer.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "rus");
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("������� ����")),
		shared_ptr<string>(new string("����������")),
		shared_ptr<string>(new string("� ��� ���� ���� �������")),
		shared_ptr<string>(new string("�������")),
		shared_ptr<string>(new string("�����������"))
	};
	shared_ptr<string> pwin;
	pwin = films[2];   // films[2] � pwin ��������� �� ���� � ��� �� ������

	cout << "�������� �� ������ �����\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	
	system("pause");
	return 0;
}

