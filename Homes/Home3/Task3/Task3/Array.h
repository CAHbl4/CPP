#pragma once
class Array
{
	int size;
	int* ptr;
public:
	Array(int size = 0);
	Array(const Array& other);
	Array(Array&& other);

	Array& operator=(const Array& other);
	Array& operator=(Array&& other);

	Array& operator++();
	Array operator++(int);
	Array& operator--();
	Array operator--(int);

	void Set(int id, int value) const;
	int Get(int id) const;

	void Show() const;

	int& operator[](int id) const;

	~Array();
};
