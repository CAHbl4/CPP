// Using_Vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//для работы с вектором
#include<vector>
//для работы с алгоритмами
#include<algorithm>

using namespace std;

template<class T>
void show(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
}

//функция для алгоритма for_each
template<class T>
void print(T x)
{
	cout << x << "\t";
}



int _tmain(int argc, _TCHAR* argv[])
{
	//создание
	vector<int> v1;//создание пустого вектора
	vector<double> v2(5);//вектор из 5 элементов вещественного типа
	vector<char> v3 = { 'A', 'B', 'C' };//вектор из 3 символов
	//обычный массив
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	//создание из существующего массива
	vector<int> v4(arr, arr + 5);
	vector<char> v5(3, '!');//вектор из 3 сиволов !
	
	//вывод стандартный
	cout << "---------V1-------------\n";
	show(v1);
	cout << "---------V2-------------\n";
	show(v2);
	cout << "---------V3-------------\n";
	show(v3);
	cout << "---------V4-------------\n";
	show(v4);
	cout << "---------V5-------------\n";
	show(v5);
	
	//вывод с использованием алгоритма for_each
	cout << "----------For_Each-----------\n";
	for_each(v4.begin(), v4.end(), print<int>);
	cout << endl;
	for_each(v4.begin(), v4.end(), print<char>);
	cout << endl;

	//вывод цикла for (стандарт C++11)
	cout << "---------------For-----------------\n";
	
	for (auto a : v4)
	{
		cout << a << "\t";
	}
	cout << endl;

	
	for each(auto a in v4)
	{
		cout << a << "\t";
	}
	cout << endl;
	//присваивание значений
	cout << "--------------Vector V1------------\n";
	//заполнить одинаковыми значениями
	v1.assign(5, 1);
	for (auto a : v1)
	{
		cout << a << "\t";
	}
	cout << endl;
	//добавление в конец и только
	v1.push_back(5);
	v1.push_back(7);
	show(v1);
	//изменение значений
	v1[3] = 33;
	v1.at(0) = 100;
	show(v1);







	system("pause");
	return 0;
}

