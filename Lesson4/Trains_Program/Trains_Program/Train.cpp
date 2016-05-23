#include "stdafx.h"
#include "Train.h"


Train::Train()
{
	int tmp;
	char str[50];

	cout << "Введите номер поезда: ";
	cin >> tmp;
	SetTrainNumber(tmp);

	cout << "Введите название поезда: ";
	cin >> str;
	SetName(str);

	cout << "Введите количество вагонов: ";
	cin >> tmp;
	SetWagonsCount(tmp);

	wagonPassengers = nullptr;
	SetWagonPassengers();
}

Train::Train(int trainNumber, const char *name, int wagonsCount){
	SetTrainNumber(trainNumber);
	SetName(name);
	SetWagonsCount(wagonsCount);
	wagonPassengers = nullptr;
	SetWagonPassengers();
}

void Train::SetTrainNumber(int trainNumber){
	this->trainNumber = trainNumber;
}

void Train::SetName(const char* name){
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Train::SetWagonsCount(int wagonsCount){
	this->wagonsCount = wagonsCount;
}

void Train::SetWagonPassengers(){
	if (wagonPassengers)
		delete[] wagonPassengers;

	wagonPassengers = new int[wagonsCount];

	for (int i = 0; i < wagonsCount; ++i)
	{
		cout << "Введите количество пассажиров в " << i + 1 << " вагоне: ";
		cin >> wagonPassengers[i];
	}
}

int Train::GetTrainNumber(){
	return trainNumber;
}

const char* Train::GetName(){
	return name;
}

int Train::GetWagonsCount(){
	return wagonsCount;
}

int Train::GetWagonPassengers(int number) {
	return wagonPassengers[number];
}

int Train::GetPassengersCount() {
	int count = 0;
	for (int i = 0; i < wagonsCount; ++i) {
		count += wagonPassengers[i];
	}
	return count;
}

int Train::GetMaxPassengers(){
	int max = 0;
	for (int i = 1; i < wagonsCount; ++i) {
		if (wagonPassengers[i] > wagonPassengers[max]){
			max = i;
		}
	}
	return max;
}

int Train::GetMinPassengers(){
	int min = 0;
	for (int i = 1; i < wagonsCount; ++i) {
		if (wagonPassengers[i] < wagonPassengers[min]){
			min = i;
		}
	}
	return min;
}


void Train::Show() {
	cout << "Номер поезда: " << trainNumber << endl;
	cout << "Название поезда: " << name << endl;
	cout << "Количество вагонов: " << wagonsCount << endl;
	cout << "Количество пассажиров в поезде: " << GetPassengersCount() << endl;
	cout << "Наибольшее количество пассажиров в вагоне: " << GetMaxPassengers() + 1 << endl;
	cout << "Наименьшее количество пассажиров в вагоне: " << GetMinPassengers() + 1 << endl;
}

Train::~Train()
{
	if (name)
		delete[] name;
	if (wagonPassengers)
		delete[] wagonPassengers;
}

 Train* GetMaxTrain(Train* train, int count){
	 Train* max = train++;
	 int maxCount = max->GetPassengersCount();
	 for (int i = 1; i < count; ++i) {
		 if (train->GetPassengersCount() > maxCount){
			 max = train;
			 maxCount = max->GetPassengersCount();
		 }
		 ++train;
	 }
	 return max;
}

 Train* GetMinTrain(Train* train, int count){
	 Train* min = train++;
	 int minCount = min->GetPassengersCount();
	 for (int i = 1; i < count; ++i) {
		 if (train->GetPassengersCount() < minCount){
			 min = train;
			 minCount = min->GetPassengersCount();
		 }
		 ++train;
	 }
	 return min;
 }