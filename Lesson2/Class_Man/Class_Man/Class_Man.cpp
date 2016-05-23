// Class_Man.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Man.h"


int main()
{
	setlocale(LC_ALL, "Rus");

	Man m1;
	m1.Passport();
	//cout << "Размер объекта: " << sizeof(m1) << endl;

	Man m2("Василий", "Пупкин", 21);
	m2.Passport();
	
	cout << "-------------------------------------------------------------------------\n";
	cout << "Фамилия 2-го человека: " << m2.GetSurName() << endl;
	cout << "Возраст 1-го человека: " << m1.GetAge() << endl;

	cout << "-------------------------------------------------------------------------\n";
	m1.SetName("Иван");
	m1.SetSurName("Иванов");
	m1.SetAge(18);
	m1.Passport();

	cout << "-------------------------------------------------------------------------\n";
	Man men[3];
	for (int i = 0; i < 1; ++i)
	{
		men[i].Passport();
	}
	
	system("pause");
    return 0;
}

