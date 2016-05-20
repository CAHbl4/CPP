#include "stdafx.h"
#include "Flat.h"


Flat::Flat()
{
	float length, width; 
	cout << "Input sizes Livingroom: ";
	cin >> length >> width;
	livingroom.SetAll(length, width);
	cout << "Input sizes Bedroom: ";
	cin >> length >> width;
	bedroom.SetAll(length, width);
	cout << "Input sizes Bathroom: ";
	cin >> length >> width;
	bathroom.SetAll(length, width);
	cout << "Input sizes Kitchen: ";
	cin >> length >> width;
	kitchen.SetAll(length, width);
	cout << "Input sizes Hall: ";
	cin >> length >> width;
	hall.SetAll(length, width);
}

void Flat::Plan()
{
	cout << "Plan of Flat:\n";
	cout << "Livingroom: " << livingroom.Square() << endl;
	cout << "Bedroom: " << bedroom.Square() << endl;
	cout << "Bathroom: " << bathroom.Square() << endl;
	cout << "Kitchen: " << kitchen.Square() << endl;
	cout << "Hall: " << hall.Square() << endl;
	cout << "Summary square: " << Square() << endl;
}

Flat::~Flat()
{
}
