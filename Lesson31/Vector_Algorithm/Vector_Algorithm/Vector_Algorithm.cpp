// Vector_Algorithm.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;


int f(int x)
{
	x = rand() % 100;
	return x;
}
template<class T>
void show(T x)
{

	cout << x << "\t";
}

class Person
{
	string name;
	int age;
public:
	Person(string str = "\0", int a = 0) :name(str), age(a)
	{}
	void Passport()
	{
		std::cout << "Name:"<< name << "\nAge:" << age << endl;
	}
	friend ostream& operator<<(ostream& out, const Person& Obj);
	
};

ostream& operator<<(ostream& out, const Person& Obj)
{
	out << "Name:" << Obj.name << "\nAge:" << Obj.age << endl;
	return out;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//создаем два вектора размерностью 5(элементы нулевые);
	vector<int> v1(5);
	vector<int> v2(5);
	//примен€ем алгоритм transform
	//измен€ющий значени€ элементов и сохран€ющий их
	//в новом векторе
	transform(v1.begin(), v1.end(),v2.begin(), f);
	//выводим v1
	for_each(v1.begin(), v1.end(), show<int>);
	cout << endl;
	//выводим v2
	for_each(v2.begin(), v2.end(), show<int>);
	cout << endl;
	//обмен содержимым контейнеров
	v1.swap(v2);
	//выводим v1
	for_each(v1.begin(), v1.end(), show<int>);
	cout << endl;
	//выводим v2
	for_each(v2.begin(), v2.end(), show<int>);
	cout << endl;

	//методы insert и erase
	v2[0] = 11;
	v2.at(3) = 44;
	cout << "---------------------------------\n";
	//выводим v2
	for_each(v2.begin(), v2.end(), show<int>);
	cout << endl;
	//втавл€ем элемент на вторую позицию значение 22
	v2.insert(v2.begin()+1,22);
	//выводим v2
	for_each(v2.begin(), v2.end(), show<int>);
	cout << endl;
	//удал€ем элемент с 4 позиции
	v2.erase(v2.begin() + 4);
	//выводим v2
	for_each(v2.begin(), v2.end(), show<int>);
	cout << endl;
	v2.at(4) = 55;
	for_each(v2.begin(), v2.end(), show<int>);
	cout << endl;

	//методы empty, back, pop_back
	while (!v2.empty())
	{
		cout << v2.back() << "\t";
		v2.pop_back();
	}
	cout << "\nsize v2=" << v2.size() << endl;
	cout << "-------------------------------\n";
	//создадим группу Person
	vector<Person> v3;
	v3.push_back(Person("Alex", 25));
	v3.push_back(Person("Max", 27));
	v3.push_back(Person("Mary", 22));
	for_each(v3.begin(), v3.end(), show<Person>);
	cout << endl;

	//запись в файл
	ofstream out("test.dat", ios::binary);
	if (!out)
		//стандартный поток вывода без использовани€ буфера
		cerr << "Error!!!\n";
	for (auto a : v1)
	{
		out.write(reinterpret_cast<char*>(&a), sizeof(int));
	}
	out.close();

	//считывание из файла
	ifstream in1("test.dat", ios::binary);
	in1.clear();
	in1.seekg(0, ios::end);
	//определ€ем размер файла
	int n = in1.tellg();
	//определ€ем размер вектора
	int size = n / sizeof(int);
	vector<int> v5(size);
	in1.clear();
	in1.seekg(0);
	for (int i = 0; i < size; i++)
	{
		in1.read(reinterpret_cast<char*>(&n), sizeof(int));
		v5[i] = n;
	}
	in1.close();
	cout << "Read from file\n";
	for_each(v5.begin(), v5.end(), show<int>);
	cout << endl;



	system("pause");
	return 0;
}

