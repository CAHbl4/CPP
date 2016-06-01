#pragma once
class Matrix
{
	int rows;
	int cols;
	int **ptr;
	void FreeMem() const;
public:
	Matrix(int rows = 0, int cols = 0);

	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	int& operator()(int row, int col) const;

	void Show() const;

	~Matrix();
};

