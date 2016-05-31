#include "stdafx.h"
#include "Array.h"


Array::Array(const Array& other)
{
	size = other.size;
	ptr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = other.ptr[i];
	}
}


void Array::Show()
{
	for (int i = 0; i < size; ++i)
		cout << ptr[i] << "\t";
	cout << endl;
}

Array& Array::operator=(const Array& other)
{
	if (this == &other)
		return *this;
	if (ptr)
		delete[] ptr;
	size = other.size;
	ptr = new int[size];

	for (int i = 0; i < size; ++i)
		ptr[i] = other.ptr[i];
	return *this;
}

Array& Array::operator++()
{
	int* ptrNew = new int[size + 1];
	for (int i = 0; i < size; ++i)
	{
		ptrNew[i + 1] = ptr[i];
	}
	ptrNew[0] = rand() % 100;
	if (ptr)
		delete[] ptr;
	ptr = ptrNew;
	size++;
	return *this;
}

Array Array::operator++(int)
{
	Array tmp = *this;
	if (ptr)
		delete[] ptr;
	ptr = new int[++size];
	for (int i = 0; i < size - 1; ++i)
	{
		ptr[i] = tmp.ptr[i];
	}
	ptr[size - 1] = rand() % 100;
	return tmp;
}

Array& Array::operator--()
{
	if (!size)
	{
		cout << "An array is empty!";
		return *this;
	}

	int* ptrNew = new int[--size];
	for (int i = 1; i < size + 1; ++i)
	{
		ptrNew[i - 1] = ptr[i];
	}
	if (ptr)
		delete[] ptr;
	ptr = ptrNew;
	return *this;
}

Array Array::operator--(int)
{
	if (!size)
	{
		cout << "An array is empty!";
		return *this;
	}
	Array tmp = *this;
	if (ptr)
		delete[] ptr;
	ptr = new int[--size];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = tmp.ptr[i];
	}
	return tmp;
}

void Array::Set(int id, int value) const
{
	if (id < 0 || id >= size)
	{
		cout << "Index out of bound exception";
		exit(EXIT_FAILURE);
	}
	ptr[id] = value;
}

int Array::Get(int id) const
{
	if (id < 0 || id >= size)
	{
		cout << "Index out of bound exception";
		exit(EXIT_FAILURE);
	}
	return ptr[id];
}

int& Array::operator[](int id)
{
	if (id < 0 || id >= size)
	{
		cout << "Index out of bound exception";
		exit(EXIT_FAILURE);
	}
	return ptr[id];
}

