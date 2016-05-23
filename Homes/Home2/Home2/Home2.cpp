// Home2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Phonebook.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Phonebook book;
	book.AddRecord();
	book.AddRecord();
	book.AddRecord();
	book.ShowRecords();
	book.DeleteRecord(1);
	book.ShowRecords();
	int* search;
	int count;
	search = book.SearchByName("test", count);
	cout << "=================================================\n";
	cout << "Результаты поиска:\n";
	if (count)
		for (int i = 0; i < count; ++i) {
			book.ShowRecord(search[i]);
		}
	else {
		cout << "Совпадений не найдено.\n";
	}
	delete[] search;

	system("pause");
    return 0;
}

