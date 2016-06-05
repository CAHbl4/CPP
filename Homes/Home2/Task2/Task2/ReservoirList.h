#pragma once
#include "Reservoir.h"

class ReservoirList
{
	Reservoir* ptr;
	int count;
public:
	ReservoirList(int count = 0);
	ReservoirList(const ReservoirList& other);
	ReservoirList& operator=(const ReservoirList& other);

	void Add(const Reservoir& reservoir);
	Reservoir& Get(int index) const;
	void Set(int index, const Reservoir& value) const;
	void Remove(int index);
	void Clear();
	int GetCount() const;
	void Show() const;

	Reservoir& operator[](int index) const;

	int Export(const char* fileName) const;

	int Save(const char* fileName) const;
	int Load(const char* fileName);

	~ReservoirList();
};

