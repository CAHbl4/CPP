#include "stdafx.h"
#include "String.h"

int String::created = 0;

String::String(int length) {
	string = new char[length + 1];
	++created;
	this->length = length;
}

String::String(const char* string) {
	this->string = new char[strlen(string) + 1];
	strcpy_s(this->string, strlen(string) + 1, string);
	++created;
	this->length = strlen(string);
}

//Не стал реализовывать очистку буфера. Сильно много костылей получится.
void String::InputString() {
	cin.getline(string, length + 1);
}

char* String::GetString() {
	return string;
}

int String::GetLength() {
	return length;
}

void String::ShowString() {
	cout << string << endl;
}

int String::GetCreated() {
	return created;
}


String::~String()
{
	if (string)
		delete[] string;
}
