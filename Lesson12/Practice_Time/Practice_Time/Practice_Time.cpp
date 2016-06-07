// Practice_Time2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Time2.h"


int _tmain(int argc, _TCHAR* argv[]) {
	Time2 t1(14, 61, 0);
	Time2 t5(-1, 12, 2);
	Time2 t6(1, 12, 2);
	cout << "t5 " << t5;
	cout << "t6 " << t6;
	cout << "t5 - t6 " << t5 - t6;
	cout << "t1 " << t1;
	t1++;
	cout << "t1 " << t1;
	++t1;
	cout << "t1 " << t1;

	Time2 t2 = t1;
	cout << "t2 " << t2;
	--t2;
	cout << "t2 " << t2;
	t2--;
	cout << "t2 " << t2;

	cout << "t2 - t1 " << t2 - t1;
	cout << "t1 + t2 " << t1 + t2;

	Time2 t3(t2);

	t2 == t3 ? cout << "t2 == t3\n" : cout << "t2 != t3\n";
	t2 == t1 ? cout << "t2 == t1\n" : cout << "t2 != t1\n";

	cout << int(t3) << endl;
	cout << "t3 " << t3;

	system("pause");
	return 0;
}
