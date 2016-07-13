// Deque.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<deque>
#include<algorithm>
#include<iterator>
#include<functional>
#include<vector>
#include<queue>
#include<stack>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	deque<int> q1 = { 4, 2, 8, 6, 7, 3};
	ostream_iterator<int> outiter(cout, "\t");
	cout << "Q1:\n";
	copy(q1.begin(), q1.end(), outiter);
	cout << endl;

	//сортировка
	sort(q1.begin(), q1.end());
	cout << "Sort Q1:\n";
	copy(q1.begin(), q1.end(), outiter);
	cout << endl;

	//вставка элементов  в начало и конец
	deque<int> q2;
	for (int i = 0; i < 2; i++)
	{
		q2.push_front(rand() % 10);
		q2.push_back(rand() % 10);
	}

	cout << "Q2:\n";
	copy(q2.begin(), q2.end(), outiter);
	cout << endl;
	//сортируем 
	sort(q2.begin(), q2.end());
	cout << "Sort Q2:\n";
	copy(q2.begin(), q2.end(), outiter);
	cout << endl;

	//объединение отсортированных контейнеров
	deque<int> q3(q1.size()+q2.size());
	merge(q1.begin(), q1.end(), q2.begin(), q2.end(), q3.begin());
	cout << "Q3:\n";
	copy(q3.begin(), q3.end(), outiter);
	cout << endl;

	//запись результата в вектор
	vector<int> v1(q1.size() + q2.size());
	merge(q1.begin(), q1.end(), q2.begin(), q2.end(), v1.begin());
	cout << "V1:\n";
	copy(v1.begin(), v1.end(), outiter);
	cout << endl;

	//Контейнеры Queue, Stack
	queue<int> qu1;
	qu1.push(1);
	qu1.push(5);
	qu1.push(7);
	cout << "Qu1:\n";
	while (!qu1.empty())
	{
		cout << qu1.front() << "\t";
		qu1.pop();
	}
	cout << endl;

	stack<int> st1;
	st1.push(1);
	st1.push(5);
	st1.push(7);
	cout << "St1:\n";
	while (!st1.empty())
	{
		cout << st1.top() << "\t";
		st1.pop();
	}
	cout << endl;



	system("pause");
	return 0;
}

