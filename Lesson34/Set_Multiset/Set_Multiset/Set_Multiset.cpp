// Set_Multiset.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<set>
#include<iterator>
#include<algorithm>
#include<functional>
#include <string>

using namespace std;

class Person
{
	string name;
	string surname;
	int age;
public:
	Person(string str1 = "\0", string str2 = "\0", int a = 20) :name(str1), surname(str2), age(a){}
	friend ostream& operator<<(ostream& out, const Person& Obj);
	friend bool operator<(const Person& p1, const Person& p2);
};

ostream& operator<<(ostream& out, const Person& Obj)
{
	out << "Имя: " << Obj.name << endl;
	out << "Фамилия: " << Obj.surname << endl;
	out << "Возраст: " << Obj.age << endl;
	return out;
}

bool operator<(const Person& p1, const Person& p2)
{
	if (p1.name < p2.name)
		return true;
	if (p1.name == p2.name)
		return p1.surname < p2.surname;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	set<int> s1 = { 5, 6, 3, 9, 2, 7, 3, 9, 5 };
	cout << "Set1:\n";
	ostream_iterator<int> outiter(cout, "\t");
	copy(s1.begin(), s1.end(), outiter);
	cout << endl;
	//формирование дерева по убыванию
	set<int, greater<int> > s2 = { 5, 6, 3, 9, 2, 7, 3, 9, 5 };
	cout << "Set2:\n";
	copy(s2.begin(), s2.end(), outiter);
	cout << endl;

	//для использования повторяющихся значений
	//используется мультимножество
	multiset<int> ms = { 5, 6, 3, 9, 2, 7, 3, 9, 5 };
	cout << "MultiSet:\n";
	copy(ms.begin(), ms.end(), outiter);
	cout << endl;

	//поиск из диапазона
	set<string,less<string> > s3;
	s3.insert("Маша");
	s3.insert("Катя");
	s3.insert("Петя");
	s3.insert("Вася");
	s3.insert("Дима");
	s3.insert("Таня");
	s3.insert("Маша");

	cout << "Список:\n";
	ostream_iterator<string> siter(cout, "\n");
	copy(s3.begin(), s3.end(), siter);
	cout << "Вывод из диапазона Д-С\n";
	string namefirst = "Д";
	string namelast = "С";
	auto iter1 = s3.lower_bound(namefirst);
	while (iter1 != s3.upper_bound(namelast))
	{
		cout << *iter1 << endl;
		iter1++;
	}

	//список людей
	set<Person, less<Person> > gr;
	gr.insert(Person("Коля", "Колокольчиков", 14));
	gr.insert(Person("Тимур", "Гайдар", 15));
	gr.insert(Person("Миша", "Квакин", 14));
	gr.insert(Person("Алиса", "Селезнява", 16));
	gr.insert(Person("Алиса", "Селезнева", 18));

	cout << "Cписок людей:\n";
	ostream_iterator<Person> piter(cout, "\n");
	copy(gr.begin(), gr.end(), piter);






	
	system("pause");
	return 0;
}

