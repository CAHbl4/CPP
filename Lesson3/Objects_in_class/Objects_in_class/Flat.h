#pragma once
#include "Rectangle.h"

class Flat
{
	Rectangle livingroom;
	Rectangle bedroom;
	Rectangle bathroom;
	Rectangle kitchen;
	Rectangle hall;
public:
	Flat();

	void Plan();

	float Square()
	{
		return livingroom.Square() + bedroom.Square() + bathroom.Square() + kitchen.Square() + hall.Square();
	}


	~Flat();
};