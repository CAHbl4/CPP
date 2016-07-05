// File_Object.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

class Person
{
protected:
	char* name;
	int age;
public:
	Person(char* str = "NoName", int a = 20) :age(a)
	{
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
	}
	virtual void ShowPerson()
	{
		cout << "Name:" << name << endl;
		cout << "Age:" << age << endl;
	}
	virtual ~Person()
	{
		if (name)
			delete[] name;
	}
	//запись в файл
	virtual void WriteFile(fstream& out) 
	{
		int n;
		n = strlen(name) + 1;
		out.write(reinterpret_cast<char*>(&n), sizeof(n));
		out.write(name, n);
		out.write((char*)&age, sizeof(age));
	}
	virtual void ReadFile(fstream& in)
	{
		if (name)
			delete[] name;
		//n-длина строки+1
		int n;
		//считываем количество байтов занимаемых строкой
		in.read(reinterpret_cast<char*>(&n), sizeof(n));
		//выделяем память для name
		name = new char[n];
		//считываем Name Из файла
		in.read(name, n);
		//считываем age из файла
		in.read(reinterpret_cast<char*>(&age), sizeof(age));
	}

};

class Student :public Person
{
	//дополнительные поля массив оценок
	int size;
	int* marks;
public:
	Student(char* str = "NoName", int a = 20, int s = 0) :Person(str, a), size(s)
	{
		marks = new int[size];
		for (int i = 0; i < size; i++)
			marks[i] = rand() % 10;
	}
	void ShowPerson()
	{
		Person::ShowPerson();
		cout << "Marks: ";
		for (int i = 0; i < size; i++)
			cout << marks[i] << "\t";
		cout << endl;
	}
	~Student()
	{
		if (marks)
			delete[] marks;
	}
	void WriteFile(fstream& out) 
	{
		Person::WriteFile(out);
		//записываем размер
		out.write(reinterpret_cast<char*>(&size), sizeof(size));
		//записываем массив
		out.write(reinterpret_cast<char*>(marks), size*sizeof(int));
	}
	void ReadFile(fstream& in)
	{
		Person::ReadFile(in);
		if (marks)
			delete[] marks;
		in.read(reinterpret_cast<char*>(&size), sizeof(size));
		marks = new int[size];
		in.read(reinterpret_cast<char*>(marks), size*sizeof(int));
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Person p1("Petya", 33);
	//p1.ShowPerson();
	Person p2("Vasya", 27);
	//запись объектов в файл
	try
	{
		fstream out("Person1.dat", ios::app | ios::binary);
		if (!out)
			throw exception("Error!!!");
		//int n;
		////запись первого человека
		//n = strlen(p1.name)+1;
		//out.write(reinterpret_cast<char*>(&n), sizeof(n));
		//out.write(p1.name, n);
		//out.write((char*)&p1.age, sizeof(p1.age));
		////запись первого человека
		//n = strlen(p2.name) + 1;
		//out.write(reinterpret_cast<char*>(&n), sizeof(n));
		//out.write(p2.name, n);
		//out.write((char*)&p2.age, sizeof(p2.age));

		//запись с использованием метода класса
		/*p1.WriteFile(out);
		p2.WriteFile(out);
		out.close();*/

		//считывание данных из файла
		fstream in("Person1.dat", ios::in | ios::binary);
		if (!in)
			throw exception("Error!!!");
		//создаем объект
		Person temp;
		//определим количество объектов в файле
		int count;
		//перемещаем указатель в конец файла
		in.seekg(0,ios::end);
		//определяем текущую позицию указателя (смешение в байтах от начала)
		count = in.tellg();
		in.seekg(0);
		while (in.tellg()<count)
		{
			//считываем данные
			temp.ReadFile(in);
			//отображаем
			temp.ShowPerson();
			cout << "---------------------------\n";
		}
		in.close();

		//запись наследника
		Student st1("Ivan", 24, 4);
		Student st2("Alex", 26, 5);
		fstream outs("Student.dat", ios::app | ios::binary);
		if (!outs)
			throw exception("Error!!!");
		st1.WriteFile(outs);
		st2.WriteFile(outs);
		outs.close();
		//чтение из файла
		fstream ins("Student.dat", ios::in | ios::binary);
		if (!ins)
			throw exception("Error!!!");
		Student temps;
		temps.ReadFile(ins);
		temps.ShowPerson();
		temps.ReadFile(ins);
		temps.ShowPerson();
		ins.close();

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}

