// Class_Man.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Man.h"


int main()
{
	setlocale(LC_ALL, "Rus");

	Man m1;
	m1.Passport();
	//cout << "������ �������: " << sizeof(m1) << endl;

	Man m2("�������", "������", 21);
	m2.Passport();
	
	cout << "-------------------------------------------------------------------------\n";
	cout << "������� 2-�� ��������: " << m2.GetSurName() << endl;
	cout << "������� 1-�� ��������: " << m1.GetAge() << endl;

	cout << "-------------------------------------------------------------------------\n";
	m1.SetName("����");
	m1.SetSurName("������");
	m1.SetAge(18);
	m1.Passport();
	
	system("pause");
    return 0;
}

