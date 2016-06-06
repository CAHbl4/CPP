// MoveConstructor_MoveOperator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	{
		String s1;
		cout << s1;
		String s2("12345!");
		cout << s2;
		String s3 = s2;
		cout << s3;
		s1 = s3;
		cout << s1;
		cout << "--------------------------------------\n";
		String s4 = String("Hello");
		cout << s4;
		String s5;
		s5 = String("Hello world");
		cout << s5;
		s3 = s1 + s5;
		cout << s3;
	}
	system("pause");
	return 0;
}

