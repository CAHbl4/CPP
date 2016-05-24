#include "stdafx.h"
#include "Person.h"


Person::Person()
{
	age = 0;
	name = new char[1];
	strcpy_s(name, 1, "\0");
}


Person& Person::operator=(const Person& obj)
{
	if (name)
		delete[] name;
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;
	return *this;
}

Person::Person(const Person& obj)
{
	if (name)
		delete[] name;
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;
}

void Person::SetData()
{
	char str[256];
	fflush(stdin);
	cout << "Enter name: ";
	cin.getline(str, 256);
	name = new char[strlen(str) + 1];
	strcpy_s(name, strlen(str) + 1, str);
	cout << "Enter age";
	cin >> age;
}

void Person::Show()
{
	cout << "Name: " << name << "\nAge: " << age << endl;
}

Person::~Person()
{
	if (name)
		delete[] name;
}
