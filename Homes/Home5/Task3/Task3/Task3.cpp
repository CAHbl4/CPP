// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Record.h"
#include "Base.h"
//#include <vld.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Record record(123);
	record.AddPenalty(Date(4, 3, 2014), RedSignal, "Комментарий 1", 120);
	record.AddPenalty(Date(25, 7, 2015), SpeedLimit, "Комментарий 2", 140);
	record.AddPenalty(Date(31, 9, 2015), DoubleLine, "Комментарий 3", 80);

	Base base;
	
	base.AddRecord(record);

	record.SetNumber(124);
	base.AddRecord(record);

	Record record2(123);
	record2.AddPenalty(Date(17, 10, 2016), SpeedLimit, "Новый комментарий", 90);
	base.AddRecord(record2);

	record2.SetNumber(100);
	base.AddRecord(record2);

	record2.SetNumber(130);
	base.AddRecord(record2);
	record2.SetNumber(90);
	base.AddRecord(record2);
	record2.SetNumber(110);
	base.AddRecord(record2);
	record2.SetNumber(118);
	base.AddRecord(record2);
	record2.SetNumber(101);
	base.AddRecord(record2);
	record2.SetNumber(125);
	base.AddRecord(record2);

	base.Show();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Проверяем поиск по номеру\n";
	base.Show(100);
	base.Show(102);
	base.ShowFromTo(90, 125);

	system("pause");
	return 0;
}

