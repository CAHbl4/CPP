// Memory_Report.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <crtdbg.h> // ���������� ����������
#define _CRTDBG_MAP_ALLOC // ���������� ����� �������� �� �������

#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // 	����������� �������� ������ ������
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE); // ����������� �����	������
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT); // ����������� ����	����� ��������
	
	int *p1 = new int[4];
	//delete[] p1;

	int *p2 = new int[8];
	//delete[] p2;

	_CrtDumpMemoryLeaks(); // ������ �������� �� ���� ������ ������


	

	system("pause");
	return 0;
}

