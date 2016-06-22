// Animals.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Animal
{
protected:
	char* name;
public:
	Animal(char* str = "Noname!!!")
	{
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
	}
	virtual void Say()
	{
		cout << "I'm amorph animal" <<name<<", I can't say anything!!!\n";
	}
	virtual void Move()
	{
		cout << "I'm amorph animal" << name << ", I can't move!!!\n";
	}
	virtual ~Animal()
	{
		if (name)
			delete[] name;
	}
};

//производные классы
class Duck:public Animal
{
public:
	Duck(char* str) :Animal(str){}
	virtual void Say()
	{
		cout << "I'm duck "<<name<<", I say Krya-Krya!!!\n";
	}
	virtual void Move()
	{
		cout << "I'm duck " << name << ", I can fly!!!\n";
	}
};

class Frog :public Animal
{
public:
	Frog(char* str) :Animal(str){}
	virtual void Say()
	{
		cout << "I'm frog " << name << ", I say Kwa-Kwa!!!\n";
	}
	virtual void Move()
	{
		cout << "I'm frog " << name << ", I can jump!!!\n";
	}
};

class Dog :public Animal
{
public:
	Dog(char* str) :Animal(str){}
	virtual void Say()
	{
		cout << "I'm dog " << name << ", I say Gav-Gav!!!\n";
	}
	virtual void Move()
	{
		cout << "I'm dog " << name << ", I can run, jump!!!\n";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Animal *stado[4];
	stado[0] = new Animal;
	stado[1] = new Duck("Scroodge");
	stado[2] = new Dog("Sharik");
	stado[3] = new Frog("Queen");

	for (int i = 0; i < 4; i++)
	{
		cout << "-----------------------------\n";
		stado[i]->Say();
		stado[i]->Move();
		cout << typeid(*stado[i]).name() << endl;
			
	}

	system("pause");
	return 0;
}

