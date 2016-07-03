#pragma once
#include "AirCraft.h"

class Fighter :
	public AirCraft {
public:
	Fighter(std::string mark, std::string model, int maxSpeed, int maxHeight)
		: AirCraft(mark, model, maxSpeed, maxHeight) {}

	int Cost() const override {
		return AirCraft::Cost() * 3;
	}
};
