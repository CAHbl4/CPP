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

	void Show() const {
		records.GetData().Show();
	}

	void Show(int number) {
		Record search(number);
		if (records.Search(search))
			std::cout << records.Get(Record(search));
		else
			std::cout << "Запись не найдена\n";
	}

	void ShowFromTo(int left, int right) const {
		LinkedList<Record> data = records.GetData();
		for (int i = 0; i <= data.GetUpperBound(); ++i) {
			if (data[i].GetNumber() >= left &&data[i].GetNumber() <= right)
				std::cout << data[i];
		}
	}
};

