#pragma once
#include "AirCraft.h"

class Bomber :
	public AirCraft {
public:

	Bomber(std::string mark, std::string model, int maxSpeed, int maxHeight)
		: AirCraft(mark, model, maxSpeed, maxHeight) {}


	int Cost() const override {
		return AirCraft::Cost() * 2;
	}
};
