#pragma once
#include <string>

class Student {
protected:
	std::string name;
	std::string surname;
	int attendance;
public:
	Student(std::string name, std::string surname, int attendance)
		: name(name),
		  surname(surname),
		  attendance(attendance) {}

	virtual bool PassExam() = 0;


	std::string GetName() const {
		return name;
	}

	std::string GetSurname() const {
		return surname;
	}

	int GetAttendance() const {
		return attendance;
	}

	virtual ~Student() { }
};
