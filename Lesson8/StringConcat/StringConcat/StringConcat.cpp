// StringConcat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "String.h"


int _tmain(int argc, _TCHAR* argv[])
{
	String s1("1, 2, 3!");
	s1.Show();

	String s2(" One, Two, Three");
	s2.Show();

	String s3;
	s3 = s1 + s2;
	s3.Show();

	system("pause");
	return 0;
}

