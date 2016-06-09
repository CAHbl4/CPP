#include "stdafx.h"
#include "String.h"


String::String(const char* str):
	length(strlen(str)) {
	std::cout << "Default!\n";
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
}

String::String(const String& other)
	: length(other.length) {
	std::cout << "Copy!\n";
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, other.str);
}

String::String(String&& other)
	: length(other.length),
	  str(other.str) {
	std::cout << "Move!\n";
	other.str = nullptr;
	other.length = 0;
}

String& String::operator=(const String& other) {
	if (this == &other)
		return *this;
	if (str)
		delete[] str;
	length = other.length;
	str = new char[length + 1];
	strcpy_s(this->str, length + 1, other.str);
	return *this;
}

String& String::operator=(String&& other) {
	if (this == &other)
		return *this;
	length = other.length;
	str = other.str;
	other.str = nullptr;
	other.length = 0;
	return *this;
}

String String::operator+(const String& obj) const  {
	String temp;
	temp.length = length + obj.length;
	temp.str = new char[temp.length + 1];
	strcpy_s(temp.str, temp.length + 1, str);
	strcat_s(temp.str, temp.length + 1, obj.str);
	return temp;
}

String::~String() {
	if (str)
		delete[] str;
}