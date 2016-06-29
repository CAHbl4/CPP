// Terminate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//описываем функцию, которая будет вызываться при использовании необработанного исключения
void SoftAbort()
{
	//некоторые действия, которые необходимо выполнить
	cout << "Crash!!!\n";
	system("pause");
	//и только после этого завершаем раьоту программы
	exit(1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	set_terminate(SoftAbort);
	throw;
	return 0;
}

