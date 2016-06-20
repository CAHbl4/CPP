// Student.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Person
{
protected:
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

class Student :public Person
{
	char* group;
	int *marks;
	int size;
public:
	Student(char* n = "\0", char* s = "\0", char* gr = "\0", int age = 18, int size = 0) :size(size),
		Person(n, s, age)
	{
		//заполнение группы
		group = new char[strlen(gr) + 1];
		strcpy_s(group, strlen(gr) + 1, gr);
		marks = new int[size];
		for (int i = 0; i < size; i++)
		{
			marks[i]=rand()%10+1;
		}
	}
	~Student()
	{
		if (group)
			delete[] group;
		if (marks)
			delete[] marks;
	}
	void Passport()
	{
		Person::Passport();
		cout << "Group:" << group << endl;
		cout << "Marks:\n";
		for (int i = 0; i < size; i++)
			cout << marks[i] << "\t";
		cout << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Student st1("Max", "Lesser", "P11015", 25, 4);
	st1.Passport();
	system("pause");
		return 0;
}

