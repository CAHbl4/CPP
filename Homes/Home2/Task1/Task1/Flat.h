#pragma once
#include "Man.h"

class Flat {
	Man* residents;
	int count;
public:
	Flat(int count = 0);
	Flat(const Flat& other);

	Flat& operator=(const Flat& other);

	void AddResident(int count = 1);
	void DeleteResident(int id);

	int GetCount() const;

	void ShowResidents() const;

	~Flat();
};
