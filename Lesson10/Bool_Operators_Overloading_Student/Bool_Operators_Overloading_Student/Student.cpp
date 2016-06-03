#include "stdafx.h"
#include "Student.h"

int Student::countStudent = 0;

Student::Student(char* name, char* surname, int age): age(age) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);

	++countStudent;
}


Student::Student(const Student& other) {
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	surname = new char[strlen(other.surname) + 1];
	strcpy_s(surname, strlen(other.surname) + 1, other.surname);

	age = other.age;

	++countStudent;
}


Student& Student::operator=(const Student& other) {
	if (this == &other)
		return *this;
	if (this->name)
		delete[] name;
	if (surname)
		delete[] surname;

	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	surname = new char[strlen(other.surname) + 1];
	strcpy_s(surname, strlen(other.surname) + 1, other.surname);

	age = other.age;

	return *this;
}


bool Student::operator==(const Student& other) const {
	if (strcmp(name, other.name))
		return false;
	if (strcmp(surname, other.surname))
		return false;
	return true;
}


Student::~Student() {
	if (name)
		delete[] name;
	if (surname)
		delete[] surname;

	--countStudent;
}


istream& operator>>(istream& in, Student& obj) {
	char str[256];
	cout << "Enter name: ";
	in.ignore(in.rdbuf()->in_avail());
	in.getline(str, 256);
	if (obj.name)
		delete[] obj.name;
	obj.name = new char[strlen(str) + 1];
	strcpy_s(obj.name, strlen(str) + 1, str);

	cout << "Enter surname: ";
	in.ignore(in.rdbuf()->in_avail());
	in.getline(str, 256);
	if (obj.surname)
		delete[] obj.surname;
	obj.surname = new char[strlen(str) + 1];
	strcpy_s(obj.surname, strlen(str) + 1, str);

	cout << "Enter age: ";
	in >> obj.age;
	in.ignore(in.rdbuf()->in_avail());

	return in;
}


ostream& operator<<(ostream& out, const Student& obj) {
	out << "Name: " << obj.name << endl;
	out << "Surname: " << obj.surname << endl;
	out << "Age: " << obj.age << endl;
	out << "Count od Students:" << obj.countStudent << endl;
	return out;
}
