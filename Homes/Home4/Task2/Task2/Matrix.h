#pragma once
template <class T>
class Matrix {
	int rows, cols;
	T** ptr;
public:
	Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
		ptr = new T*[rows];
		for (int i = 0; i < rows; ++i) {
			ptr[i] = new T[cols];
		}
	}

	Matrix(const Matrix& other) {
		rows = other.rows;
		cols = other.cols;

		ptr = new T*[rows];
		for (int i = 0; i < rows; ++i) {
			ptr[i] = new T[cols];
			for (int j = 0; j < cols; ++j) {
				ptr[i][j] = other.ptr[i][j];
			}
		}

	}

	Matrix& operator=(const Matrix& other) {
		if (this == &other)
			return *this;
		ClearMemory();
		rows = other.rows;
		cols = other.cols;

		ptr = new T*[rows];
		for (int i = 0; i < rows; ++i) {
			ptr[i] = new T[cols];
			for (int j = 0; j < cols; ++j) {
				ptr[i][j] = other.ptr[i][j];
			}
		}
		return *this;
	}

	void ClearMemory() {
		if (ptr)
			for (int i = 0; i < rows; i++)
				delete[] ptr[i];
		delete[] ptr;
	}

	void Show() const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << ptr[i][j] << "\t";
			cout << endl;
		}
		cout << endl;
	}

	void FillRand() {
		for (int i = 0; i < cols; ++i) {
			for (int j = 0; j < rows; ++j) {
				ptr[i][j] = rand() % 10;
			}
		}
	}

	void FindMin() const {
		int row = 0, col = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (ptr[i][j] < ptr[row][col]) {
					row = i;
					col = j;
				}
			}
		}
		cout << "Min[" << row << "][" << col << "] = " << ptr[row][col] << endl;
	}

	void FindMax() const {
		int row = 0, col = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (ptr[i][j] > ptr[row][col]) {
					row = i;
					col = j;
				}
			}
		}
		cout << "Max[" << row << "][" << col << "] = " << ptr[row][col] << endl;
	}

	friend istream& operator>><T>(istream& is, Matrix<T>& obj);

	Matrix operator+(const Matrix& other) {
		if (rows == other.rows && cols == other.cols) {
			Matrix<T> tmp(rows, cols);
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					tmp.ptr[i][j] = ptr[i][j] + other.ptr[i][j];
			return tmp;
		}
		throw invalid_argument("Matrices should be same size.");
	}

	Matrix operator-(const Matrix& other) {
		if (rows == other.rows && cols == other.cols) {
			Matrix<T> tmp(rows, cols);
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					tmp.ptr[i][j] = ptr[i][j] - other.ptr[i][j];
			return tmp;
		}
		throw invalid_argument("Matrices should be same size.");
	}

	Matrix operator*(const Matrix& other) {
		if (cols == other.rows) {
			Matrix<T> tmp(rows, other.cols);

			for (int i = 0; i < tmp.rows; ++i)
				for (int j = 0; j < tmp.cols; ++j) {
					tmp.ptr[i][j] = 0;
					for (int k = 0; k < cols; ++k)
						tmp.ptr[i][j] += ptr[i][k] * other.ptr[k][j];
				}

			return tmp;
		}
		throw invalid_argument("Second matrix rows count should be equal to first matrix columns count.");
	}

	~Matrix() {
		ClearMemory();
	}

};

template <class T>
istream& operator>>(istream& is, Matrix<T>& obj) {
	for (int i = 0; i < obj.cols; ++i) {
		for (int j = 0; j < obj.rows; ++i) {
			cout << "Matrix[" << i << "][" << j << "]: ";
			is >> obj.ptr[i][j];
		}
	}
	return is;
}
