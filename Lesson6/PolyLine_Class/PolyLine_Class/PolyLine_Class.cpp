// PolyLine_Class.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Point.h"
#include "PolyLine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//Point A(1, 1);
	//A.Show();
	//Point B = A;
	//B.Show();
	//Point C(3, 3);
	//C.Show();
	//B.CopyData(C);
	//B.Show();

	PolyLine p1(3);
	p1.SetData();
	p1.Show();

	PolyLine p2 = p1;
	p2.Show();

	p2.Add(3);
	p2.Show();

	system("pause");
	return 0;
}

