// Task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include "Student.h"
#include "Regular.h"
#include "Genius.h"
#include "Smart.h"
#include <iostream>

using namespace std;
 

int _tmain(int argc, _TCHAR* argv[]) {
	srand(time(0));

	const int SIZE = 10;
	Student* students[SIZE];

	students[0] = new Regular("Ivan", "Ivanov", 11);
	students[1] = new Regular("Konstantin", "Petrov", 20);
	students[2] = new Regular("Andrei", "Sidorov", 8);
	students[3] = new Regular("Mihail", "Fedorov", 10);
	students[4] = new Regular("Denis", "Kuznetov", 1);
	students[5] = new Smart("Fedor", "Konuhov", 13);
	students[6] = new Genius("Aleksandr", "L", 0);
	students[7] = new Smart("Vladimir", "P", 11);
	students[8] = new Smart("Vasili", "Chapaev", 20);
	students[9] = new Smart("Vitaliy", "Alibabaev", 1);

	for (int i = 0; i < SIZE; ++i) {
		cout << students[i]->GetName() << " "
			<< students[i]->GetSurname()
			<< " with " << students[i]->GetAttendance() << " attendace"
			<< (students[i]->PassExam() ? " passed " : " failed ") << "exam.\n";
	}

	system("pause");

	for (int i = 0; i < SIZE; ++i) {
		delete students[i]; 
	}
	return 0;
}
