#pragma once
#include "Student.h"
class Genius :
	public Student
{
public:

	Genius(std::string name, std::string surname, int attendance)
		: Student(name, surname, attendance) {}

	bool PassExam() override{
		return attendance;
	}
};

