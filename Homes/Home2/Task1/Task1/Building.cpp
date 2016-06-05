#include "stdafx.h"
#include "Building.h"


Building::Building(int count): count(count) {
	flats = new Flat[count];
}


Building::Building(const Building& other) {
	count = other.count;
	flats = new Flat[count];
	for (int i = 0; i < count; ++i)
		flats[i] = other.flats[i];
}


Building& Building::operator=(const Building& other) {
	if (this == &other)
		return *this;
	if (flats)
		delete[] flats;
	count = other.count;
	flats = new Flat[count];
	for (int i = 0; i < count; ++i)
		flats[i] = other.flats[i];
	return *this;
}


void Building::AddFlat(int count) {
	Flat* tmp = new Flat[this->count + count];
	for (int i = 0; i < this->count; ++i) {
		tmp[i] = flats[i];
	}
	if (flats)
		delete[] flats;

	flats = tmp;

	this->count += count;
}


void Building::AddFlat(const Flat& flat) {
	Flat* tmp = new Flat[count + 1];
	for (int i = 0; i < count; ++i) {
		tmp[i] = flats[i];
	}
	if (flats)
		delete[] flats;

	tmp[count] = flat;
	flats = tmp;
	++count;
}


void Building::AddResidentToFlat(int flatNum, int count) const {
	if (flatNum < 1 || flatNum > this->count) {
		cout << "Incorrect number of flat!\n";
		return;
	}
	flats[flatNum - 1].AddResident(count);
}


void Building::DeleteFlat(int id) {
	if (id < 1 || id > count) {
		cout << "Incorrect number of flat!\n";
		return;
	}
	Flat* tmp = new Flat[count - 1];
	for (int i = 0, j = 0; i < count; ++i) {
		if (id != i + 1)
			tmp[j++] = flats[i];
	}
	delete[] flats;
	flats = tmp;
	--count;
}


void Building::Show() const {
	cout << "The building has " << count << " flats.\n";
	for (int i = 0; i < count; ++i) {
		cout << "The flat " << i + 1 << " has " << flats[i].GetCount() << " residents.\n";
		flats[i].ShowResidents();
	}
}


Building::~Building() {
	if (flats)
		delete[] flats;
}
