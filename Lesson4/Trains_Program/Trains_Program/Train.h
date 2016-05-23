#pragma once
class Train
{
	int trainNumber;
	char* name;
	int wagonsCount;
	int* wagonPassengers;
public:
	Train();
	Train(int trainNumber, const char *name, int wagonsCount);

	void SetTrainNumber(int trainNumber);
	void SetName(const char* name);
	void SetWagonsCount(int wagonCount);
	void SetWagonPassengers();

	int GetTrainNumber();
	const char* GetName();
	int GetWagonsCount();
	int GetWagonPassengers(int number);
	int GetPassengersCount();

	int GetMaxPassengers();
	int GetMinPassengers();

	void Show();

	~Train();
};

Train* GetMaxTrain(Train* train, int count);
Train* GetMinTrain(Train* train, int count);