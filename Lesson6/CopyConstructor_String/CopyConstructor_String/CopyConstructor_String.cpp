// CopyConstructor_String.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "String.h"


int _tmain(int argc, _TCHAR* argv[])
{
	String s1("One, two, three ...");
	s1.Show();

	String s2 = s1;
	s2.Show();
	return 0;
}

