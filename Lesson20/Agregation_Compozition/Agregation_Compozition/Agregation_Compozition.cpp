// Agregation_Compozition.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Person
{
	char* name;
	char* surname;
	int age;
public:
	Person(char* str1 = "\0", char* str2 = "\0", int a = 0) :age(a)
	{
		name = new char[strlen(str1) + 1];
		strcpy_s(name, strlen(str1) + 1, str1);
		surname = new char[strlen(str2) + 1];
		strcpy_s(surname, strlen(str2) + 1, str2);
	}
	~Person()
	{
		if (name)
			delete[] name;
		if (surname)
			delete[] surname;
	}
	Person(const Person& Obj)
	{
		name = new char[strlen(Obj.name) + 1];
		strcpy_s(name, strlen(Obj.name) + 1, Obj.name);
		surname = new char[strlen(Obj.surname) + 1];
		strcpy_s(surname, strlen(Obj.surname) + 1, Obj.surname);
		age = Obj.age;
	}
	Person& operator=(const Person& Obj)
	{
		if (this == &Obj)
			return *this;
		if (name)
			delete[] name;
		if (surname)
			delete[] surname;
		name = new char[strlen(Obj.name) + 1];
		strcpy_s(name, strlen(Obj.name) + 1, Obj.name);
		surname = new char[strlen(Obj.surname) + 1];
		strcpy_s(surname, strlen(Obj.surname) + 1, Obj.surname);
		age = Obj.age;
	}
	void Passport()
	{
		cout << "Name:" << name << ", Surname:" << surname << ", age:" << age << endl;
	}

	void SetPerson()
	{
		char str[256];
		cout << "Enter name:";
		cin >> str;
		if (name)
			delete[] name;
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		cout << "Enter surname:";
		cin >> str;
		if (surname)
			delete[] surname;
		surname = new char[strlen(str) + 1];
		strcpy_s(surname, strlen(str) + 1, str);
		cout << "Enter age:";
		cin >> age;
	}

};

class Group
{
	int size;
	char* name;
	Person* ptr;
public:
	Group(int size = 0, char* str = "\0") :size(size)
	{
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		ptr = new Person[size];
	}
	void ShowGroup()
	{
		cout << "Group:" << name << endl;
		for (int i = 0; i < size; i++)
			ptr[i].Passport();
	}

	void CreateGroup()
	{
		char str[256];
		cout << "Enter groupname:";
		cin >> str;
		if (name)
			delete[] name;
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		cout << "Enter acount Person:";
		cin >> size;
		if (ptr)
			delete[] ptr;
		ptr = new Person[size];
		for (int i = 0; i < size; i++)
			ptr[i].SetPerson();
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	Person st1("Ivan", "Ivanov", 23);
	st1.Passport();
	Group gr1;
	gr1.CreateGroup();
	gr1.ShowGroup();
	system("pause");
	return 0;
}

