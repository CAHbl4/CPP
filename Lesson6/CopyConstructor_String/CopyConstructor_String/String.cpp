#include "stdafx.h"
#include "String.h"

String::String(char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, str);
}

String::String(const String& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy_s(str, size + 1, other.str);
}
