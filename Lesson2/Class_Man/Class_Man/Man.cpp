#include "stdafx.h"
#include "Man.h"

Man::Man()
{
	char str[20];
	cout << "Введите имя: ";
	cin >> str;
	OemToAnsi(str, str);
	strcpy_s(name, str);
	cout << "Введите фамилию: ";
	cin >> str;
	OemToAnsi(str, str);
	strcpy_s(surname, str);
	cout << "Введите возраст: ";
	cin >> age;
}

Man::Man(const char* str_name, const char* str_surname, int value)
{
	strcpy_s(name, str_name);
	strcpy_s(surname, str_surname);
	age = value;
}

const char* Man::GetName() const
{
	return name;
}

const char* Man::GetSurName() const
{
	return surname;
}

int Man::GetAge() const
{
	return age;
}

void Man::SetName(const char* str)
{
	strcpy_s(name, str);
}

void Man::SetSurName(const char* str)
{
	strcpy_s(surname, str);
}

void Man::SetAge(int value)
{
	age = value;
}

void Man::Passport()
{
	cout << "Имя:" << name << endl;
	cout << "Фамилия:" << surname << endl;
	cout << "Возраст:" << age << endl;
	cout << "------------------------------\n";
}

Man::~Man()
{
}
