#include "stdafx.h"
#include "Phonebook.h"

Phonebook::Phonebook()
{
	count = 0;
	allocated = 0;
	Reallocate();
}

void Phonebook::Reallocate(int count) {
	Record* tmp = new Record[allocated + count];

	for (int i = 0; i < this->count; ++i) {
		tmp[i].SetName(records[i].GetName());
		tmp[i].SetSurname(records[i].GetSurname());
		tmp[i].SetPatronymic(records[i].GetPatronymic());
		tmp[i].SetPhone(records[i].GetPhone());
	}
	delete[] records;
	records = tmp;
	allocated += count;
}

void Phonebook::AddRecord() {
	if (count == allocated)
		Reallocate();
	char tmp[50];

	cout << "---Запись " << count << "---\n";
	
	cout << "Введите Фамилию: ";
	cin >> tmp;
	records[count].SetSurname(tmp);

	cout << "Введите Имя: ";
	cin >> tmp;
	records[count].SetName(tmp);

	cout << "Введите Отчество: ";
	cin >> tmp;
	records[count].SetPatronymic(tmp);

	cout << "Введите телефон: ";
	cin >> tmp;
	records[count].SetPhone(tmp);

	++count;
}

void Phonebook::DeleteRecord(int id) {
	if (id >= 0 && id < count) {
		Record* tmp = new Record[count + 5];
		int i = 0, j = 0;
		while (j < count) {
			if (j == id)
				++j;
			tmp[i].SetName(records[j].GetName());
			tmp[i].SetSurname(records[j].GetSurname());
			tmp[i].SetPatronymic(records[j].GetPatronymic());
			tmp[i].SetPhone(records[j].GetPhone());
			++i;
			++j;
		}
		delete[] records;
		records = tmp;
		allocated = count + 5;
		--count;
	} else {
		cout << "Неверный id\n";
	}
}

int* Phonebook::SearchByName(const char* name, int& count) {
	count = 0;
	int* result = new int[this->count];

	for (int i = 0; i < this->count; ++i) {
		if(strstr(records[i].GetName(), name)) {
			result[count] = i;
			++count;
		}
	}
	return result;
}

void Phonebook::ShowRecords() {
	for (int i = 0; i < count; ++i) {
		cout << "---Запись " << i << "---\n";
		records[i].Show();
	}
}

void Phonebook::ShowRecord(int id) {
	if (id >= 0 && id < count) {
		records[id].Show();
	}
	else {
		cout << "Неверный id\n";
	}
}

Phonebook::~Phonebook()
{
	if (records)
		delete[] records;
}
