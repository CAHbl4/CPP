// List.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include<iostream>
#include<list>
#include<algorithm>
#include<fstream>
#include<functional>
#include<iterator>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	list<int> l1;
	for (int i = 0; i < 3; i++)
	{
		l1.push_back(rand() % 10);
		l1.push_front(rand() % 10);
	}
	//вывод 
	ostream_iterator<int> outiter(cout, "\t");
	cout << "List:\n";
	copy(l1.begin(), l1.end(), outiter);
	cout << endl;

	//сортировка
	l1.sort();
	cout << "Sort List:\n";
	copy(l1.begin(), l1.end(), outiter);
	cout << endl;

	//обратна€ перестановка
	l1.reverse();
	cout << "Revers List:\n";
	copy(l1.begin(), l1.end(), outiter);
	cout << endl;
	l1.reverse();

	//объединение
	list<int> l2 = { 2, 5, 9,4,3 };
	l2.sort();
	cout << "List2:\n";
	copy(l2.begin(), l2.end(), outiter);
	cout << endl;
	//list<int> l3(l1.size()+l2.size());
 	l1.merge(l2);
	cout << "List1:\n";
	copy(l1.begin(), l1.end(), outiter);
	cout << endl;
	//удаление повтор€ющихс€ элементов
	l1.unique();
	cout << "List1:\n";
	copy(l1.begin(), l1.end(), outiter);
	cout << endl;
	int a = 44;
	auto iter = find(l1.begin(), l1.end(), a);
	if (iter == l1.end())
		cout <<a<<" not exist\n";
	else
		cout <<a<<" exist\n";

	system("pause");
	return 0;
}

