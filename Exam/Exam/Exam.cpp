// Exam.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "TimeTable.h"
#include "Train.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TimeTable trains;

	trains.AddRecord(Record(new Train("Minsk", "Gomel", 945, TrainType::Regional), Time(10, 35), Time(9, 15), std::set<WorkingDays>() = {WorkingDays::Wednesday, WorkingDays:: Saturday}));
	trains.AddRecord(Record(new Train("Gomel", "Moscow", 846, TrainType::International), Time(9, 45), Time(10, 10), std::set<WorkingDays>() = {WorkingDays::Wednesday, WorkingDays:: Saturday}));
	trains.AddRecord(Record(new Train("Moscow", "Gomel", 845, TrainType::International), Time(10, 40), Time(13, 05), std::set<WorkingDays>() = {WorkingDays::Wednesday, WorkingDays:: Saturday}));
	trains.AddRecord(Record(new Train("Gomel", "Minsk", 946, TrainType::Regional), Time(13, 35), Time(14, 20), std::set<WorkingDays>() = {WorkingDays::Wednesday, WorkingDays:: Saturday}));

	trains.Show();

	trains.Save("trains.dat");

	std::cout << "----------------------------------\n";
	TimeTable trains2;

	trains2.Show();
	std::cout << "----------------------------------\n";
	trains2.Load("trains.dat");
	trains2.Show();

	system("pause");
	return 0;
}

