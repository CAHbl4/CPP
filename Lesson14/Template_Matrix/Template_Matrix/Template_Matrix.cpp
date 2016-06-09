// Template_Matrix.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class Matrix
{
	int rows;
	int cols;
	T **ptr;
	void ClearMemory()
	{
		//������� ���������� ��� ������� ������
		if (ptr)
		for (int i = 0; i < rows; i++)
			delete[] ptr[i];
		delete[] ptr;
	}
public:
	//����������� � ����������� � �� ���������
	Matrix(int rows = 0, int cols = 0) :rows(rows), cols(cols)
	{
		//�������� ������
		ptr = new T*[rows];
		for (int i = 0; i < rows; i++)
			ptr[i] = new T[cols];
		//��������� ������� ���������� ����������
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			ptr[i][j] = rand() % 100;
	}
	//����������� �����������
	Matrix(const Matrix& Obj)
	{
		//�������� ������
		rows = Obj.rows;
		cols = Obj.cols;
		ptr = new T*[rows];
		for (int i = 0; i < rows; i++)
			ptr[i] = new T[cols];
		//�������� ��������
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			ptr[i][j] = Obj.ptr[i][j];
	}

	//���������� ��������� ������������
	Matrix& operator=(const Matrix& Obj)
	{
		//�������� �� ����������������
		if (this == &Obj)
			return *this;
		//������� ������
		ClearMemory();
		//�������� ����� ������
		rows = Obj.rows;
		cols = Obj.cols;
		ptr = new T*[rows];
		for (int i = 0; i < cols; i++)
			ptr[i] = new T[cols];
		//�������� ��������
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			ptr[i][j] = Obj.ptr[i][j];
		return *this;
	}
	//����������
	~Matrix()
	{
		ClearMemory();
	}

	//���������� ��������� ������ �������
	T& operator()(int indexRow, int indexCol)
	{
		if (indexRow >= 0 && indexRow<rows&&indexCol >= 0 && indexCol<cols)
			return ptr[indexRow][indexCol];
		else
		{
			cout << "You are wrong! Index is out of bounds! By, by!!!";
			exit(1);
		}
	}
	//����� �������
	void ShowMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				cout << ptr[i][j] << "\t";
			cout << endl;
		}
		cout << endl;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix<int> A(3, 3);
	A.ShowMatrix();
	cout << "Changing element [1][2]:" << A(0, 1) << endl;
	A(0, 1) = 111;
	A.ShowMatrix();
	Matrix<int> B(A);
	B.ShowMatrix();
	Matrix<int> C;
	C = B;
	C.ShowMatrix();
	Matrix<char> D(6, 4);
	D.ShowMatrix();
	system("pause");
	return 0;
}



