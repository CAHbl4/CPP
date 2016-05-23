// Trains_Program.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Train.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Train *trains = nullptr;
	int count = 0;

	cout << "������� ���������� �������: ";
	cin >> count;

	trains = new Train[count];

	cout << "=========================================================================\n";

	for (int i = 0; i < count; ++i) {
		trains[i].Show();
		cout << "=========================================================================\n";
	}

	Train *maxTrain = GetMaxTrain(trains, count);
	cout << "���������� ���������� ���������� � ������ ����� " << maxTrain->GetTrainNumber() << endl;
	cout << "���������� ����������: " << maxTrain->GetPassengersCount() << endl;

	Train *minTrain = GetMinTrain(trains, count);
	cout << "���������� ���������� ���������� � ������ ����� " << minTrain->GetTrainNumber() << endl;
	cout << "���������� ����������: " << minTrain->GetPassengersCount() << endl;


	delete[] trains;
	system("pause");
	return 0;
}

