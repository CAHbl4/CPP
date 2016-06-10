// Universal_Array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class Array
{
	int size;
	T *ptr;
public:
	Array(int size = 0) :size(size)
	{
		ptr = new T[size];
	}
	Array(const Array<T>& Obj)
	{
		size = Obj.size;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = Obj.ptr[i];
	}
	~Array()
	{
		if (ptr)
			delete[] ptr;
	}
	Array& operator=(const Array<T>& Obj)
	{
		if (this == &Obj)
			return *this;
		if (ptr)
			delete[] ptr;
		size = Obj.size;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = Obj.ptr[i];
		return *this;
	}
	friend ostream& operator<<<T>(ostream& out, const Array<T>& Obj);
	friend istream& operator>><T>(istream& in, Array<T>& Obj);
};

template<class T>
ostream& operator<<(ostream& out, const Array<T>& Obj)
{
	out << "Data:\n";
	for (int i = 0; i < Obj.size; i++)
		out << Obj.ptr[i] << "\t";
	out << endl;
	return out;
}

template<class T>
istream& operator>>(istream& in, Array<T>& Obj)
{
	cout << "Enter data:\n";
	for (int i = 0; i < Obj.size; i++)
		in >> Obj.ptr[i];
	return in;
}

class Student
{
	char* name;
	int age;
public:
	Student(char* str = "No name", int age = 17) :age(age)
	{
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
	}
	~Student()
	{
		if (name)
			delete[] name;
	}
	friend istream& operator>>(istream& in, Student& Obj);
	friend ostream& operator<<(ostream& out, const Student& Obj);
};

istream& operator>>(istream& in, Student& Obj)
{
	char str[50];
	cout << "Enter name:";
	in >> str;
	if (Obj.name)
		delete[] Obj.name;
	Obj.name = new char[strlen(str) + 1];
	strcpy_s(Obj.name, strlen(str) + 1, str);
	cout << "Enter age:";
	in >> Obj.age;
	return in;
}

ostream& operator<<(ostream& out, const Student& Obj)
{
	out << "Name:" << Obj.name << "\nAge:" << Obj.age << endl;
	return out;
}


int _tmain(int argc, _TCHAR* argv[])
{
	/*Array<int> ar1(3);
	cin >> ar1;
	cout << ar1;
	Array<char> ar2(3);
	cin >> ar2;
	cout << ar2;

	Student st1;
	cin >> st1;
	cout << st1;*/

	Array<Student> ar3(3);
	cin >> ar3;
	cout << ar3;

	system("pause");
	return 0;
}

