// Class_Data.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<ctime>

using namespace std;

//описание шаблонного класса
template<class T>
class Test
{
	T *data;
public:
	explicit Test(T value)
	{
		data = new T;
		*data = value;
	}
	~Test()
	{
		if (data)
			delete data;
	}
	void ShowData()
	{
		cout << "Data: " << *data << endl;
	}
};

//шаблонный класс для динамического массива
template<class T>
class Array
{
	int size;
	T* ptr;
public:
	Array(int size) :size(size)
	{
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = float(rand() % 100) / 10;
	}
	~Array()
	{
		if (ptr)
			delete[] ptr;
	}
	void ShowArray()
	{
		for (int i = 0; i < size; i++)
			cout << ptr[i] << "\t";
		cout << endl;
	}
};

template<class T1, class T2>
class Pair
{
	T1 one;
	T2 two;
public:
	explicit Pair(T1 one, T2 two) :one(one), two(two){}
	void ShowPair()
	{
		cout << "Para : " << one << "-" << two << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	//Инстанцирование шаблонного класса для int
	Test<int> t1(5);
	t1.ShowData();
	//Инстанцирование шаблонного класса для char
	Test<char> t2(4);
	t2.ShowData();
	cout << "-----------------------------------------------------\n";
	Array<int> ar1(5);
	ar1.ShowArray();
	Array<float> ar2(5);
	ar2.ShowArray();
	Array<char> ar3(5);
	ar3.ShowArray();
	cout << "-----------------------------------------------------\n";
	Pair<int, double> p1(1, 2.3);
	Pair<int, int> p2(5.5, 6);
	Pair<char, float> p3('E', 2.71);
	p1.ShowPair();
	p2.ShowPair();
	p3.ShowPair();
	system("pause");
	return 0;
}

