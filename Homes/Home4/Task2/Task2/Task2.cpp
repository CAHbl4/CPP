// Task2.cpp : Defines the entry point for the console application.
//

/*Задание: Создайте шаблонный класс матрица. Необходимо реализовать динамическое выделение памяти, 
очистку памяти, заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, 
арифметические операции с помощью перегруженных операторов (+,-, *, /), поиск максимального и минимального элемента.
*/

#include "stdafx.h"
#include "Matrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Matrix<int> A(3, 3);
	A.FillRand();
	A.Show();

	Matrix<int> B(3, 3);
	B.FillRand();
	B.Show();

	Matrix<int> C;

	C = A + B;
	C.Show();

	C = A - B;
	C.Show();

	C = A * B;
	C.Show();

	A.FindMin();

	B.FindMax();

	system("pause");
	return 0;
}

