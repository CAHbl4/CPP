#pragma once
#include "String.h"
#include "Job.h"
#include <fstream>
#include <string>

class PrinterLog
{
	String fileName;
public:
	PrinterLog(const String& fileName = "log.txt")
		: fileName(fileName) {}

	void operator<<(const Job& job) const {
		std::ofstream fout(fileName, std::ios::out | std::ios::app);
		if (fout.is_open()) {
			fout << job;
			fout.close();
		}
	}

	void ShowLog() const {
		std::ifstream fin(fileName);
		std::string line;
		if (fin.is_open()) {
			while (std::getline(fin, line)) {
				std::cout << line << '\n';
			}
		}
	}
};
