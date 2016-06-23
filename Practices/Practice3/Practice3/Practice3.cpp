// Practice3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Computer.h"
#include "Notebook.h"


int _tmain(int argc, _TCHAR* argv[]) {
	Computer comp1(2500, 4, 4096, 500);
	cout << comp1 << endl << "Cost: " << comp1.Cost() << ", Ready for work: " << (comp1.IsGood() ? "Yes" : "No") << endl;
	Notebook note1(2100, 2, 2048, 320, 30);
	cout << note1 << endl << "Cost: " << note1.Cost() << ", Ready for work: " << (note1.IsGood() ? "Yes" : "No") << endl;

	system("pause");
	return 0;
}
