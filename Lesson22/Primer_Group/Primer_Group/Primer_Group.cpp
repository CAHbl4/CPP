// Primer_Group.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Person
{
protected:
	char* name;
	int age;
public:
	Person(char* str=0)
	{
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1,str);
		age = rand() % 21 + 20;;
	}
	char* GetName() const
	{
		return name;
	}
	int GetAge() const
	{
		return age;
	}
	virtual void About()
	{
		cout << "My name is" << name << "\nI am " << age << " years old!\n";
	}
	virtual void Privet(Person* Obj);
	~Person()
	{
		if (name)
			delete[] name;
	}
};

class Formalist :public Person
{
public:
	Formalist(char* str) :Person(str){}
	void Privet(Person* Obj)
	{
		cout << "Hello!" << Obj->GetName() << endl;
	}
};

class Neformal :public Person
{
public:
	Neformal(char* str) :Person(str){}
	void Privet( Person* Obj)
	{
		cout << "Hi!" << Obj->GetName() << endl;
	}
};

class Realist :public Person
{
public:
	Realist(char* str) :Person(str){}
	void Privet(Person* Obj)
	{
		if ((age+5) >= Obj->GetAge())
			cout << "Hi!" << Obj->GetName() << endl;
		else
			cout << "Hello!" << Obj->GetName() << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Person *ptr[5];
	ptr[0] = new Formalist("Pit");
	ptr[1] = new Neformal("Alex");
	ptr[2] = new Realist("Stas");
	ptr[3] = new Realist("Sara");
	ptr[4] = new Formalist("Adam");

	Person *ptr1 = new Person("Max");
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			ptr[i]->About();
			ptr[i]->Privet(ptr1);
		}
	}

	system("pause");
	return 0;
}

