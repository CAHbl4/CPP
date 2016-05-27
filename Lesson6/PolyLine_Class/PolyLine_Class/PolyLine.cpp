#include "stdafx.h"
#include "PolyLine.h"

PolyLine::PolyLine(const PolyLine& other)
{
	cout << "Copy constructor PolyLine\n";
	size = other.size;
	ptr = new Point[size];
	for (int i = 0; i < size; ++i)
		ptr[i].CopyData(other.ptr[i]);

}

void PolyLine::Add(int size)
{
	Point *tmp = new Point[this->size + size];

	if (ptr) {
		for (int i = 0; i < size; ++i)
			tmp[i].CopyData(ptr[i]);
		delete[] ptr;
	}

	for (int i = this->size; i < this->size + size; ++i)
		tmp[i].InputData();

	ptr = tmp;
	this->size += size;
}

void PolyLine::SetData()
{
	for (int i = 0; i < size; ++i)
		ptr[i].InputData();
}

void PolyLine::Show()
{
	for (int i = 0; i < size; ++i)
		ptr[i].Show();
}

PolyLine::~PolyLine()
{
	cout << "Destructor PolyLine\n";
	if (ptr)
		delete[] ptr;
}
