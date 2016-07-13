// ListPerson.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<list>
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
	Person(string str1="NoName", string str2="NoFace", int a=0) :name(str1), surname(str2), age(a){}
	friend ostream& operator<<(ostream& out, const Person& Obj);
	friend istream& operator>>(istream& in1, Person& Obj);
	bool operator<(const Person& Obj)
	{
		//return name < Obj.name;
		return age < Obj.age;
	}
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

int _tmain(int argc, _TCHAR* argv[])
{
	list<Person> l1;
	l1.push_back(Person("Jhon", "Smith", 35));
	l1.push_back(Person("Sara", "Conor", 31));
	l1.push_back(Person("Max", "Pein", 24));
	l1.push_back(Person("Paul", "Creez", 28));

	//вывод списка
	ostream_iterator<Person> outiter(cout, "\n");
	copy(l1.begin(), l1.end(), outiter);

	if (l1.back() < l1.front())
		cout << "<!!!\n";
	else
		cout << "not<!!!\n";

	//сортировка списка
	l1.sort();
	cout << "------------------------Sort---------------------------\n";
	copy(l1.begin(), l1.end(), outiter);

	//запись в файл
	ofstream fout("Person.dat");
	ostream_iterator<Person> foutiter(fout, "");
	copy(l1.begin(), l1.end(), foutiter);
	fout.close();


	//проверка ввода
	Person p1;
	cout << "Enter data:\n";
	cin >> p1;
	cout << "--------------------------------------\n";
	cout << p1;
	//чтение из файла
	ifstream fin("Person.dat");
	istream_iterator<Person> initer(fin);
	istream_iterator<Person> enditer;
	list<Person> L2;
	copy(initer, enditer, back_inserter(L2));
	


	cout << "Spisok L2\n";
	copy(L2.begin(), L2.end(), outiter);



	system("pause");
	return 0;
}

