#include "stdafx.h"
#include "Man.h"


Man::Man(const char* name) : length(strlen(name)) {
	this->name = new char[length + 1];
	strcpy_s(this->name, length + 1, name);
};


Man::Man(const Man& other) {
	length = other.length;
	name = new char[length + 1];
	strcpy_s(name, length + 1, other.name);
}


char* Man::GetName() const {
	return name;
}


void Man::SetName(const char* name) {
	if (this->name)
		delete[] this->name;
	length = strlen(name);
	this->name = new char[length + 1];
	strcpy_s(this->name, length + 1, name);
}


Man& Man::operator=(const Man& other) {
	if (this == &other)
		return *this;
	if (name)
		delete[] name;
	length = other.length;
	name = new char[length + 1];
	strcpy_s(name, length + 1, other.name);
	return *this;
}


Man::~Man() {
	if (name)
		delete[] name;
}
