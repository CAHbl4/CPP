// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include "Man.h"
#include "Novice.h"
#include "Skilled.h"
#include "Veteran.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[]) {
	srand(time(0));
	const int SIZE = 5;
	Man* shooters[5];

	shooters[0] = new Novice("Jon", 25, 5);
	shooters[1] = new Skilled("Jon Smit", 30, 8);
	shooters[2] = new Veteran("V. Putin", 55, 35);
	shooters[3] = new Skilled("Vasili Pupkin", 32, 11);
	shooters[4] = new Novice("Vasya", 21, 3);

	bool result = false;
	int i = 0;
	while (!result && i < SIZE)
		result = shooters[i++]->Shoot();

	if (result)
		std::cout << shooters[i - 1]->GetName() << " hit the target. Good job!\n";
	else
		std::cout << "Nobody hit the target\n";

	system("pause");

	for (int i = 0; i < SIZE; ++i) {
		delete shooters[i];
	}
	return 0;
}
