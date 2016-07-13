// Set.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<set>
#include<fstream>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;

class Person
{
	string name;
	string surname;
	int age;
public:
	Person(string str1 = "NoName", string str2 = "NoFace", int a = 0) :name(str1), surname(str2), age(a){}
	friend ostream& operator<<(ostream& out, const Person& Obj);
	friend istream& operator>>(istream& in1, Person& Obj);
	friend bool operator<(const Person& Obj1, const Person& Obj2);
};

ostream& operator<<(ostream& out, const Person& Obj)
{
	out << Obj.name << endl;
	out << Obj.surname << endl;
	out << Obj.age << endl;
	return out;
}
istream& operator>>(istream& in1, Person& Obj)
{
	getline(in1, Obj.name);
	getline(in1, Obj.surname);
	in1 >> Obj.age;
	return in1;
}

bool operator<(const Person& Obj1, const Person& Obj2)
{
	return Obj1.age < Obj2.age;
}




int _tmain(int argc, _TCHAR* argv[])
{
	set<Person,less<Person> > s1;
	s1.insert(Person("Jhon", "Smith", 35));
	s1.insert(Person("Sara", "Conor", 26));
	s1.insert(Person("Max", "Pein", 24));
	s1.insert(Person("Paul", "Creez", 28));

	//вывод 
	ostream_iterator<Person> outiter(cout, "\n");
	copy(s1.begin(), s1.end(), outiter);


	system("pause");
	return 0;
}

