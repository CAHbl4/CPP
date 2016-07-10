#pragma once
#include "Student.h"
class Smart :
	public Student
{
public:
	Smart(std::string name, std::string surname, int attendance)
		: Student(name, surname, attendance) {}

	bool PassExam() override {
		if (attendance == 20)
			return true;
		if (attendance > 10)
			return rand() % 100 < 70;
		return false;
	}
};

