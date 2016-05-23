#pragma once
#include "Record.h"

class Phonebook
{
	Record* records;
	int count;
	int allocated;
	void Reallocate(int count = 5);
public:
	void AddRecord();
	void DeleteRecord(int id);

	int* SearchByName(const char* name, int& count);

	void ShowRecords();
	void ShowRecord(int id);
	
	Phonebook();
	~Phonebook();
};

