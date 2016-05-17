#include "stdafx.h"
#include "Man.h"

Man::Man()
{
	strcpy_s(name, "No face");
	strcpy_s(surname, "No name");
	age = 0;
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
