#include "stdafx.h"
#include "Flat.h"


Flat::Flat(int count): count(count) {
	residents = new Man[count];
	char buf[256];
	for (int i = 0; i < count; ++i) {
		cout << "Enter name for resident " << i + 1 << ": ";
		cin.getline(buf, 256);
		residents[i].SetName(buf);
	}
}


Flat::Flat(const Flat& other) {
	count = other.count;
	residents = new Man[count];
	for (int i = 0; i < count; ++i)
		residents[i] = other.residents[i];
}


Flat& Flat::operator=(const Flat& other) {
	if (this == &other)
		return *this;
	if (residents)
		delete[] residents;
	count = other.count;
	residents = new Man[count];
	for (int i = 0; i < count; ++i)
		residents[i] = other.residents[i];
	return *this;
}


void Flat::AddResident(int count) {
	Man* tmp = new Man[this->count + count];
	for (int i = 0; i < this->count; ++i)
		tmp[i] = residents[i];

	char buf[256];

	for (int i = this->count; i < this->count + count; ++i) {
		cout << "Enter name for resident " << i + 1 << ": ";
		cin.getline(buf, 256);
		tmp[i].SetName(buf);
	}

	if (residents)
		delete[] residents;
	residents = tmp;
	this->count += count;
}


void Flat::DeleteResident(int id) {
	if (id < 1 || id > count) {
		cout << "Incorrect number of resident!\n";
		return;
	}
	Man* tmp = new Man[count - 1];
	for (int i = 0, j = 0; i < count; ++i) {
		if (id != i + 1)
			tmp[j++] = residents[i];
	}
	delete[] residents;
	residents = tmp;
	--count;
}


int Flat::GetCount() const {
	return count;
}


void Flat::ShowResidents() const {
	for (int i = 0; i < count; ++i) {
		cout << "Resident " << i + 1 << ": " << residents[i].GetName() << endl;
	}
}


Flat::~Flat() {
	if (residents)
		delete[] residents;
}
