#pragma once
class Array
{
	int size;
	int* ptr;
public:
	Array(int size = 0) : size(size)
	{
		ptr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = rand() % 100;
		}
	}

	Array(const Array& other);

	void Show();

	Array& operator=(const Array& other);
	Array& operator++();
	Array operator++(int);

	Array& operator--();
	Array operator--(int);

	void Set(int id, int value) const;
	int Get(int id) const;

	int& operator[](int id);

	~Array()
	{
		if (ptr)
			delete[] ptr;
	}
};
