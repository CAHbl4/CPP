// Memory_Report.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <crtdbg.h> // подключаем библиотеку
#define _CRTDBG_MAP_ALLOC // активируем режим контроля за памятью

#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // 	настраиваем контроль утечки памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE); // настраиваем режим	вывода
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT); // настраиваем куда	нужно выводить
	
	int *p1 = new int[4];
	//delete[] p1;

	int *p2 = new int[8];
	//delete[] p2;

	_CrtDumpMemoryLeaks(); // делаем проверку на факт утечки памяти


	

	system("pause");
	return 0;
}

