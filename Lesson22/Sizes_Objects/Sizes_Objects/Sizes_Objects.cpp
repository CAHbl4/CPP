// Sizes_Objects.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Empty{};
class NoEmpty{ int data; };
class EmptyMethod{ void show(); };
class NoEmptyMethod{ int data; void show(); };
class EmptyVirtual{ virtual void show(); };
class NoEmptyVirtual{ int data; virtual void show(); };



int _tmain(int argc, _TCHAR* argv[])
{
	
	cout << "Empty size:" << sizeof(Empty) << endl;
	cout << "EmptyMethod size:" << sizeof(EmptyMethod) << endl;
	cout << "EmptyVirtual size:" << sizeof(EmptyVirtual) << endl;
	cout << "--------------------------------------\n";
	cout << "NoEmpty size:" << sizeof(NoEmpty) << endl;
	cout << "NoEmptyMethod size:" << sizeof(NoEmptyMethod) << endl;
	cout << "NoEmptyVirtual size:" << sizeof(NoEmptyVirtual) << endl;

	system("pause");
	return 0;
}

