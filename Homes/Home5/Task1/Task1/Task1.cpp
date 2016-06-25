// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedStack.h"
#include <iostream>
#include "List.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LinkedStack<int> stack;
	stack.Push(2);
	stack.Push(4);
	stack.Push(7);
	stack.Show();
	cout << stack.Peek() << endl;
	stack.Show();
	stack.Pop();
	stack.Show();

	List<int> list1;
	list1.AddBack(1);
	list1.AddBack(2);
	list1.AddBack(3);
	list1.AddBack(4);
	list1.ShowList();
	List<int> list2(list1);
	list2.ShowList();
	List<int> list3;
	list3 = list1 + list2;
	list3.ShowList();
	list2.AddBack(5);
	list2.AddBack(6);
	list2.ShowList();
	list3 = list1 * list2;
	list3.ShowList();
	
	system("pause");
	return 0;
}

