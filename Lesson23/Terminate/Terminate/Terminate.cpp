// Terminate.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//��������� �������, ������� ����� ���������� ��� ������������� ��������������� ����������
void SoftAbort()
{
	//��������� ��������, ������� ���������� ���������
	cout << "Crash!!!\n";
	system("pause");
	//� ������ ����� ����� ��������� ������ ���������
	exit(1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	set_terminate(SoftAbort);
	throw;
	return 0;
}

