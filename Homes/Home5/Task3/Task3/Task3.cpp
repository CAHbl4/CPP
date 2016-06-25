// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Record.h"
#include "BinaryTree.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Record record(123);
	//record.AddPenalty(Date(1, 1, 2016), RedSignal, "Комментарий", 120);
	//record.AddPenalty(Date(1, 1, 2016), RedSignal, "Комментарий", 120);
	//record.AddPenalty(Date(1, 1, 2016), RedSignal, "Комментарий", 120);
	//cout << record;

	BinaryTree<int> tree;

	tree.Add(20);
	tree.Add(8);
	tree.Add(25);
	tree.Add(7);
	tree.Add(15);
	tree.Add(22);
	tree.Add(30);
	tree.Add(9);
	tree.Add(28);

	tree.Show(tree.GetRoot(), 0);
	tree.GetData().Show();

	system("pause");
	return 0;
}

