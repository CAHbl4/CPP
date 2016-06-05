#pragma once
#include "Flat.h"

class Building {
	Flat* flats;
	int count;
public:
	Building(int count = 0);
	Building(const Building& other);

	Building& operator=(const Building& other);

	void AddFlat(int count = 1);

	void AddResidentToFlat(int flatNum, int count) const;

	void AddFlat(const Flat& flat);

	void DeleteFlat(int id);

	void Show() const;

	~Building();
};
