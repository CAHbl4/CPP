#pragma once
#include "Record.h"
#include <list>

class TimeTable
{
	std::list<Record> records;
public:

	void AddRecord(Record record) {
		records.push_back(record);
	}

	void Show() const{
		for (Record record : records) {
			std::cout << record << std::endl;
		}
	}

	void Save(const char* fileName) {
		try {
			std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
			for (Record record : records) {
				record.Save(out);
			}
			out.close();
		}
		catch (std::exception &e) {
			std::cerr << e.what();
		}
	}
	
	void Load(const char* fileName) {
		try {
			std::ifstream in(fileName, std::ios::binary | std::ios::ate);
			int size = in.tellg();
			in.seekg(0, std::ios::beg);
			Record tmp;
			while (in.tellg() < size) {
				tmp.Load(in);
				AddRecord(tmp);
			}
		}
		catch (std::exception &e) {
			std::cerr << e.what();
		}
	}

	~TimeTable()
	{
	}
};

