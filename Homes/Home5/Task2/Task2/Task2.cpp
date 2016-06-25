// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
//#include "vld.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LinkedList<int> list;

	list.SetSize(5, 5);
	list.Show();
	list.SetSize(3, 5);
	list.Show();
	list.Add(1);
	list.Show();
	list.Add(2);
	list.Show();
	list.Add(3);
	list.Show();
	list.Add(4);
	list.Show();
	list[2] = 111;
	list.Show();
	list.SetAt(1, 222);
	list.FreeExtra();
	list.Show();
	list.SetSize(1, 5);
	list.Show();
	list.Add(4);
	list.Show();
	LinkedList<int> list2;
	list2.Add(222);
	list2.Add(333);
	list2.Add(444);
	list.Append(list2);
	list.Show();
	list2.Show();
	list2 = list;
	list2.Show();

	int* data = list2.GetData();
	for (int i = 0; i <= list.GetUpperBound(); ++i) 
		cout << data[i] << "\t";
	cout << endl;
	delete[] data;

	list2.InsertAt(2, 123);
	list2.Show();
	list2.RemoveAt(3);
	list2.Show();

	system("pause");
	return 0;
}

