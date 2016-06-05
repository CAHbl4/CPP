#include "stdafx.h"
#include "Reservoir.h"


void ShowTypes() {
	cout << "Available types:\n"
		<< Pool << ". Pool\n"
		<< Pond << ". Pond\n"
		<< Lake << ". Lake\n"
		<< Sea << ". Sea\n"
		<< Ocean << ". Ocean\n";
}


istream& operator>>(istream& is, ReservoirType& rval) {
	unsigned int type = ReservoirType_COUNT;
	while (true) {
		if (is >> type) {
			if (type >= ReservoirType_COUNT)
				cout << "Wrong type. Try again: ";
			else
				break;
		}
		else {
			is.clear();
			is.sync();
		}

	}
	rval = ReservoirType(type);
	return is;
}


Reservoir::Reservoir(char* const name, ReservoirType type, float width, float length, float maxDepth) :
	type(type),
	width(width),
	length(length),
	maxDepth(maxDepth) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


Reservoir::Reservoir(const Reservoir& other) :
	type(other.type),
	width(other.width),
	length(other.length),
	maxDepth(other.maxDepth) {
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
}


Reservoir& Reservoir::operator=(const Reservoir& other) {
	if (this == &other)
		return *this;
	if (name)
		delete[] name;
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	type = other.type;
	width = other.width;
	length = other.length;
	maxDepth = other.maxDepth;
	return *this;
}


const char* Reservoir::GetName() const {
	return name;
}


ReservoirType Reservoir::GetType() const {
	return type;
}


float Reservoir::GetWidth() const {
	return width;
}


float Reservoir::GetLength() const {
	return length;
}


float Reservoir::GetMaxDepth() const {
	return maxDepth;
}


void Reservoir::SetName(char* name) {
	if (this->name)
		delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


void Reservoir::SetType(ReservoirType type) {
	this->type = type;
}


void Reservoir::SetWidth(float width) {
	this->width = width;
}


void Reservoir::SetLength(float length) {
	this->length = length;
}


void Reservoir::SetMaxDepth(float maxDepth) {
	this->maxDepth = maxDepth;
}


ostream& operator<<(ostream& os, const Reservoir& obj) {
	os
		<< "Name: " << obj.name << endl
		<< "Type: ";
	switch (obj.type) {
	case Pool: os << "Pool";
		break;
	case Pond: os << "Pond";
		break;
	case Lake: os << "Lake";
		break;
	case Sea: os << "Sea";
		break;
	case Ocean: os << "Ocean";
		break;
	}
	os << endl
		<< "Width: " << obj.width << endl
		<< "Length: " << obj.length << endl
		<< "Max Depth: " << obj.maxDepth << endl;
	return os;
}


istream& operator>>(istream& is, Reservoir& obj) {
	char str[256];
	cout << "Enter name: ";
	is.ignore(is.rdbuf()->in_avail());
	is.getline(str, 256);
	obj.SetName(str);
	ShowTypes();
	cout << "Select type: ";
	is.ignore(is.rdbuf()->in_avail());
	is >> obj.type;
	cout << "Enter width: ";
	is >> obj.width;
	cout << "Enter length: ";
	is >> obj.length;
	cout << "Enter max depth: ";
	is >> obj.maxDepth;
	return is;
}


Reservoir::~Reservoir() {
	if (name)
		delete[] name;
}
