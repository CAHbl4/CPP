// Binary_Operators_Overloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Point3D.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Point3D A(1, 1, 1);
	A.Show();
	Point3D B(3, 3, 3);
	B.Show();
	Point3D C;
	C = A + B;
	C.Show();
	A.Show();
	C = C + 1;
	C.Show();
	C = A + 2 + B * C + A;
	C.Show();

	system("pause");
	return 0;
}

