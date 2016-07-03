// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AirCraft.h"
#include "Bomber.h"
#include "Fighter.h"


int _tmain(int argc, _TCHAR* argv[])
{
	AirCraft airCraft("Mark 1", "Basic Aircraft", 1200, 15000);
	Bomber bomber("Mark 2", "Bomber 1", 1800, 20000);
	Fighter fighter("Mark 3", "Fighter 1", 2800, 30000);

	airCraft.Info();
	std::cout << std::endl;
	bomber.Info();
	std::cout << std::endl;
	fighter.Info();
	std::cout << std::endl;

	system("pause");
	return 0;
}

