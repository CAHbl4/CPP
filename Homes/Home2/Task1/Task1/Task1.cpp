// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Building.h"


int _tmain(int argc, _TCHAR* argv[]) {
	Building bld1(2);
	bld1.AddResidentToFlat(1, 1);
	bld1.AddResidentToFlat(2, 2);
	bld1.Show();

	bld1.DeleteFlat(1);
	bld1.Show();

	bld1.AddFlat(1);
	bld1.Show();
	cout << "----------------------------------\n";
	Building bld2 = bld1;
	bld2.AddResidentToFlat(2, 3);
	bld2.Show();

	Flat flt1(2);
	bld2.AddFlat(flt1);
	bld2.Show();

	system("pause");
	return 0;
}
