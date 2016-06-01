#include "stdafx.h"
#include "Matrix.h"


void Matrix::FreeMem() const
{
	if (ptr)
	{
		for (int i = 0; i < rows; ++i)
			delete[] ptr[i];
		delete[] ptr;
	}
}


Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
	ptr = new int*[rows];
	for (int i = 0; i < rows; ++i)
		ptr[i] = new int[cols];
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			ptr[i][j] = rand() % 100;
}


Matrix::Matrix(const Matrix& other)
{
	rows = other.rows;
	cols = other.cols;
	ptr = new int*[rows];

	for (int i = 0; i < rows; ++i)
		ptr[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			ptr[i][j] = other.ptr[i][j];
}


Matrix& Matrix::operator=(const Matrix& other)
{
	if (this == &other)
		return *this;
	FreeMem();

	rows = other.rows;
	cols = other.cols;
	ptr = new int*[rows];

	for (int i = 0; i < rows; ++i)
		ptr[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			ptr[i][j] = other.ptr[i][j];

	return *this;
}


int& Matrix::operator()(int row, int col) const
{
	if (row >= 0 && row < rows && col >= 0 && col < cols)
		return ptr[row][col];
	cout << "Index out of bound exception\n";
	system("pause");
	exit(EXIT_FAILURE);
}


void Matrix::Show() const
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << ptr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}


Matrix::~Matrix()
{
	FreeMem();
}
