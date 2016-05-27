#include "stdafx.h"
#include "Record.h"

Record::Record()
{
	surname = name = patronymic = phone = nullptr;
}

void Record::SetName(const char* str) {
	name = new char[strlen(str) + 1];
	strcpy_s(name, strlen(str) + 1, str);
}

void Record::SetSurname(const char* str) {
	surname = new char[strlen(str) + 1];
	strcpy_s(surname, strlen(str) + 1, str);
}

void Record::SetPatronymic(const char* str) {
	patronymic = new char[strlen(str) + 1];
	strcpy_s(patronymic, strlen(str) + 1, str);
}

void Record::SetPhone(const char* str) {
	phone = new char[strlen(str) + 1];
	strcpy_s(phone, strlen(str) + 1, str);
}

char* Record::GetName() {
	return name;
}

char* Record::GetSurname() {
	return surname;
}

char* Record::GetPatronymic() {
	return patronymic;
}

char* Record::GetPhone() {
	return phone;
}

void Record::Show() {
	cout << "Фамилия: " << surname << endl;
	cout << "Имя: " << name << endl;
	cout << "Отчество: " << patronymic << endl;
	cout << "Телефон: " << phone << endl;
}


Record::~Record()
{
	if (surname)
		delete[] surname;
	if (name)
		delete[] name;
	if (patronymic)
		delete[] patronymic;
	if (phone)
		delete[] phone;
}
