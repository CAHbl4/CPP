#pragma once
#include "Record.h"
#include "BinaryTree.h"

class Base
{
	BinaryTree<Record> records;
public:
	void AddRecord(Record record) {
		if (records.Search(record))
			records.Get(record).GetList().Append(record.GetList());
		else records.Add(record);
	}

	void AddRecord(int number, Penalty penalty) {
		Record record(number);
		record.AddPenalty(penalty);
		AddRecord(record);
	}

};

