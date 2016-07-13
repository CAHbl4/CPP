// Test.cpp: определяет точку входа для консольного приложения.
//

//Разработать класс Person
//поля: фамилия, имя, дата рождения
//дата рождения - агрегированный класс data
//класс data - день, месяц, год
//предусмотреть запись и считывание изх файла


#include "stdafx.h"
#include <iostream>
#include<string>
#include <fstream>
#include<set>

using namespace std;


class Date
{
	int day;
	int month;
	int year;
public:
	Date(int d = 13, int m = 7, int y = 2016)
	{
		if (d > 31 || d < 1)
			throw "Wrong day!";
		else
			day = d;
		if (m > 12 || m < 1)
			throw "Wrong month!";
		else
			month = m;
		if (y < 0)
			throw "Wrong year!";
		else
			year = y;
	}
	Date(const Date& obj)
	{
		day = obj.day;
		month = obj.month;
		year = obj.year;
	}
	//getters
	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}
	//setters
	void input()
	{
		cout << "Enter date in format d/m/y:";
		cin >> day >> month >> year;
	}
	void show() const
	{
		cout << day << "/" << month << "/" << year;
	}
	friend bool operator==(const Date&, const Date&);
};

bool operator==(const Date& obj1, const Date& obj2)
{
	return obj1.day == obj2.day&&obj1.month == obj2.month&&obj1.year == obj2.year;
}

class Person
{
	string name;
	string surname;
	Date birth;
public:
	Person(string fname = "No_name", string lname = "No_surname", Date d = Date())
	{
		name = fname;
		surname = lname;
		birth = d;
	}
	void input()
	{
		cout << "Enter name:";
		cin >> name;
		cout << "Enter surname:";
		cin >> surname;
		birth.input();
	}
	void show() const
	{
		cout << "Name - " << name << endl;
		cout << "Surname - " << surname << endl;
		cout << "Birthday - ";
		birth.show();
		cout << "\n----------------------------\n";
	}

	friend bool operator==(const Person&, const Person&);
	friend bool operator>(const Person&, const Person&);
	friend bool operator<(const Person&, const Person&);


	void writeFile(ofstream& out)
	{
		int size = name.capacity();
		out.write((char*)&size, sizeof(int));
		out.write((char*)name.c_str(), size);
		size = surname.capacity();
		out.write((char*)&size, sizeof(int));
		out.write((char*)surname.c_str(), size);
		out.write((char*)&birth, sizeof(Date));
	}

	void readFile(ifstream& in)
	{
		int size;
		in.read((char*)&size, sizeof(int));
		char* str1 = new char[size];
		in.read((char*)str1, size);
		in.read((char*)&size, sizeof(int));
		char* str2 = new char[size];
		in.read((char*)str2, size);
		in.read((char*)&birth, sizeof(Date));
		name = str1;
		surname = str2;
		delete str1;
		delete str2;
	}
};

bool operator==(const Person& obj1, const Person& obj2)
{
	return obj1.name == obj2.name&&obj1.surname == obj2.surname&&obj1.birth == obj2.birth;
}

bool operator>(const Person& obj1, const Person& obj2)
{
	return obj1.surname > obj2.surname;
}
bool operator<(const Person& obj1, const Person& obj2)
{
	return obj1.surname < obj2.surname;
}


int _tmain(int argc, _TCHAR* argv[])
{
	try{
		set<Person, less<Person>> spisok;
		spisok.insert(Person("Petr", "Petrov", Date(1, 2, 2010)));
		spisok.insert(Person("Semen", "Semenov", Date(11, 12, 1995)));
		spisok.insert(Person("Sergey", "Sergeev", Date(10, 3, 2003)));
		spisok.insert(Person("Ivan", "Ivanov", Date(1, 2, 2001)));

		//вывод списка
		for (Person x : spisok)
			x.show();
		//поиск человека по фамилии
		Person p1("Serg", "Sergeev", Date(10, 3, 2003));
		auto iter = spisok.find(p1);
		if (iter == spisok.end())
			cout << "Person is not exist\n";
		else
		{
			cout << "Person exist\n";
			iter->show();
		}
		//поиск объекта Person
		cout << "---------------------------------\n";
		iter = find(spisok.begin(), spisok.end(), p1);
		if (iter == spisok.end())
			cout << "Person is not exist\n";
		else
		{
			cout << "Person exist\n";
			iter->show();
		}

		Person p2("Sergey", "Sergeev", Date(10, 3, 2003));
		cout << (p1 == p2) << endl;
		Person p3("Ivan", "Ivanov", Date(1, 2, 2001));

		//запись в файл
		ofstream out("spisok.dat", ios::binary);
		if (!out)
		{
			cerr << "Error open file\n";
			exit(1);
		}
		p1.writeFile(out);
		p2.writeFile(out);
		p3.writeFile(out);
		out.close();

		Person p4, p5, p6;
		ifstream in("spisok.dat", ios::binary);
		if (!in)
		{
			cerr << "Error open file\n";
			exit(1);
		}
		p4.readFile(in);
		p5.readFile(in);
		p6.readFile(in);
		in.close();
		p4.show();
		p5.show();
		p6.show();
	}
	catch (char* str)
	{
		cout << str << endl;
	}

	system("pause");
	return 0;
}

